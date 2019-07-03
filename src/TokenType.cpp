//
// Created by klougod on 02/07/19.
//

#include <string>
#include "TokenType.h"


std::string TokenType::stringifyTokenType(TokenType::Type type)
{
  switch (type)
  {
    // Identifiers and literals.
    case Type::IDENTIFIER: return "IDENTIFIER";
    case Type::NUMBER: return "NUMBER";
    // Arithmetic ops.
    case Type::PLUS: return "PLUS";
    case Type::MINUS: return "MINUS";
    case Type::TIMES: return "TIMES";
    case Type::DIV: return "DIV";
    // Comparison ops.
    case Type::GT: return "GT";
    case Type::GTE: return "GTE";
    case Type::LT: return "LT";
    case Type::LTE: return "LTE";
    case Type::EQ: return "EQ";
    // Assign op.
    case Type::ASSIGN: return "ASSIGN";
    // Parentheses.
    case Type::LEFTPARENTHESIS: return "LEFTPARENTHESIS";
    case Type::RIGHTPARENTHESIS: return "RIGHTPARENTHESIS";
    // Brackets.
    case Type::LEFTBRACKET: return "LEFTBRACKET";
    case Type::RIGHTBRACKET: return "RIGHTBRACKET";
    // End of input.
    case Type::ENDOFINPUT: return "ENDOFINPUT";
    // Initialization optional value.
    case Type::NULLTOKEN: return "NULLTOKEN";
    // Fallback if some tokentype is missing in the above cases.
    default: return "TYPEMISSING";
  }
};

