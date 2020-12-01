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
	void ParseArgs(const std::string &);
	bool IsPositive();
	ErrorCode_e CheckArguments(const std::string&);

	ErrorCode_e error_code;
	std::vector<int> numeric;
	const std::string tokens[2] = {",", "\n"};
};

