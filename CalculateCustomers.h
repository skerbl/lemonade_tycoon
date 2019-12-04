//------------------------------------------------------------------------------
// Filename: CalculateCustomers.h
// Description: Calculates the number of customers based on weather.
// Authors: Mirza Omerovic 1531506, Stephan Kerbl 0155521, Filip Tisaj 1530680
// Tutor: Thomas Neff
// Group ID: 15693
// Created: 17.05.2017
// Last change: 17.05.2017
//------------------------------------------------------------------------------

#ifndef SEP17_GROUP15693_CALCULATECUSTOMERS_H
#define SEP17_GROUP15693_CALCULATECUSTOMERS_H

class GameHandler;

class CalculateCustomers
{
  private:

  static const int NUMBER_OF_CUSTOMERS = 500;

  //--------------------------------------------------------------------------
  // Constants for calculating the number of sales for this round
  static constexpr float BASE_SALES_MULTIPLIER = 1.0f;
  static constexpr float WEATHER_PENALTY_MULTIPLIER = -0.2f;
  static constexpr float WEATHER_BONUS_MULTIPLIER = 0.2f;
  static constexpr float INGREDIENT_OVER_FIRST_THRESHOLD = -0.5f;
  static constexpr float INGREDIENT_OVER_SECOND_THRESHOLD = -1.0f;

  //--------------------------------------------------------------------------
  // Ingredient penalty thresholds
  static const int SUGAR_FIRST_THRESHOLD = 15;
  static const int SUGAR_SECOND_THRESHOLD = 20;
  static const int LEMON_FIRST_THRESHOLD = 12;
  static const int LEMON_SECOND_THRESHOLD = 18;
  static const int WATER_FIRST_THRESHOLD = 95;
  static const int WATER_SECOND_THRESHOLD = 98;

  // Constants for calculating the number of customers for this round
  static constexpr float HOT_WEATHER_MULTIPLIER = 1.5f;
  static constexpr float CLOUDY_WEATHER_MULTIPLIER = 0.8f;
  static constexpr float RAINY_WEATHER_MULTIPLIER = 0.5f;
  static constexpr float STORMY_WEATHER_MULTIPLIER = 0.1f;

  public:

  //--------------------------------------------------------------------------
  // Constructor

  CalculateCustomers();

  //--------------------------------------------------------------------------
  // Destructor

  ~CalculateCustomers();


  static int execute(GameHandler& game);

};

#endif //SEP17_GROUP15693_CALCULATECUSTOMERS_H
