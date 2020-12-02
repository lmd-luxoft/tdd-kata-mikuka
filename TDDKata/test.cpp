#include "pch.h"
#include "Calculator.h"
#include "TestFixture.h"
#include <string>


	TEST_F(TestFixture, EmptyArgsTest) {
		std::string arg = "";
		auto expected = 0;

		auto result = calc->Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST_F(TestFixture, OneArgumentTest) {
		std::string arg = "1";
		auto expected = 1;

		auto result = calc->Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST_F(TestFixture, OneNegativeArgumentTest) {
		std::string arg = "-999";
		auto expected = -1;

		auto result = calc->Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST_F(TestFixture, SummWithZeroTest) {
		std::string arg = "0,2";
		auto expected = 2;

		auto result = calc->Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST_F(TestFixture, SummTest) {
		std::string arg = "1,20";
		auto expected = 21;

		auto result = calc->Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST_F(TestFixture, FirstNegativeArgsTest) {
		std::string arg = "-1,1";
		auto expected = -1;

		auto result = calc->Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST_F(TestFixture, SecondNegativeArgsTest) {
		std::string arg = "1,-1";
		auto expected = -1;

		auto result = calc->Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST_F(TestFixture, AllNegativeArgsTest) {
		std::string arg = "-2,-1";
		auto expected = -1;

		auto result = calc->Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST_F(TestFixture, FirstInvalidArgsTest) {
		std::string arg = "a,3";
		auto expected = -2;

		auto result = calc->Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST_F(TestFixture, SecondInvalidArgsTest) {
		std::string arg = "3,a";
		auto expected = -2;

		auto result = calc->Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST_F(TestFixture, SymbolArgsTest) {
		std::string arg = "a";
		auto expected = -2;

		auto result = calc->Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST_F(TestFixture, AllSymbolArgsTest) {
		std::string arg = "a,b";
		auto expected = -2;

		auto result = calc->Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST_F(TestFixture, SeparatorTest) {
		std::string arg = "0.1";
		auto expected = -3;

		auto result = calc->Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST_F(TestFixture, VariableArgsTest) {
		std::string arg = "0,1,2";
		auto expected = 3;

		auto result = calc->Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST_F(TestFixture, Variable2ArgsTest) {
		std::string arg = "0,1,2,10,100";
		auto expected = 113;

		auto result = calc->Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST_F(TestFixture, NexLineTwoArgsTest) {
		std::string arg = "1\n2";
		auto expected = 3;

		auto result = calc->Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST_F(TestFixture, NexLineArgsTest) {
		std::string arg = "1\n2,3";
		auto expected = 6;

		auto result = calc->Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST_F(TestFixture, IncorrectNexLineArgsTest) {
		std::string arg = "1,\n";
		auto expected = -4;

		auto result = calc->Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST_F(TestFixture, Token0Test) {
		std::string arg = "//;\n2;3";
		auto expected = 5;

		auto result = calc->Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST_F(TestFixture, Token1Test) {
		std::string arg = "//$\n2$3";
		auto expected = 5;

		auto result = calc->Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST_F(TestFixture, Token2Test) {
		std::string arg = "//;\n2,3,5";
		auto expected = 10;

		auto result = calc->Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST_F(TestFixture, Token3Test) {
		std::string arg = "//;\n2\n3\n5";
		auto expected = 10;

		auto result = calc->Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST_F(TestFixture, SeveralDelimitersTest) {
		std::string arg = "//***\n1***2***3";
		auto expected = 6;

		auto result = calc->Add(arg);
		ASSERT_EQ(expected, result);
	}


	TEST_F(TestFixture, SeveralDifferentDelimitersTest) {
		std::string arg = "//@#$\n1@#$2@#$3";
		auto expected = 6;

		auto result = calc->Add(arg);
		ASSERT_EQ(expected, result);
	}

	
	TEST_F(TestFixture, Sample) {
		/* Arrange */
		std::string arg = "2,3,4,5";
		auto expected = 14;
		/* Act */
		auto actual = calc->Add(arg);
		/* Assert */
		ASSERT_EQ(expected, actual);
	}