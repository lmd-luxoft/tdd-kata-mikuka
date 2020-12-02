#include "pch.h"
#include "Calculator.h"
#include "TestFixture.h"
#include "TextFixtureWithParam.h"
#include <string>


TEST_P(TextFixtureWithParam, AddTest) {
	std::string arg = std::get<0>(GetParam());
	auto expected = std::get<1>(GetParam());

	auto result = calc->Add(arg);
	ASSERT_EQ(expected, result);
}
