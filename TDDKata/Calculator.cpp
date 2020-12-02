#include "pch.h"
#include "Calculator.h"
#include <exception>
#include <stdexcept>
#include <algorithm>


Calculator::Calculator()
    :error_code(NO_ERROR) {
    tokens.push_back(",");
    tokens.push_back("\n");
}


int Calculator::Add(std::string expression) {
    int result = 0;

    if (expression.length()) {
        std::string custom_token = GetCustomToken(expression);
        /* Удаление из исходной строки описания разделителя */
        if (custom_token.length())
            expression = expression.substr(custom_token.length());

        error_code = CheckTokens(expression);
        if (error_code == NO_ERROR)
            error_code = GetNumeric();
 
        if (error_code == NO_ERROR) {
            if (IsPositive()) {
                for (auto &n : numeric)
                    result += n;
            } else {
                result = NEGATIVE_ARGS;
            }
        } else {
            result = error_code;
        }
    }

    return result;
}


int Calculator::Add(char* expression) {
    throw 0;
}


bool Calculator::IsPositive() {
    bool result = true;

    for (auto &n : numeric) {
        if (n < 0) {
            result = false;
            break;
        }
    }

    return result;
}


std::string Calculator::GetCustomToken(const std::string& str) {
    const std::string begin_marker = { "//" };
    const std::string end_marker = { "\n" };
    std::string result;

    size_t begin_marker_pos = str.find(begin_marker);
    if (begin_marker_pos != std::string::npos) {
        result = str.substr(begin_marker_pos);
        size_t end_marker_pos = str.find(end_marker);
        if (end_marker_pos && end_marker_pos != std::string::npos) {
            result = result.substr(begin_marker.length(), end_marker_pos - begin_marker.length());
            tokens.push_back(result);
            result = begin_marker + result + end_marker;
        }
    }

    return result;
}


Calculator::ErrorCode_e Calculator::GetNumeric() {
    ErrorCode_e result = NO_ERROR;
    try {
        for (auto& argument : args) {
            if (std::isalpha(*argument.second.data())) {
                result = SYMBOL_ARGS;
                break;
            }

            numeric.push_back(std::stoi(argument.second));
        }
    }

    catch (const std::invalid_argument&) {
        result = ARGS_EXCEEDED;
    }

    return result;
}


Calculator::ErrorCode_e Calculator::CheckTokens(const std::string& str) {
    enum {MIN_ARGUMENTS = 1};
    ErrorCode_e result = NO_ERROR;
    std::string second = str;
    size_t offset = 0;

    args.insert(std::pair<size_t, std::string>(offset, second));

    bool exit_flag;
    do {
        exit_flag = false;

        for (auto &token : tokens) {
            size_t pos = str.find(token, offset);
            if (pos && pos != std::string::npos && pos != UINT32_MAX) {
                pos += token.length();
                args.insert(std::pair<size_t, std::string>(pos, str.substr(pos)));
                exit_flag = true;
            }
        }

        if (args.size()) {
            offset = args.rbegin()->first;
            second = args.rbegin()->second;
        }
    } while (exit_flag);

    /* Проверка на наличие неизвестных разделителей */
    if (args.size() == MIN_ARGUMENTS) {
        for (auto& ch : second) {
            if (std::ispunct(ch) && ch != '-') {
                result = TOKEN_ERROR;
                break;
            }
        }
    }

    return result;
}