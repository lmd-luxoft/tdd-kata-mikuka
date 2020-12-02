#include "pch.h"
#include "TestFixture.h"


void TestFixture::SetUp() {
    calc = new Calculator();
}


void TestFixture::TearDown() {
    delete calc;
}