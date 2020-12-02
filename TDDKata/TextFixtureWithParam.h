#pragma once
#include "TestFixture.h"

struct Param {
    std::string op;
    int expected;

    Param(std::string op, int expected)
     :op(op)
     ,expected(expected) {}
};


class TextFixtureWithParam : public TestFixture, public ::testing::WithParamInterface<Param>
{
};

