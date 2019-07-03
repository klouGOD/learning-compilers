//
// Created by klougod on 30/06/19.
//

#include <string>
#include <stdexcept>
#include <iostream>
#include "CharUtils.h"
#include "Token.h"
#include "TokenType.h"
#include "Lexer.h"

Token Lexer::recognizeIdentifier()
{
  std::string identifier = "";
  unsigned int position = m_position;
  unsigned int line = m_line;
  unsigned int column = m_column;
  char character = ' ';

  while (position < m_input.length())
  {
    character = m_input.at(position);
    identifier += character;
    if (!CharUtils::isIdentifier(character))
    {
      break;
    }

    position++;
  }

  m_position += identifier.length();
  m_column += identifier.length();

  return Token(TokenType::Type::IDENTIFIER, identifier, line, column);
};

Token Lexer::recognizeNumber()
{
  std::string number = "";
  unsigned int position = m_position;
  unsigned int column = m_column;
  char character = ' ';

  while (position < m_input.length())
  {
    character = m_input.at(position);
    if (!CharUtils::isDigit(character))
    {
      break;
    }

    number += character;
    position++;
  }

  m_position += number.length();
  m_column += number.length();

  return Token(TokenType::Type::NUMBER, number, m_line, column);
};

Token Lexer::recognizeParentheses()
{
  char character = m_input.at(m_position);
  unsigned int column = m_column;
  std::string parenthesis(1, character);
  TokenType::Type type = TokenType::Type::NULLTOKEN;

  if (character == '(')
  {
    type = TokenType::Type::LEFTPARENTHESIS;
  }
  else if (character == ')')
  {
    type = TokenType::Type::RIGHTPARENTHESIS;
  }

  m_position += 1;
  m_column += 1;

  return Token(type, parenthesis, m_line, column);
};

Token Lexer::recognizeBrackets()
{
  char character = m_input.at(m_position);
  unsigned int column = m_column;
  std::string bracket(1, character);
  TokenType::Type type = TokenType::Type::NULLTOKEN;

  if (character == '{')
  {
    type = TokenType::Type::LEFTBRACKET;
  }
  else if (character == '}')
  {
    type = TokenType::Type::RIGHTBRACKET;
  }

  m_position += 1;
  m_column += 1;

  return Token(type, bracket, m_line, column);
};

Token Lexer::recognizeOp()
{
  char character = m_input.at(m_position);

  if (CharUtils::isArithmeticOperator(character))
  {
    std::cout << "arithmetic" << std::endl;
    return this->recognizeArithmeticOp();
  }
  else if (CharUtils::isComparisonOperator(character))
  {
    std::cout << "comparison" << std::endl;
    return this->recognizeComparisonOp();
  }
  std::cout << "invalid" << std::endl;
  return Token(TokenType::Type::NULLTOKEN);
}

Token Lexer::recognizeArithmeticOp()
{
  char character = m_input.at(m_position);
  unsigned int column = m_column;
  std::string op(1, character);
  TokenType::Type type = TokenType::Type::NULLTOKEN;
  switch (character)
  {
  case '+':
    type = TokenType::Type::PLUS;
    break;
  case '-':
    type = TokenType::Type::MINUS;
    break;
  case '/':
    type = TokenType::Type::DIV;
    break;
  case '*':
    type = TokenType::Type::TIMES;
    break;
  }

  m_column += 1;
  m_position += 1;

  return Token(type, op, m_line, column);
}

Token Lexer::recognizeComparisonOp()
{
  unsigned int position = m_position;
  char character = m_input.at(position);
  char next_character = position + 1 >= m_input.length() ? ' ' : m_input.at(position + 1);
  unsigned int column = m_column;
  bool is_next_char_equal = next_character == '=';
  std::string op(1, character);
  TokenType::Type type = TokenType::Type::NULLTOKEN;
  switch (character)
  {
  case '<':
    if (is_next_char_equal)
    {
      type = TokenType::Type::LTE;
      op += next_character;
      break;
    }
    else
    {
      type = TokenType::Type::LT;
      break;
    }
  case '>':
    if (is_next_char_equal)
    {
      type = TokenType::Type::GTE;
      op += next_character;
      break;
    }
    else
    {
      type = TokenType::Type::GT;
      break;
    }
  case '=':
    if (is_next_char_equal)
    {
      type = TokenType::Type::EQ;
      op += next_character;
      break;
    }
    else
    {
      type = TokenType::Type::ASSIGN;
      break;
    }
  }

  m_column += op.length();
  m_position += op.length();

  return Token(type, op, m_line, column);
}

Token Lexer::nextToken()
{
  this->skipWhiteSpaces();

  if (m_position >= m_input.length())
  {
    return Token(TokenType::Type::ENDOFINPUT);
  }

  char character = m_input.at(m_position);

  if (CharUtils::isFirstIdentifier(character))
  {
    return this->recognizeIdentifier();
  }

  if (CharUtils::isParenthesis(character))
  {
    return this->recognizeParentheses();
  }

  if (CharUtils::isBracket(character))
  {
    return this->recognizeBrackets();
  }

  if (CharUtils::isOperator(character))
  {
    return this->recognizeOp();
  }

  if (CharUtils::isDigit(character))
  {
    return this->recognizeNumber();
  }

  throw std::invalid_argument("unhandled input");
};

std::list<Token> Lexer::allLineTokens()
{

  Token token = this->nextToken();
  while (token.type() != TokenType::Type::ENDOFINPUT)
  {
    m_tokens.push_back(token);
    token = this->nextToken();
  }
  return m_tokens;
}

void Lexer::skipWhiteSpaces()
{
  while (m_position < m_input.length() && CharUtils::isWhiteSpace(m_input.at(m_position)))
  {
    m_position++;
    m_column++;
  }
}