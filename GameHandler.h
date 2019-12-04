//------------------------------------------------------------------------------
// Filename: GameHandler.h
// Description: Controller class that handles the game.
// Authors: Mirza Omerovic 1531506, Stephan Kerbl 0155521, Filip Tisaj 1530680
// Tutor: Thomas Neff
// Group ID: 15693
// Created: 25.04.2017
// Last change: 26.04.2017
//------------------------------------------------------------------------------

#ifndef PROJECT_GAMEHANDLER_H
#define PROJECT_GAMEHANDLER_H

#include <memory>
#include <vector>
#include "GameData.h"

class Command;
class GameData;

class GameHandler
{
  private:
    std::vector<std::unique_ptr<Command>> commands_;

    std::vector<std::string> input_arguments_ {""};

    bool quit_flag_ = false;

    std::unique_ptr<GameData> game_data_;

    //--------------------------------------------------------------------------
    // Private copy constructor

    GameHandler(const GameHandler& original);

    //--------------------------------------------------------------------------
    // Private assignment operator

    GameHandler& operator=(const GameHandler& original);

  public:
    //--------------------------------------------------------------------------
    // Constructor

    GameHandler();

    //--------------------------------------------------------------------------
    // Destructor

    ~GameHandler();

    //--------------------------------------------------------------------------
    // Run: This runs the game. Return 0 for success.

    int runGame();

    //--------------------------------------------------------------------------
    // Setter method for quit flag

    void setQuitFlag(bool flag);

    //--------------------------------------------------------------------------
    // Getter methods for game data

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
  // Setter methods for game data

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


#endif //PROJECT_GAMEHANDLER_H
