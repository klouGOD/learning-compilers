//
// Created by klougod on 30/06/19.
//

#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <list>
#include "./Token.h"

class Lexer
{
  public:
  
    Lexer()
    {
      m_input = "";
      m_line = 0;
      m_column = 1;
      m_position = 0;
    };

    void nextLine(std::string input)
    {
      m_input = input;
      m_line++;
      m_column = 1;
      m_position = 0;
    };

    std::list<Token> allLineTokens();

  private:
    void skipWhiteSpaces();
    Token recognizeIdentifier();
    Token recognizeNumber();
    Token recognizeArithmeticOp();
    Token recognizeComparisonOp();
    Token recognizeOp();
    Token recognizeParentheses();
    Token recognizeBrackets();
    Token nextToken();
    std::string m_input;
    std::list<Token> m_tokens;
    unsigned int m_position;
    unsigned int m_line;
    unsigned int m_column;
};

#endif