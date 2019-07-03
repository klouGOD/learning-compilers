//
// Created by klougod on 29/06/19.
//

#include <string>
#include "Token.h"
#include "TokenType.h"

Token::Token(TokenType::Type type, std::string lexeme, int line, int column)
{
  setToken(type, lexeme, line, column);
};

std::string Token::stringType()
{
  return TokenType::stringifyTokenType(this->type());
}

void Token::setToken(TokenType::Type type, std::string lexeme, int line, int column)
{
  m_type = type;
  m_lexeme = lexeme;
  m_line = line;
  m_column = column;
};