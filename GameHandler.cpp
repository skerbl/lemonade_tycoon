//------------------------------------------------------------------------------
// Filename: GameHandler.cpp
// Description: Controller class that handles the game.
// Authors: Mirza Omerovic 1531506, Stephan Kerbl 0155521, Filip Tisaj 1530680
// Tutor: Thomas Neff
// Group ID: 15693
// Created: 25.04.2017
// Last change: 26.04.2017
//------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>
#include "GameHandler.h"
#include "Command.h"
#include "CommandBalance.h"
#include "CommandEcho.h"
#include "CommandQuit.h"
#include "CommandQuote.h"
#include "CommandRecipe.h"
#include "UserInput.h"
#include "CommandPlay.h"
#include "CommandBuy.h"
#include "CommandSetweather.h"


//------------------------------------------------------------------------------
GameHandler::GameHandler()
  try : game_data_(new GameData)
  {
    commands_.emplace_back(new CommandEcho("echo"));
    commands_.emplace_back(new CommandQuit("quit"));
    commands_.emplace_back(new CommandQuote("quote"));
    commands_.emplace_back(new CommandBalance("balance"));
    commands_.emplace_back(new CommandRecipe("recipe"));
    commands_.emplace_back(new CommandPlay("play"));
    commands_.emplace_back(new CommandBuy("buy"));
    commands_.emplace_back(new CommandSetweather("setweather"));
    game_data_->createEnvironmentalCondition();
  }
  catch(std::bad_alloc &e)
  {
    throw e;
  }


//------------------------------------------------------------------------------
GameHandler::~GameHandler()
{
  commands_.clear();

  game_data_.reset();
}

//------------------------------------------------------------------------------
int GameHandler::runGame()
{
  bool command_executed = false;

  do
  {
    UserInput::listen(input_arguments_);

    std::transform(input_arguments_.front().begin(), input_arguments_.front().end(),
        input_arguments_.front().begin(), ::tolower);

    for (const auto &command : commands_)
    {
      if (command->getName().compare(input_arguments_.front()) == 0)
      {
        command->execute(*this, input_arguments_);
        command_executed = true;
        break;
      }
    }

    if (!command_executed)
    {
      std::cout << "[ERR] Unknown command." << std::endl;
    }

    command_executed = false;
  }
  while (!quit_flag_);

  return 0;
}

//------------------------------------------------------------------------------
void GameHandler::setQuitFlag(bool flag)
{
  quit_flag_ = flag;
}

//------------------------------------------------------------------------------
const int GameHandler::getMoney() const
{
  return game_data_->getMoney();
}

//------------------------------------------------------------------------------
const int GameHandler::getLemon() const
{
  return game_data_->getLemon();
}

//------------------------------------------------------------------------------
const int GameHandler::getSugar() const
{
  return game_data_->getSugar();
}

//------------------------------------------------------------------------------
const int GameHandler::getLemonPrice() const
{
  return game_data_->getLemonPrice();
}

//------------------------------------------------------------------------------
const int GameHandler::getSugarPrice() const
{
  return game_data_->getSugarPrice();
}

//------------------------------------------------------------------------------
const int GameHandler::getLemonPercentage() const
{
  return game_data_->getLemonPercentage();
}

//------------------------------------------------------------------------------
const int GameHandler::getSugarPercentage() const
{
  return game_data_->getSugarPercentage();
}

//------------------------------------------------------------------------------
const int GameHandler::getWaterPercentage() const
{
  return game_data_->getWaterPercentage();
}

//------------------------------------------------------------------------------
const int GameHandler::getBalance() const
{
  return game_data_->getBalance();
}

//------------------------------------------------------------------------------
const int GameHandler::getLemonadePrice() const
{
  return game_data_->getLemonadePrice();
}

//------------------------------------------------------------------------------
const int GameHandler::getExpenses() const
{
  return game_data_->getExpenses();
}


//------------------------------------------------------------------------------
void GameHandler::setMoney(int money)
{
  game_data_->setMoney(money);
}

//------------------------------------------------------------------------------
void GameHandler::setLemon(int lemon)
{
  game_data_->setLemon(lemon);
}

//------------------------------------------------------------------------------
void GameHandler::setSugar(int sugar)
{
  game_data_->setSugar(sugar);
}

//------------------------------------------------------------------------------
void GameHandler::setLemonPrice(int lemon_price)
{
  game_data_->setLemonPrice(lemon_price);
}

//------------------------------------------------------------------------------
void GameHandler::setSugarPrice(int sugar_price)
{
  game_data_->setSugarPrice(sugar_price);
}

//------------------------------------------------------------------------------
void GameHandler::setRecipe(int lemon, int sugar, int water)
{
  game_data_->setRecipe(lemon, sugar, water);
}

//------------------------------------------------------------------------------
void GameHandler::setBalance(int balance)
{
  game_data_->setBalance(balance);
}

//------------------------------------------------------------------------------
void GameHandler::setLemonadePrice(int lemonade_price)
{
  game_data_->setLemonadePrice(lemonade_price);
}

//------------------------------------------------------------------------------
void GameHandler::setExpenses(int expenses)
{
  game_data_->setExpenses(expenses);
}

//------------------------------------------------------------------------------
void GameHandler::setWeather(EnvironmentalCondition::Cover sky_cover,
                             EnvironmentalCondition::Rank precipitation,
                             float temperature,
                             EnvironmentalCondition::Rank wind)
{
    game_data_->setWeather(sky_cover, precipitation, temperature, wind);
}


//------------------------------------------------------------------------------
void GameHandler::resetRecipe()
{
  game_data_->resetRecipe();
}




//------------------------------------------------------------------------------
void GameHandler::createEnvironmentalCondition()
{
  game_data_->createEnvironmentalCondition();
}

//------------------------------------------------------------------------------
bool GameHandler::isItHot() const
{
  return game_data_->isItHot();
}

//------------------------------------------------------------------------------
bool GameHandler::isItRainy() const
{
  return game_data_->isItRainy();
}

//------------------------------------------------------------------------------
bool GameHandler::isItStormy() const
{
  return game_data_->isItStormy();
}

//------------------------------------------------------------------------------
bool GameHandler::isItCold() const
{
  return game_data_->isItCold();
}

//------------------------------------------------------------------------------
bool GameHandler::isItCloudy() const
{
  return game_data_->isItCloudy();
}

void GameHandler::writeBalance() const
{
  game_data_->writeBalance();
}

void GameHandler::writeWeather() const
{
  game_data_->writeWeather();
}
















