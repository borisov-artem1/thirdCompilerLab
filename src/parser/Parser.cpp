#include "Parser.h"


void Parser::error(const std::string& msg)
{
    throw std::runtime_error("Error: " + msg + " on position " + std::to_string(pos) + " (symbol '" + peek() + "')");
    //std::cerr << "Error: " << msg << " on position " << pos << " (symbol '" << peek() << "')" << std::endl;
    //exit(1);
}

char Parser::peek()
{
    return pos < input.size() ? input[pos] : '\0';
}

char Parser::get()
{
    return pos < input.size() ? input[pos++] : '\0';
}

void Parser::skipWhitespace()
{
    while (isspace(peek())) pos++;
}

bool Parser::match(const char expected)
{
    skipWhitespace();
    if (peek() == expected)
    {
        pos++;
        return true;
    }
    return false;
}

void Parser::expect(char expected)
{
    skipWhitespace();
    if (get() != expected) error(std::string("expected '") + expected + "'");
}

void Parser::program()
{
    skipWhitespace();
    block();
}

void Parser::block()
{
    skipWhitespace();
    if (!match('{')) error(std::string("expected '{'"));
    operatorList();
    skipWhitespace();
    if (!match('}')) error(std::string("expected '}'"));
}

void Parser::operatorList()
{
    skipWhitespace();
    operator_();
    tail();
}

void Parser::tail()
{
    skipWhitespace();
    if (match(';'))
    {
        operator_();
        tail();
    }
}


void Parser::operator_()
{
    skipWhitespace();
    if (peek() == '{')
    {
        block();
    } else if (std::isalpha(peek()))
    {
        identifier();
        skipWhitespace();
        if (!match('=')) error(std::string("expected symbol '=' after identifier"));
        expression();
    } else
    {
        error(std::string("expected identifier or block"));
    }
}

void Parser::expression()
{
    term();
    expressionPrime();
}

void Parser::expressionPrime()
{
    skipWhitespace();
    if (match('!'))
    {
        term();
        expressionPrime();
    }
}

void Parser::term()
{
    factor();
    termPrime();
}

void Parser::termPrime()
{
    skipWhitespace();
    if (match('&'))
    {
        factor();
        termPrime();
    }
}

void Parser::factor()
{
    skipWhitespace();
    if (match('~'))
    {
        factor();
    } else if (input.substr(pos, 4) == "true")
    {
        pos += 4;
    } else if (input.substr(pos, 5) == "false") {
        pos += 5;
    } else if (std::isalpha(peek()))
    {
        identifier();
    } else
    {
        error(std::string("wrong factor"));
    }
}

void Parser::identifier()
{
    skipWhitespace();
    if (!std::isalpha(peek())) error(std::string("expected identifier"));

    while (std::isalnum(peek())) pos++;
}

bool Parser::parse()
{
    skipWhitespace();
    program();
    skipWhitespace();
    if (pos != input.length()) error(std::string("unexpected end of input"));
    std::cout << "The parsing was completed successfully" << std::endl;
    return true;
}

Parser::Parser(const std::string& input) : input(input), pos(0) {}









