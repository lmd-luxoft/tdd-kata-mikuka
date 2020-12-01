#include "pch.h"
#include "Calculator.h"
#include <exception>
#include <stdexcept>


Calculator::Calculator()
 :error_code(NO_ERROR) {

}

int Calculator::Add(std::string expression) {
    int result = 0;

    if (expression.length()) {
        std::vector<int> args = GetArgs(expression);
        result = error_code;

        if (error_code == NO_ERROR) {
            for (auto& digit : args) {
                if (digit < 0) {
                    result = error_code = NEGATIVE_ARGS;
                    break;
                }
            }

            if (error_code == NO_ERROR) {
                result = args[0];
                if (args.size() > 1)
                    result = args[0] + args[1];
            }
        }
    }

    return result;
}


int Calculator::Add(char* expression) {
    throw 0;
}


std::vector<int> Calculator::GetArgs(const std::string& str) {
    enum { MAX_SEPARATORS = 1 };
    const std::string token = ",";
    std::vector<int> digit;

    try {
        digit.push_back(std::stoi(str));

        uint32_t token_pos = str.find(token);
        if (token_pos != UINT32_MAX) {
            std::string second = str.substr(++token_pos);
            digit.push_back(std::stoi(second));

            if (second.find(token) != std::string::npos)
                error_code = ARGS_EXCEEDED;
        } else {
            for (auto &c : str) {
                if (std::ispunct(c)) {
                    if (c == '-')
                        break;
                    error_code = TOKEN_ERROR;
                    break;
                }

                if (std::isalpha(c)) {
                    error_code = SYMBOL_ARGS;
                    break;
                }
            }
        }
    }
    catch (const std::invalid_argument& exc) {
        error_code = ARGS_EXCEEDED;

        for (auto& c : str) {
            if (std::isalpha(c)) {
                error_code = SYMBOL_ARGS;
                break;
            }
        }
    }

    return digit;
}


bool CalculatorIsDigit(std::string args) {
    return true;
}