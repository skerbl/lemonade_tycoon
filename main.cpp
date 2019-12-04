//------------------------------------------------------------------------------
// Filename: main.cpp
// Description: The main program.
// Authors: Mirza Omerovic 1531506, Stephan Kerbl 0155521, Filip Tisaj 1530680
// Tutor: Thomas Neff
// Group ID: 15693
// Created: 25.04.2017
// Last change: 26.04.2017
//------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <random>
#include "GameHandler.h"



using std::cout;
using std::endl;


int main(int argc, char* argv[])
{
  srand(static_cast<unsigned int> (time(NULL)));

  if(argc != 4)
  {
    std::cout << "[ERR] Wrong usage: ./basic <price_lemonade> "
      "<price_lemon> <price_sugar>" << endl;
    return 2;
  }

  std::istringstream argument1(argv[1]);
  std::istringstream argument2(argv[2]);
  std::istringstream argument3(argv[3]);
  int lemonade_price;
  int lemon_price;
  int sugar_price;

  if(!(argument1 >> lemonade_price) || !(argument2 >> lemon_price) ||
      !(argument3 >> sugar_price))
  {
    std::cout << "[ERR] Wrong usage: ./basic <price_lemonade> "
      "<price_lemon> <price_sugar>" << endl;
    return 2;
  }

  GameHandler *game;

  try
  {
    game = new GameHandler();
  }
  catch(std::bad_alloc &e)
  {
    std::cout << "[ERR] Out of memory." << endl;
    return 1;
  }

  game->setLemonadePrice(lemonade_price);
  game->setLemonPrice(lemon_price);
  game->setSugarPrice(sugar_price);

  game->runGame();

  delete game;

  return 0;
}