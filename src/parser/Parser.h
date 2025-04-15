#pragma once
#include <iostream>


class Parser
{
    std::string input;
    size_t pos;
public:
    explicit Parser(const std::string& input);
    bool parse();
private:
    void error(const std::string& msg);
    char peek();
    char get();
    void skipWhitespace();
    bool match(char expected);
    void expect(char expected);
    void program();
    void block();
    void operatorList();
    void tail();
    void operator_();
    void expression();
    void expressionPrime();
    void term();
    void termPrime();
    void factor();
    void identifier();
};