//------------------------------------------------------------------------------
// Filename: UserInput.cpp
// Description: Class that listens for user input string, segments it an writes 
// the segments to a string vector provided by the caller.
// Authors: Mirza Omerovic 1531506, Stephan Kerbl 0155521, Filip Tisaj 1530680
// Tutor: Thomas Neff
// Group ID: 15693
// Created: 19.04.2017
// Last change: 26.04.2017
//------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include "UserInput.h"


void UserInput::listen(std::vector<std::string> &args)
{
  args.clear();
  std::string input_string;
  size_t word_start = 0;
  size_t word_end = 0;

  std::cout << "sep> ";
  std::getline (std::cin, input_string);

  while (word_end != std::string::npos)
  {
    // deal with leading and excess whitespaces (including tabs)
    word_start = input_string.find_first_not_of(" \t", word_end);

    // deal with trailing whitespaces
    if (word_start == std::string::npos)
    {
      break;
    }
    word_end = input_string.find_first_of(" ", word_start);
    args.push_back(input_string.substr(word_start, word_end - word_start));
  }

}

