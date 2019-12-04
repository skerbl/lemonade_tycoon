//------------------------------------------------------------------------------
// Filename: CommandRecipe.h
// Description: Executes the recipe command.
// Authors: Mirza Omerovic 1531506, Stephan Kerbl 0155521, Filip Tisaj 1530680
// Tutor: Thomas Neff
// Group ID: 15693
// Created: 25.04.2017
// Last change: 26.04.2017
//------------------------------------------------------------------------------

#ifndef PROJECT_COMMANDRECIPE_H
#define PROJECT_COMMANDRECIPE_H

#include "Command.h"



class CommandRecipe: public Command
{
  private:
    //--------------------------------------------------------------------------
    /// Name of this command
    std::string command_name_;

    //--------------------------------------------------------------------------
    /// Number of arguments to be valid
    const unsigned int ARG_COUNT_1_ = 1;
    const unsigned int ARG_COUNT_2_ = 4;

  public:
    //--------------------------------------------------------------------------
    // Constructor

    CommandRecipe(std::string name);

    //--------------------------------------------------------------------------
    // Destructor

    ~CommandRecipe();

    //--------------------------------------------------------------------------
    // Executes the command.
    // @param game The game where action should be performed on
    // @param params Possible parameters neede for the execution
    // @return Integer representing the success of the action

    int execute(GameHandler& game, std::vector<std::string>& params);

};



#endif //PROJECT_COMMANDRECIPE_H
