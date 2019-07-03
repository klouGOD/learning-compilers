//
// Created by klougod on 30/06/19.
//

#include <cctype>
#include <iostream>
#include "CharUtils.h"

bool CharUtils::isLetter(char character)
{
  return std::isalpha(character);
};

bool CharUtils::isDigit(char character)
{
  return std::isdigit(character);
};

bool CharUtils::isFirstIdentifier(char character)
{
  return character == '_' || std::isalpha(character);
};

bool CharUtils::isIdentifier(char character)
{
  return character == '-' || character == '_' || std::isalpha(character) || std::isdigit(character);
};

bool CharUtils::isWhiteSpace(char character)
{
  return std::isspace(character);
};

bool CharUtils::isParenthesis(char character)
{
  if (character == '(' || character == ')')
  {
    return true;
  }
  else
  {
    return false;
  }
};

bool CharUtils::isBracket(char character)
{
  if (character == '{' || character == '}')
  {
    return true;
  }
  else
  {
    return false;
  }
};

bool CharUtils::isOperator(char character)
{
  if (character == '+' || character == '-' || character == '/' ||
      character == '*' || character == '=' || character == '>' ||
      character == '<')
  {
    return true;
  }
  else
  {
    return false;
  }
};

bool CharUtils::isArithmeticOperator(char character)
{
  if (character == '+' || character == '-' || character == '/' || character == '*')
  {
    return true;
  }
  else
  {
    return false;
  }
};

bool CharUtils::isComparisonOperator(char character)
{
  if (character == '=' || character == '>' || character == '<')
  {
    return true;
  }
  else
  {
    return false;
  }
};