//------------------------------------------------------------------------------
// Filename: CommandRecipe.cpp
// Description: Executes the recipe command.
// Authors: Mirza Omerovic 1531506, Stephan Kerbl 0155521, Filip Tisaj 1530680
// Tutor: Thomas Neff
// Group ID: 15693
// Created: 26.04.2017
// Last change: 26.04.2017
//------------------------------------------------------------------------------


#include <iostream>
#include <vector>
#include <locale>
#include <string>
#include "CommandRecipe.h"
#include "GameHandler.h"

CommandRecipe::CommandRecipe(std::string name) : Command(name), command_name_(name)
{

}

CommandRecipe::~CommandRecipe()
{

}

int CommandRecipe::execute(GameHandler& game, std::vector<std::string>& params)
{
  bool all_numbers = true;
  
  if (params.size() == ARG_COUNT_1_)
  {
    std::cout << "L: " << game.getLemonPercentage() << "%" << std::endl;
    std::cout << "S: " << game.getSugarPercentage() << "%" << std::endl;
    std::cout << "W: " << game.getWaterPercentage() << "%" << std::endl;
  }

  else if (params.size() != ARG_COUNT_2_)
  {
    std::cout << "[ERR] Usage: recipe [lemon] [sugar] [water]" << std::endl;
  }
  else
  {
    for (const auto &argument1 : params.at(1)) 
    {
      if (isdigit(argument1) == false) 
      {
        all_numbers = false;
      }
    }
    for (const auto &argument2 : params.at(2)) 
    {
      if (isdigit(argument2) == false) 
      {
        all_numbers = false;
      }
    }
    for (const auto &argument3 : params.at(3)) 
    {
      if (isdigit(argument3) == false) 
      {
        all_numbers = false;
      }
    }

    if (all_numbers) 
    {
      int lemon = std::stoi(params.at(1));
      int sugar = std::stoi(params.at(2));
      int water = std::stoi(params.at(3));
      int sum = lemon + sugar + water;


      if (sum != 100) 
      {
        std::cout << "[ERR] The sum of parts must be 100." << std::endl;
        return 0;
      }
      if(lemon % 3 != 0)
      {
        std::cout << "[ERR] The value of Lemon must be a multiple of 3." << std::endl;
        return 0;
      }
      if(sugar % 2 != 0)
      {
        std::cout << "[ERR] The value of Sugar must be a multiple of 2." << std::endl;
      }
      else
      {
        game.setRecipe(lemon, sugar, water);

        std::cout << "L: " << lemon << "%" << std::endl;
        std::cout << "S: " << sugar << "%" << std::endl;
        std::cout << "W: " << water << "%" << std::endl;
      }
    }
    else
    {
      std::cout << "[ERR] Wrong parameter." << std::endl;
    }
  }
  
  return 0;
}