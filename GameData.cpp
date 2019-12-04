//------------------------------------------------------------------------------
// Filename: GameData.cpp
// Description: Aa class that contains the data for the game.
// Authors: Mirza Omerovic 1531506, Stephan Kerbl 0155521, Filip Tisaj 1530680
// Tutor: Thomas Neff
// Group ID: 15693
// Created: 26.04.2017
// Last change: 26.04.2017
//------------------------------------------------------------------------------

#include "GameData.h"
#include "EnvironmentalEngine.h"


//------------------------------------------------------------------------------
GameData::GameData()
{

}

//------------------------------------------------------------------------------
GameData::~GameData()
{
  delete(weather_);
  delete(balance_file_);
  delete(weather_file_);
}

int GameData::BASE_LEMON_PERCENTAGE = 6;
int GameData::BASE_SUGAR_PERCENTAGE = 6;
int GameData::BASE_WATER_PERCENTAGE = 88;

//------------------------------------------------------------------------------
const int GameData::getMoney() const
{
  return money_;
}

const int GameData::getLemon() const
{
  return lemon_;
}

const int GameData::getSugar() const
{
  return sugar_;
}

const int GameData::getLemonPrice() const
{
  return lemon_price_;
}

const int GameData::getSugarPrice() const
{
  return sugar_price_;
}

const int GameData::getLemonPercentage() const
{
  return lemon_percentage_;
}

const int GameData::getSugarPercentage() const
{
  return sugar_percentage_;
}

const int GameData::getWaterPercentage() const
{
  return water_percentage_;
}

const int GameData::getBalance() const
{
  return balance_;
}

const int GameData::getLemonadePrice() const
{
  return lemonade_price_;
}

const int GameData::getExpenses() const
{
  return expenses_;
}




void GameData::setMoney(int money)
{
  money_ = money;
}

void GameData::setLemon(int lemon)
{
  lemon_ = lemon;
}

void GameData::setSugar(int sugar)
{
  sugar_ = sugar;
}

void GameData::setLemonPrice(int lemon_price)
{
  lemon_price_ = lemon_price;
}

void GameData::setSugarPrice(int sugar_price)
{
  sugar_price_ = sugar_price;
}

void GameData::setRecipe(int lemon, int sugar, int water)
{
  lemon_percentage_ = lemon;
  sugar_percentage_ = sugar;
  water_percentage_ = water;
}

void GameData::setBalance(int balance)
{
  balance_ = balance;
}

void GameData::setLemonadePrice(int lemonade_price)
{
  lemonade_price_ = lemonade_price;
}

void GameData::setExpenses(int expenses)
{
  expenses_ = expenses;
}

void GameData::setWeather(EnvironmentalCondition::Cover sky_cover,
                          EnvironmentalCondition::Rank precipitation,
                          float temperature,
                          EnvironmentalCondition::Rank wind)
{
  weather_->setSkyCover(sky_cover);
  weather_->setPrecipitation(precipitation);
  weather_->setTemperature(temperature);
  weather_->setWind(wind);
}

void GameData::resetRecipe()
{
  lemon_percentage_ = BASE_LEMON_PERCENTAGE;
  sugar_percentage_ = BASE_SUGAR_PERCENTAGE;
  water_percentage_ = BASE_WATER_PERCENTAGE;
}






void GameData::createEnvironmentalCondition()
{
  delete(weather_);
  weather_ = EnvironmentalEngine::createCondition();
}

bool GameData::isItHot() const
{
  return weather_->isItHot();
}

bool GameData::isItRainy() const
{
  return weather_->isItRainy();
}

bool GameData::isItStormy() const
{
  return weather_->isItStormy();
}

bool GameData::isItCold() const
{
  return weather_->isItCold();
}

bool GameData::isItCloudy() const
{
  return weather_->isItCloudy();
}

void GameData::writeBalance() const
{
  balance_file_->writeFile(lemon_, sugar_, money_, balance_);
}

void GameData::writeWeather() const
{
  weather_file_->writeFile(*weather_);
}













