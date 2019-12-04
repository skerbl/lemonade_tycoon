//------------------------------------------------------------------------------
// Filename: CommandBalance.cpp
// Description: The balance command
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
#include "CommandBalance.h"

CommandBalance::CommandBalance(std::string name) : Command(name), command_name_(name)
{

}

CommandBalance::~CommandBalance()
{

}

int CommandBalance::execute(GameHandler &game, std::vector<std::string> &params)
{
  if (params.size() > ARG_COUNT_)
  {
    std::cout << "[ERR] Usage: balance" << std::endl;
  }
  else
  {
    std:: cout << "L: " << game.getLemon() << std::endl;
    std:: cout << "S: " << game.getSugar() << std::endl;
    std:: cout << "----------" << std::endl;
    std:: cout << "C: " << game.getMoney() << " $" << std::endl;
    std:: cout << "B: " << game.getBalance() << " $" << std::endl;
  }

  return 0;
}


