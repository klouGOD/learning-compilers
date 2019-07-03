//
// Created by johnathan on 18/03/18.
//

#include <string>
#include <fstream>
#include <list>
#include <iostream>
#include "../include/Lexer.h"
#include "../include/Token.h"

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    std::cerr << "Usage: " << argv[0] << "SOURCE PATH" << std::endl;
    return EXIT_FAILURE;
  }

  std::ifstream fin;
  std::string line;
  Lexer lexer = Lexer();
  std::list<Token> line_tokens;

  fin.open(argv[1]);

  // Execute a loop until EOF (End of File)
  while (!fin.eof())
  {
    getline(fin, line);
    lexer.nextLine(line);
    // That is very ugly yet, it is this way only for quickly testing inputs
    line_tokens = lexer.allLineTokens();
  }
  // Close the file
  fin.close();

  for (auto i : line_tokens) 
  {
    std::cout << "[" << i.stringType() << " "<< "l" << i.line() << "-" << "c" 
    << i.column() << "]: "<< i.lexeme() << std::endl;
  }

  return EXIT_SUCCESS;
};