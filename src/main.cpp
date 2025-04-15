#include <gtest/gtest.h>
#include <iostream>
#include "parser/Parser.h"


int main(int argc, char **argv)
{
    // std::string input;
    //
    // while (true)
    // {
    //     std::cout << "Input string: " << std::endl;
    //     std::getline(std::cin, input);
    //     Parser parser(input);
    //     parser.parse();
    // }
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}