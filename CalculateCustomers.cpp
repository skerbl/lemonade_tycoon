//------------------------------------------------------------------------------
// Filename: CalculateCustomers.h
// Description: Calculates the number of customers based on weather.
// Authors: Mirza Omerovic 1531506, Stephan Kerbl 0155521, Filip Tisaj 1530680
// Tutor: Thomas Neff
// Group ID: 15693
// Created: 17.05.2017
// Last change: 17.05.2017
//------------------------------------------------------------------------------


#include <cmath>
#include "CalculateCustomers.h"
#include "GameHandler.h"

CalculateCustomers::CalculateCustomers()
{

}

CalculateCustomers::~CalculateCustomers()
{

}

int CalculateCustomers::execute(GameHandler &game)
{
  int customers = NUMBER_OF_CUSTOMERS;
  float sales_multiplier = BASE_SALES_MULTIPLIER;
  int potential_sales;


  if(game.isItStormy())
  {
    customers = (int) round((float) customers * STORMY_WEATHER_MULTIPLIER);
  }
  else if(game.isItRainy())
  {
    customers = (int) round((float) customers * RAINY_WEATHER_MULTIPLIER);
  }
  else if(game.isItCloudy())
  {
    customers = (int) round((float) customers * CLOUDY_WEATHER_MULTIPLIER);
  }
  else if(game.isItHot())
  {
    customers = (int) round((float) customers * HOT_WEATHER_MULTIPLIER);
  }

  if(game.isItHot())
  {
    if(game.getSugarPercentage() < GameData::BASE_SUGAR_PERCENTAGE)
    {
      sales_multiplier += WEATHER_BONUS_MULTIPLIER;
    }
    if(game.getSugarPercentage() > GameData::BASE_SUGAR_PERCENTAGE)
    {
      sales_multiplier += WEATHER_PENALTY_MULTIPLIER;
    }
    if(game.getLemonPercentage() > GameData::BASE_LEMON_PERCENTAGE)
    {
      sales_multiplier += WEATHER_BONUS_MULTIPLIER;
    }
  }


  if(game.isItCold())
  {
    if(game.getSugarPercentage() > GameData::BASE_SUGAR_PERCENTAGE)
    {
      sales_multiplier += WEATHER_BONUS_MULTIPLIER;
    }
    if(game.getSugarPercentage() < GameData::BASE_SUGAR_PERCENTAGE)
    {
      sales_multiplier += WEATHER_PENALTY_MULTIPLIER;
    }
    if(game.getLemonPercentage() > GameData::BASE_LEMON_PERCENTAGE)
    {
      sales_multiplier += WEATHER_PENALTY_MULTIPLIER;
    }
  }


  if(game.getSugarPercentage() > SUGAR_SECOND_THRESHOLD)
  {
    sales_multiplier += INGREDIENT_OVER_SECOND_THRESHOLD;
  }
  else if(game.getSugarPercentage() > SUGAR_FIRST_THRESHOLD)
  {
    sales_multiplier += INGREDIENT_OVER_FIRST_THRESHOLD;
  }

  if(game.getLemonPercentage() > LEMON_SECOND_THRESHOLD)
  {
    sales_multiplier += INGREDIENT_OVER_SECOND_THRESHOLD;
  }
  else if(game.getLemonPercentage() > LEMON_FIRST_THRESHOLD)
  {
    sales_multiplier += INGREDIENT_OVER_FIRST_THRESHOLD;
  }

  if(game.getWaterPercentage() > WATER_SECOND_THRESHOLD)
  {
    sales_multiplier += INGREDIENT_OVER_SECOND_THRESHOLD;
  }
  else if(game.getWaterPercentage() > WATER_FIRST_THRESHOLD)
  {
    sales_multiplier += INGREDIENT_OVER_FIRST_THRESHOLD;
  }

  if(sales_multiplier < 0)
  {
    sales_multiplier = 0;
  }

  potential_sales = (int) round((float) customers * sales_multiplier);

  return potential_sales;
}

