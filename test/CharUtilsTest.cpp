//
// Created by klougod on 03/07/19.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <CharUtils.h>
#include <string>
#include <cstdio>

TEST(isLetter, whenInputIsLetter_ShouldReturnTrue)
{
  unsigned int alpha_len = 52;
  char alpha [alpha_len];

  // populates the array of chars with all the ASCII values for alpha chars.
  unsigned int i = 0;
  for (unsigned int j = 65; j < 91; ++j)
  {
    alpha[i] = j;
    ++i;
  }
  for (unsigned int j = 97; j < 123; ++j)
  {
    alpha[i] = j;
    ++i;
  }

  for (unsigned int t = 0; t < alpha_len; ++t)
  {
    EXPECT_EQ(CharUtils::isLetter(alpha[t]), true);
  }
}

TEST(isLetter, whenInputIsNotLetter_ShouldReturnFalse)
{
  unsigned int non_alpha_len = 74;
  char non_alpha [non_alpha_len];

  // populates the array of chars with all the ASCII values for non_alpha chars.
  unsigned int i = 0;
  for (unsigned int j = 0; j < 65; ++j)
  {
    non_alpha[i] = j;
    ++i;
  }
  for (unsigned int j = 91; j < 97; ++j)
  {
    non_alpha[i] = j;
    ++i;
  }
  for (unsigned int j = 123; j < 128; ++j)
  {
    non_alpha[i] = j;
    ++i;
  }

  for (unsigned int t = 0; t < non_alpha_len; ++t)
  {
    EXPECT_EQ(CharUtils::isLetter(non_alpha[t]), false);
  }
}

TEST(isDigit, whenInputIsDigit_ShouldReturnTrue)
{
  const char* digits = "0123456789";
  unsigned int len = (unsigned)strlen(digits);

  for (unsigned int i = 0; i < len; ++i)
  {
    EXPECT_EQ(CharUtils::isDigit(digits[i]), true);
  }
}
