//------------------------------------------------------------------------------
// EnviromentalEngine.cpp
//
// Group: Group ID: 15693, study assistant Thomas Neff
//
// Authors: Omerovic Mirza 1531506
// Stephan Kerbl 0155521
// Filip Tisaj 1530680
//------------------------------------------------------------------------------
//

#include <random>
#include <ctime>
#include "EnvironmentalEngine.h"
#include "EnvironmentalCondition.h"

//------------------------------------------------------------------------------
EnvironmentalCondition *EnvironmentalEngine::createCondition()
{


  EnvironmentalCondition::Cover sky_condition = (EnvironmentalCondition::Cover) 
      (rand() % EnvironmentalCondition::COVER_ELEMENTS);
      
  EnvironmentalCondition::Rank precipitation = (EnvironmentalCondition::Rank) 
      (rand() % EnvironmentalCondition::RANK_ELEMENTS);
      
  float temperature = static_cast<float>(rand() % ((MAX_TEMPERATURE - 
      MIN_TEMPERATURE) * 10)) / 10 + MIN_TEMPERATURE;
      
  EnvironmentalCondition::Rank wind = (EnvironmentalCondition::Rank) (rand() 
      % EnvironmentalCondition::RANK_ELEMENTS);


  EnvironmentalCondition *condition =  new EnvironmentalCondition(sky_condition, 
      precipitation, temperature, wind);



  return condition;
}


