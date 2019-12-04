//------------------------------------------------------------------------------
// EnviromentalCondition.h
//
// Group: Group ID: 15693, study assistant Thomas Neff
//
// Authors: Omerovic Mirza 1531506
// Stephan Kerbl 0155521
// Filip Tisaj 1530680
//------------------------------------------------------------------------------
//


#ifndef SEP17_GROUP15693_ENVIRONMENTALCONDITION_H
#define SEP17_GROUP15693_ENVIRONMENTALCONDITION_H

//------------------------------------------------------------------------------
// This class represents the weather. Consists of sky cover, precipitation, 
// temperature, and wind.
//
class EnvironmentalCondition
{
  public:
    enum Cover { SUNNY, CLOUDY, OVERCAST, VERY_OVERCAST};
    enum Rank { NONE, LOW, MEDIUM, HIGH};

    static constexpr int COVER_ELEMENTS = 4;
    static constexpr int RANK_ELEMENTS = 4;

    //------------------------------------------------------------------------
    // Setter Methods
    //
    void setSkyCover(Cover cover);
    void setPrecipitation(Rank rank);
    void setTemperature(float temperature);
    void setWind(Rank rank);

    //------------------------------------------------------------------------
    // Getter Methods
    //
    Cover getSkyCover() const;
    Rank getPrecipitation() const;
    float getTemperature() const;
    Rank getWind() const;

    //------------------------------------------------------------------------
    // Constructor
    //
    EnvironmentalCondition(Cover sky_cover, Rank precipitation, float temperature, 
      Rank wind);

    //------------------------------------------------------------------------
    // Destructor
    //
    ~EnvironmentalCondition();

    //------------------------------------------------------------------------
    // Queries whether the conditions are "hot". Returns true if sky cover is
    // SUNNY and the temperature is within the upper third of the temperature
    // range.
    //
    bool isItHot() const;

    //------------------------------------------------------------------------
    // Queries whether the conditions are "rainy". Returns true if precipitation
    // is MEDIUM or HIGH and sky cover is OVERCAST or VERY_OVERCAST.
    //
    bool isItRainy() const;

    //------------------------------------------------------------------------
    // Queries whether the conditions are "stormy". Returns true if wind is
    // HIGH or VERY_HIGH and sky cover is OVERCAST or VERY_OVERCAST.
    //
    bool isItStormy() const;

    //------------------------------------------------------------------------
    // Queries whether the conditions are "cold". Returns true if the teperature
    // is within the lower third of the temperature range.
    //
    bool isItCold() const;

    //------------------------------------------------------------------------
    // Queries whether the conditions are "cloudy". Returns true if sky cover
    // is OVERCAST or VERY_OVERCAST.
    //
    bool isItCloudy() const;


  private:
    Cover sky_cover_;
    Rank precipitation_;
    float temperature_;
    Rank wind_;

    //------------------------------------------------------------------------
    // Copy constructor
    //
    EnvironmentalCondition(const EnvironmentalCondition &);

    //--------------------------------------------------------------------------
    // Private assignment operator

    EnvironmentalCondition& operator=(const EnvironmentalCondition& original);
};

#endif //SEP17_GROUP15693_ENVIRONMENTALCONDITION_H
