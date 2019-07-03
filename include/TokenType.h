//
// Created by klougod on 29/06/19.
//

#ifndef TOKENTYPE_H
#define TOKENTYPE_H

namespace TokenType
{
  enum class Type
  {
    // Indentifiers and literals.
    IDENTIFIER, NUMBER,
    // Arithmetic operators. '+', '-', '*', '/'
    PLUS, MINUS, TIMES, DIV,
    // Comparison operators. '>', '>=', '<', '<=', '=='
    GT, GTE, LT, LTE, EQ,
    // Assignment operator. '='
    ASSIGN,
    // Parentheses. '(', ')'
    LEFTPARENTHESIS, RIGHTPARENTHESIS,
    // Brackets. '{', '}'
    LEFTBRACKET, RIGHTBRACKET,
    // End of input.
    ENDOFINPUT,
    // Value for token optional initialization, it may be removed if I think its 
    // better to create a new constructor without setting a TokenType value.
    NULLTOKEN
  };

  std::string stringifyTokenType(TokenType::Type type);

}; // namespace TokenType

#endif