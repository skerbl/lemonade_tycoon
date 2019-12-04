//------------------------------------------------------------------------------
// Filename: CommandSetweather.h
// Description: Executes the setweather command.
// Authors: Mirza Omerovic 1531506, Stephan Kerbl 0155521, Filip Tisaj 1530680
// Tutor: Thomas Neff
// Group ID: 15693
// Created: 17.05.2017
// Last change: 17.05.2017
//------------------------------------------------------------------------------

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
//#include <cstdlib>
#include "GameHandler.h"
#include "CommandSetweather.h"
#include "EnvironmentalEngine.h"

CommandSetweather::CommandSetweather(std::string name) : Command(name), command_name_(name)
{

}

CommandSetweather::~CommandSetweather()
{

}

int CommandSetweather::execute(GameHandler& game, std::vector<std::string>& params)
{
  if (params.size() != ARG_COUNT_)
  {
    std::cout << "[ERR] Usage: setweather <cover> <precipitation> <temperature> <wind>" << std::endl;
    return 0;
  }

  std::istringstream cover(params.at(1));
  std::istringstream precipitation(params.at(2));
  std::istringstream temperature(params.at(3));
  std::istringstream wind(params.at(4));
  int cover_value;
  int precipitation_value;
  float temperature_value;
  int wind_value;

  if ((params.at(1).find(".") != std::string::npos) ||
      (params.at(2).find(".") != std::string::npos) ||
      (params.at(4).find(".") != std::string::npos))
  {
    std::cout << "[ERR] Wrong parameter." << std::endl;
  }

  if(!(cover >> cover_value) || !(precipitation >> precipitation_value ) ||
    !(temperature >> temperature_value) || !(wind >> wind_value))
  {
    std::cout << "[ERR] Wrong parameter." << std::endl;
    return 0;
  }

  if((cover_value > 3) || (cover_value < 0))
  {
    std::cout << "[ERR] Wrong parameter." << std::endl;
    return 0;
  }

  if((precipitation_value > 3) || (precipitation_value < 0))
  {
    std::cout << "[ERR] Wrong parameter." << std::endl;
    return 0;
  }

  if((temperature_value > EnvironmentalEngine::MAX_TEMPERATURE) ||
      (temperature_value < EnvironmentalEngine::MIN_TEMPERATURE))
  {
    std::cout << "[ERR] Wrong parameter." << std::endl;
    return 0;
  }

  if((wind_value > 3) || (wind_value < 0))
  {
    std::cout << "[ERR] Wrong parameter." << std::endl;
    return 0;
  }

  game.setWeather((EnvironmentalCondition::Cover) cover_value,
                  (EnvironmentalCondition::Rank) precipitation_value,
                  temperature_value, (EnvironmentalCondition::Rank) wind_value);
  game.writeWeather();
  return 0;
}
