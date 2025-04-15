#include <gtest/gtest.h>

#include "../parser/Parser.h"


TEST(SyntaxParserTest, Simple1)
{
    const std::string input = "{ x =      a }";
    Parser parser(input);
    EXPECT_TRUE(parser.parse());
}

TEST(SyntaxParserTest, Simple2)
{
    const std::string input = "{ x = a; y = b }";
    Parser parser(input);
    EXPECT_TRUE(parser.parse());
}

TEST(SyntaxParserTest, Simple3)
{
    const std::string input = "{ x = true; y = false }";
    Parser parser(input);
    EXPECT_TRUE(parser.parse());
}

TEST(SyntaxParserTest, Simple4)
{
    const std::string input = "{ z = 42 }";
    Parser parser(input);
    EXPECT_THROW({parser.parse();}, std::runtime_error);
}

TEST(SyntaxParserTest, Simple5)
{
    const std::string input = "{ x = true; y = false }";
    Parser parser(input);
    EXPECT_TRUE(parser.parse());
}

TEST(SyntaxParserTest, Simple6)
{
    const std::string input = "{ x = ~true }";
    Parser parser(input);
    EXPECT_TRUE(parser.parse());
}

TEST(SyntaxParserTest, Complex1)
{
    const std::string input = "{ x = { y = true }";
    Parser parser(input);
    EXPECT_THROW({parser.parse();}, std::runtime_error);
}

TEST(SyntaxParserTest, Complex2)
{
    const std::string input = "{ a = true; b = ~false ! x; c = x & y ! z; { d = true } }";
    Parser parser(input);
    EXPECT_TRUE(parser.parse());
}

TEST(SyntaxParserTest, Complex3)
{
    const std::string input = "{ x = a & b ! c; { y = ~false } }";
    Parser parser(input);
    EXPECT_TRUE(parser.parse());
}