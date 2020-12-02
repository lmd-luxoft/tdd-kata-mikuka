#include "pch.h"
#include "Calculator.h"
#include "TestFixture.h"
#include "TextFixtureWithParam.h"
#include <string>


TEST_P(TextFixtureWithParam, AddTest) {
	std::string arg = GetParam().op;
	auto expected = GetParam().expected;

	auto result = calc->Add(arg);
	ASSERT_EQ(expected, result);
}
