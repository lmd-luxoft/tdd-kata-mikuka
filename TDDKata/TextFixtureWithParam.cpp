#include "pch.h"
#include "TextFixtureWithParam.h"
#include <vector>


/* Method 1 */
//INSTANTIATE_TEST_CASE_P(ParametrizedTest, TextFixtureWithParam,
//    ::testing::Values(Param("2,3", 5), Param("4", 4)));


/* Method 2 */
std::vector<std::tuple<std::string, int>> CreateParametersSet() {
    std::vector<std::tuple<std::string, int>> param;

    

        //std::get<0>(GetParam())
    param.push_back(std::make_tuple("1", 1));
    param.push_back(std::make_tuple("-999", -1));
    param.push_back(std::make_tuple("0,2", 2));
    param.push_back(std::make_tuple("1,20", 21));
    param.push_back(std::make_tuple("-1,1", -1));
    param.push_back(std::make_tuple("1,-1", -1));
    param.push_back(std::make_tuple("-2,-1", -1));
    param.push_back(std::make_tuple("a,3", -2));
    param.push_back(std::make_tuple("3,a", -2));
    param.push_back(std::make_tuple("a", -2));
    param.push_back(std::make_tuple("a,b", -2));
    param.push_back(std::make_tuple("0.1", -3));
    param.push_back(std::make_tuple("0,1,2", 3));
    param.push_back(std::make_tuple("0,1,2,10,100", 113));
    param.push_back(std::make_tuple("1\n2", 3));
    param.push_back(std::make_tuple("1\n2,3", 6));
    param.push_back(std::make_tuple("1,\n", -4));
    param.push_back(std::make_tuple("//;\n2;3", 5));
    param.push_back(std::make_tuple("//$\n2$3", 5));
    param.push_back(std::make_tuple("//;\n2,3,5", 10));
    param.push_back(std::make_tuple("//;\n2\n3\n5", 10));
    param.push_back(std::make_tuple("//***\n1***2***3", 6));
    param.push_back(std::make_tuple("//@#$\n1@#$2@#$3", 6));
    param.push_back(std::make_tuple("2,3,4,5", 14));

    return param;
}


INSTANTIATE_TEST_CASE_P(ParametrizedTest, TextFixtureWithParam,
    ::testing::ValuesIn(CreateParametersSet()));
