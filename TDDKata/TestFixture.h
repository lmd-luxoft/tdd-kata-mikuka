#pragma once
#include "Calculator.h"

class TestFixture : public ::testing::Test
{
protected:
    Calculator* calc;
    void SetUp() override; /* >- C++ 11 */
    void TearDown() override; /* >- C++ 11 */
};

