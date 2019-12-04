//------------------------------------------------------------------------------
// EnviromentalEngine.h
//
// Group: Group ID: 15693, study assistant Thomas Neff
//
// Authors: Omerovic Mirza 1531506
// Stephan Kerbl 0155521
// Filip Tisaj 1530680
//------------------------------------------------------------------------------
//

#ifndef SEP17_GROUP15693_ENVIROMENTALENGINE_H
#define SEP17_GROUP15693_ENVIROMENTALENGINE_H

//------------------------------------------------------------------------------
// Forward declaration of class EnvironmentalCondition
class EnvironmentalCondition;

//------------------------------------------------------------------------------
// The environmental engine. Creates a new object of EnvironmentalCondition with 
// randomized parameters and returns a pointer to it.
//
class EnvironmentalEngine
{
  public:
    static constexpr int MAX_TEMPERATURE = 35;
    static constexpr int MIN_TEMPERATURE = 10;

    EnvironmentalCondition static *createCondition();

};


#endif //SEP17_GROUP15693_ENVIROMENTALENGINE_H
