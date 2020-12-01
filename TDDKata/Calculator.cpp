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
        error_code = CheckArguments(expression);
        if (error_code == NO_ERROR) {
            ParseArgs(expression);

            if (error_code == NO_ERROR) {
                if (IsPositive()) {
                    for (auto& n : numeric)
                        result += n;
                } else {
                    result = NEGATIVE_ARGS;
                }
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


void Calculator::ParseArgs(const std::string& str) {
    enum {MAX_SEPARATORS = 1};

    try {
        size_t token_pos = 0;
        std::string second = str;

        do {
            numeric.push_back(std::stoi(second));
            token_pos = std::min(second.find(tokens[0]), second.find(tokens[1]));
            second = second.substr(++token_pos);
        } while (token_pos != 0);
    }

    catch (const std::invalid_argument& exc) {
        error_code = ARGS_EXCEEDED;
    }
}


bool Calculator::IsPositive() {
    bool result = true;

    for (auto& n : numeric) {
        if (n < 0) {
            result = false;
            break;
        }
    }

    return result;
}


Calculator::ErrorCode_e Calculator::CheckArguments(const std::string& str) {
    ErrorCode_e result = NO_ERROR;

    bool prev_token = false;
    for (auto &c : str) {
        if (c == '-') {
            continue;
        } else {
            if (c == *tokens[0].data() || c == *tokens[1].data()) {
                if (prev_token == true) {
                    result = ARGS_EXCEEDED;
                    break;
                }
                prev_token = true;
            } else {
                prev_token = false;

                if (std::ispunct(c)) {
                    result = TOKEN_ERROR;
                    break;
                }
                else if (std::isdigit(c) == false) {
                    result = SYMBOL_ARGS;
                    break;
                }
            }
        }
    }

    return result;
}