#include "pch.h"
#include "Calculator.h"
#include <string>


	TEST(TDDKata, EmptyArgsTest) {
		std::string arg = "";
		auto expected = 0;
		Calculator calc;

		auto result = calc.Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST(TDDKata, OneArgumentTest) {
		std::string arg = "1";
		auto expected = 1;
		Calculator calc;

		auto result = calc.Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST(TDDKata, OneNegativeArgumentTest) {
		std::string arg = "-999";
		auto expected = -1;
		Calculator calc;

		auto result = calc.Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST(TDDKata, SummWithZeroTest) {
		std::string arg = "0,2";
		auto expected = 2;
		Calculator calc;

		auto result = calc.Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST(TDDKata, SummTest) {
		std::string arg = "1,20";
		auto expected = 21;
		Calculator calc;

		auto result = calc.Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST(TDDKata, FirstNegativeArgsTest) {
		std::string arg = "-1,1";
		auto expected = -1;
		Calculator calc;

		auto result = calc.Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST(TDDKata, SecondNegativeArgsTest) {
		std::string arg = "1,-1";
		auto expected = -1;
		Calculator calc;

		auto result = calc.Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST(TDDKata, AllNegativeArgsTest) {
		std::string arg = "-2,-1";
		auto expected = -1;
		Calculator calc;

		auto result = calc.Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST(TDDKata, FirstInvalidArgsTest) {
		std::string arg = "a,3";
		auto expected = -2;
		Calculator calc;

		auto result = calc.Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST(TDDKata, SecondInvalidArgsTest) {
		std::string arg = "3,a";
		auto expected = -2;
		Calculator calc;

		auto result = calc.Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST(TDDKata, SymbolArgsTest) {
		std::string arg = "a";
		auto expected = -2;
		Calculator calc;

		auto result = calc.Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST(TDDKata, AllSymbolArgsTest) {
		std::string arg = "a,b";
		auto expected = -2;
		Calculator calc;

		auto result = calc.Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST(TDDKata, SeparatorTest) {
		std::string arg = "0.1";
		auto expected = -3;
		Calculator calc;

		auto result = calc.Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST(TDDKata, VariableArgsTest) {
		std::string arg = "0,1,2";
		auto expected = 3;
		Calculator calc;

		auto result = calc.Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST(TDDKata, Variable2ArgsTest) {
		std::string arg = "0,1,2,10,100";
		auto expected = 113;
		Calculator calc;

		auto result = calc.Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST(TDDKata, NexLineTwoArgsTest) {
		std::string arg = "1\n2";
		auto expected = 3;
		Calculator calc;

		auto result = calc.Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST(TDDKata, NexLineArgsTest) {
		std::string arg = "1\n2,3";
		auto expected = 6;
		Calculator calc;

		auto result = calc.Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST(TDDKata, IncorrectNexLineArgsTest) {
		std::string arg = "1,\n";
		auto expected = -4;
		Calculator calc;

		auto result = calc.Add(arg);
		ASSERT_EQ(expected, result);
	}
	