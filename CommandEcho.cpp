//------------------------------------------------------------------------------
// Filename: CommandEcho.cpp
// Description: Executes the echo command.
// Authors: Mirza Omerovic 1531506, Stephan Kerbl 0155521, Filip Tisaj 1530680
// Tutor: Thomas Neff
// Group ID: 15693
// Created: 25.04.2017
// Last change: 26.04.2017
//------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>
#include "CommandEcho.h"

CommandEcho::CommandEcho(std::string name) : Command(name), command_name_(name)
{

}

CommandEcho::~CommandEcho()
{

}

int CommandEcho::execute(GameHandler& game, std::vector<std::string>& params)
{
  if (params.size() == 0)
  {
    // do nothing.
  }
  else if (params.size() == 1)
  {
    std::cout << std::endl;
  }
  else
  {
    for (auto argument = params.begin() + 1; argument != params.end(); argument++)
    {
      if (argument == params.end() - 1)
      {
        std::cout << *argument << std::endl;
      }
      else
      {
        std::cout << *argument << " ";
      }
    }
  }
  return 0;
}