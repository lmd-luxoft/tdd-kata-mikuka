#pragma once
#include <string>
#include <vector>


/// <summary>
/// Class Under test
/// </summary>
class Calculator
{
public:
	enum ErrorCode_e {
		NO_ERROR = 0,
		NEGATIVE_ARGS = -1,
		SYMBOL_ARGS = -2,
		TOKEN_ERROR = -3,
		ARGS_EXCEEDED = -4,
	};

	Calculator();
	/// <summary>
	/// Sum of elements expression
	/// </summary>
	/// <param name="expression">Input expression</param>
	/// <returns>Value of sum expression of expression</returns>
	int Add(std::string expression);
	/// <summary>
	/// Sum of elements expression
	/// </summary>
	/// <param name="expression">Input expression</param>
	/// <returns>Value of sum expression of expression</returns>
	int Add(char* expression);

private:
	bool IsPositive();
	std::string GetCustomToken(const std::string &);
	ErrorCode_e CheckTokens(const std::string &);
	Calculator::ErrorCode_e GetNumeric();

	ErrorCode_e error_code;
	std::vector<int> numeric;
	std::map<size_t, std::string> args;
	std::vector<std::string> tokens;
};

