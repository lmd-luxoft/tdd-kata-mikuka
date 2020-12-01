#include "pch.h"
#include "Calculator.h"
#include <exception>
#include <stdexcept>


Calculator::Calculator()
 :error_code(NO_ERROR) {

}

int Calculator::Add(std::string expression) {
    int result = error_code;
    std::vector<int> args = GetArgs(expression);

    if (error_code == NO_ERROR) {
        for (auto &digit : args) {
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

        uint32_t token_pos = str.find(token);
        if (token_pos != std::string::npos) {
            std::string second = str.substr(token_pos + 1);
            digit.push_back(std::stoi(second));
        }

        digit.push_back(std::stoi(str));
    }
    catch (const std::invalid_argument& exc) {
        error_code = ARGS_EXCEEDED;
    }

    return digit;
}


bool CalculatorIsDigit(std::string args) {
    return true;
}