//------------------------------------------------------------------------------
// Filename: CommandQuote.cpp
// Description: Executes the quote command.
// Authors: Mirza Omerovic 1531506, Stephan Kerbl 0155521, Filip Tisaj 1530680
// Tutor: Thomas Neff
// Group ID: 15693
// Created: 25.04.2017
// Last change: 26.04.2017
//------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include "GameHandler.h"
#include "CommandQuote.h"

CommandQuote::CommandQuote(std::string name) : Command(name)
{

}

CommandQuote::~CommandQuote()
{

}

int CommandQuote::execute(GameHandler &game, std::vector<std::string> &params)
{
  if (params.size() > ARG_COUNT_)
  {
    std::cout << "[ERR] Usage: quote" << std::endl;
  }
  else
  {
    std:: cout << "L: " << game.getLemonPrice() << " $" << std::endl;
    std:: cout << "S: " << game.getSugarPrice() << " $" << std::endl;
  }

  return 0;
}
