//------------------------------------------------------------------------------
// Filename: CommandQuit.cpp
// Description: Executes the quit command.
// Authors: Mirza Omerovic 1531506, Stephan Kerbl 0155521, Filip Tisaj 1530680
// Tutor: Thomas Neff
// Group ID: 15693
// Created: 25.04.2017
// Last change: 26.04.2017
//------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include "CommandQuit.h"
#include "GameHandler.h"


CommandQuit::CommandQuit(std::string name) : Command(name), command_name_(name)
{

}

CommandQuit::~CommandQuit()
{

}

int CommandQuit::execute(GameHandler &game, std::vector<std::string> &params)
{
  if (params.size() > ARG_COUNT_)
  {
    std::cout << "[ERR] Usage: quit" << std::endl;
  }
  else
  {
    std::cout << "Going out of business!" << std::endl;
    game.setQuitFlag(true);
  }

  return 0;
}



