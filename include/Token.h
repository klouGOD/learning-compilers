//
// Created by klougod on 29/06/19.
//

#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include "./TokenType.h"

class Token
{

  public:
  
    Token(TokenType::Type type, std::string lexeme, int line, int column);

    Token(TokenType::Type type) { m_type = type; };

    void setToken(TokenType::Type type, std::string lexeme, int line, int column);

    TokenType::Type type() { return m_type; };

    std::string lexeme() { return m_lexeme; };

    unsigned int column() {return m_column; };

    unsigned int line() {return m_line; };

    std::string stringType();

  private:
    TokenType::Type m_type;
    std::string m_lexeme;
    unsigned int m_line;
    unsigned int m_column;
};

#endif