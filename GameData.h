//------------------------------------------------------------------------------
// Filename: GameData.h
// Description: A class that contains the game data.
// Authors: Mirza Omerovic 1531506, Stephan Kerbl 0155521, Filip Tisaj 1530680
// Tutor: Thomas Neff
// Group ID: 15693
// Created: 26.04.2017
// Last change: 26.04.2017
//------------------------------------------------------------------------------

#ifndef PROJECT_GAMEDATA_H
#define PROJECT_GAMEDATA_H


#include "EnvironmentalCondition.h"
#include "HTMLWriterBalance.h"
#include "HTMLWriterEnvironment.h"
#include <string>

class GameData
{
  private:

  //--------------------------------------------------------------------------
  // Values to be set at the execution of the game

    int lemonade_price_;
    int lemon_price_;
    int sugar_price_;

  //--------------------------------------------------------------------------
  // Initial values at the start of the game

    int money_ = 5000;
    int lemon_ = 100;
    int sugar_ = 100;
    int balance_ = 0;
    int expenses_ = 0;


    //--------------------------------------------------------------------------
    // The percentage of lemon, sugar and water in the initial recipe

    int lemon_percentage_  = 6;
    int sugar_percentage_ = 6;
    int water_percentage_ = 88;


    //--------------------------------------------------------------------------
    // Generates new weather conditions

    EnvironmentalCondition* weather_;

    //--------------------------------------------------------------------------
    // Generates new weather conditions

    HTMLWriterBalance* balance_file_= new HTMLWriterBalance("Balance.html");
    HTMLWriterEnvironment* weather_file_= new HTMLWriterEnvironment("Environment.html");

    //--------------------------------------------------------------------------
    // Private copy constructor

    GameData(const GameData &);

    //--------------------------------------------------------------------------
    // Private assignment operator

    GameData& operator=(const GameData& original);

  public:

    //--------------------------------------------------------------------------
    // Base recepie
    static int BASE_LEMON_PERCENTAGE;
    static int BASE_SUGAR_PERCENTAGE;
    static int BASE_WATER_PERCENTAGE;

    //--------------------------------------------------------------------------
    // Constructor

    GameData();

    //--------------------------------------------------------------------------
    // Destructor

    ~GameData();

    //--------------------------------------------------------------------------
    // Getter methods

    const int getMoney() const;

    const int getLemon() const;

    const int getSugar() const;

    const int getLemonPrice() const;

    const int getSugarPrice() const;

    const int getLemonPercentage() const;

    const int getSugarPercentage() const;

    const int getWaterPercentage() const;

    const int getBalance() const;

    const int getLemonadePrice() const;

    const int getExpenses() const;


  //--------------------------------------------------------------------------
  // Setter methods

    void setMoney(int money);

    void setLemon(int lemon);

    void setSugar(int sugar);

    void setLemonPrice(int lemon_price);

    void setSugarPrice(int sugar_price);

    void setRecipe(int lemon, int sugar, int water);

    void setBalance(int balance);

    void setLemonadePrice(int lemonade_price);

    void resetRecipe();

    void setExpenses(int expenses);

    void setWeather(EnvironmentalCondition::Cover sky_cover,
                    EnvironmentalCondition::Rank precipitation,
                    float temperature,
                    EnvironmentalCondition::Rank wind);




    void createEnvironmentalCondition();

    bool isItHot() const;

    bool isItRainy() const;

    bool isItStormy() const;

    bool isItCold() const;

    bool isItCloudy() const;

    void writeBalance() const;

    void writeWeather() const;

};


#endif //PROJECT_GAMEDATA_H
