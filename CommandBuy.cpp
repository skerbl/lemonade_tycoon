//------------------------------------------------------------------------------
// Filename: CommandEcho.h
// Description: Executes the echo command.
// Authors: Mirza Omerovic 1531506, Stephan Kerbl 0155521, Filip Tisaj 1530680
// Tutor: Thomas Neff
// Group ID: 15693
// Created: 14.05.2017
// Last change: 18.05.2017
//------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "GameHandler.h"
#include "CommandBuy.h"


CommandBuy::CommandBuy(std::string name) : Command(name), command_name_(name)
{

}

CommandBuy::~CommandBuy()
{

}

int CommandBuy::execute(GameHandler &game, std::vector<std::string> &params)
{
  if (params.size() != ARG_COUNT_)
  {
    std::cout << "[ERR] Usage: buy <lemon> <sugar>" << std::endl;
  }
  else
  {
    int lemon_price = game.getLemonPrice();
    int sugar_price = game.getSugarPrice();
    int money = game.getMoney();
    int expenses = game.getExpenses();

    std::istringstream lemon(params.at(1));
    std::istringstream sugar(params.at(2));
    int lemon_int;
    int sugar_int;

    if(!(lemon >> lemon_int) || !(sugar >> sugar_int))
    {
      std::cout<< "[ERR] Wrong parameter." << std::endl;
      return 0;
    }

    if ((lemon_price * lemon_int) + (sugar_price * sugar_int) > money)
    {
      std::cout << "[WARN] Not enough money. I buy what I can." << std::endl;

      while (((lemon_price * lemon_int) + (sugar_price * sugar_int)) > money)
      {
        lemon_int--;
        sugar_int--;
        if (lemon_int < 0) {
          lemon_int = 0;
        }
        if (sugar_int < 0) {
          sugar_int = 0;
        }
      }
    }

    std::cout << "Bought:" << std:: endl;
    std::cout << "L: " << lemon_int << std::endl;
    std::cout << "S: " << sugar_int << std::endl;

    expenses += (lemon_price * lemon_int) + (sugar_price * sugar_int);
    money -= (lemon_price * lemon_int) + (sugar_price * sugar_int);
    game.setExpenses(expenses);
    game.setMoney(money);

    lemon_int += game.getLemon();
    sugar_int += game.getSugar();

    game.setLemon(lemon_int);
    game.setSugar(sugar_int);


    game.writeBalance();
  }

  return 0;
}
