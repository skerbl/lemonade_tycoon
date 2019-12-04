//------------------------------------------------------------------------------
// EnviromentalCondition.cpp
//
// Group: Group ID: 15693, study assistant Thomas Neff
//
// Authors: Omerovic Mirza 1531506
// Stephan Kerbl 0155521
// Filip Tisaj 1530680
//------------------------------------------------------------------------------
//

#include "EnvironmentalCondition.h"
#include "EnvironmentalEngine.h"

//setters
//------------------------------------------------------------------------------
void EnvironmentalCondition::setSkyCover(Cover cover)
{
  sky_cover_ = cover;
}

void EnvironmentalCondition::setPrecipitation(Rank rank)
{
  precipitation_ = rank;
}

void EnvironmentalCondition::setTemperature(float temperature)
{
  temperature_ = temperature;
}

void EnvironmentalCondition::setWind(Rank rank)
{
  wind_ = rank;
}

//getters
//------------------------------------------------------------------------------
EnvironmentalCondition::Cover EnvironmentalCondition::getSkyCover() const
{
  return sky_cover_;
}

EnvironmentalCondition::Rank EnvironmentalCondition::getPrecipitation() const
{
  return precipitation_;
}

float EnvironmentalCondition::getTemperature() const
{
  return temperature_;
}

EnvironmentalCondition::Rank EnvironmentalCondition::getWind() const
{
  return wind_;
}

//constructor
//------------------------------------------------------------------------------
EnvironmentalCondition::EnvironmentalCondition(Cover sky_cover, Rank precipitation,
    float temperature, Rank wind) : sky_cover_(sky_cover), precipitation_(precipitation),
    temperature_(temperature), wind_(wind)
{

};

//destructor
//------------------------------------------------------------------------------
EnvironmentalCondition::~EnvironmentalCondition()
{

};

//functions to query weather state
//------------------------------------------------------------------------------
bool EnvironmentalCondition::isItHot() const
{
  bool is_hot = false;

  if (sky_cover_ == SUNNY && temperature_ > ((EnvironmentalEngine::MAX_TEMPERATURE 
      - EnvironmentalEngine::MIN_TEMPERATURE) / 3 * 2) + EnvironmentalEngine::MIN_TEMPERATURE)
  {
    is_hot = true;
  }
  return is_hot;
}

//------------------------------------------------------------------------------
bool EnvironmentalCondition::isItRainy() const
{
  bool is_rainy = false;

  if ((precipitation_ == MEDIUM || precipitation_ == HIGH) && 
      (sky_cover_ == OVERCAST || sky_cover_ == VERY_OVERCAST))
  {
    is_rainy = true;
  }
  return is_rainy;
}

//------------------------------------------------------------------------------
bool EnvironmentalCondition::isItStormy() const
{
  bool is_stormy = false;

  if ((wind_ == MEDIUM || wind_ == HIGH) && 
      (sky_cover_ == OVERCAST || sky_cover_ == VERY_OVERCAST))
  {
    is_stormy = true;
  }
  return is_stormy;
}

bool EnvironmentalCondition::isItCold() const
{
  bool is_cold = false;

  if (temperature_ < ((EnvironmentalEngine::MAX_TEMPERATURE -
    EnvironmentalEngine::MIN_TEMPERATURE) / 3) + EnvironmentalEngine::MIN_TEMPERATURE)
  {
    is_cold = true;
  }
  return is_cold;
}

bool EnvironmentalCondition::isItCloudy() const
{
  bool is_cloudy = false;

  if (sky_cover_ == OVERCAST || sky_cover_ == VERY_OVERCAST)
  {
    is_cloudy = true;
  }
  return is_cloudy;
}

