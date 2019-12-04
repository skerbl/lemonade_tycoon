//------------------------------------------------------------------------------
// Filename: CommandPlay.h
// Description: Executes the play command.
// Authors: Mirza Omerovic 1531506, Stephan Kerbl 0155521, Filip Tisaj 1530680
// Tutor: Thomas Neff
// Group ID: 15693
// Created: 11.05.2017
// Last change: 11.05.2017
//------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "CommandPlay.h"
#include "GameData.h"
#include "GameHandler.h"
#include "CalculateCustomers.h"

CommandPlay::CommandPlay(std::string name) : Command(name), command_name_(name)
{

}

CommandPlay::~CommandPlay()
{

}

int CommandPlay::execute(GameHandler& game, std::vector<std::string>& params)
{

  if (params.size() > ARG_COUNT_)
  {
    std::cout << "[ERR] Usage: play" << std::endl;
  }
  else
  {

    int potential_sales;
    int lemonades_to_produce;
    int lemons_needed;
    int sugar_needed;
    int lemons_used;
    int sugar_used;
    int lemonades_produced;
    int lemons_remaining;
    int sugar_remaining;
    int money;
    int balance;
    int profits;


    potential_sales = CalculateCustomers::execute(game);
    lemonades_to_produce = (int) ceil((float) potential_sales / 4.0) * 4;
    lemonades_produced = lemonades_to_produce;

    lemons_needed = game.getLemonPercentage() / 3 * lemonades_to_produce;
    sugar_needed  = game.getSugarPercentage() / 2 * lemonades_to_produce;
    lemons_used = lemons_needed;
    sugar_used = sugar_needed;


    while(lemons_used > game.getLemon() || sugar_used > game.getSugar())
    {
      lemons_used = lemons_used - ((game.getLemonPercentage() / 3) * 4);
      sugar_used = sugar_used- ((game.getSugarPercentage() / 2) * 4);
      lemonades_produced -= 4;
    }

    lemons_remaining = game.getLemon() - lemons_used;
    sugar_remaining = game.getSugar() - sugar_used;
    game.setLemon(lemons_remaining);
    game.setSugar(sugar_remaining);

    profits = lemonades_produced * game.getLemonadePrice();

    money = game.getMoney() + profits;
    game.setMoney(money);

    balance = profits - game.getExpenses();
    game.setBalance(balance);

    // Reset expenses for next round
    game.setExpenses(0);

    // TODO: write Balance.html, write Environment.html
    // TODO: split into separate methods

    game.writeWeather();
    game.writeBalance();
    game.createEnvironmentalCondition();
  }
  return 0;
}