//------------------------------------------------------------------------------
// Filename: CommandQuit.h
// Description: Executes the quit command.
// Authors: Mirza Omerovic 1531506, Stephan Kerbl 0155521, Filip Tisaj 1530680
// Tutor: Thomas Neff
// Group ID: 15693
// Created: 25.04.2017
// Last change: 26.04.2017
//------------------------------------------------------------------------------

#ifndef PROJECT_COMMANDQUIT_H
#define PROJECT_COMMANDQUIT_H


#include "Command.h"

class CommandQuit: public Command
{
  private:
    //--------------------------------------------------------------------------
    /// Name of this command
    std::string command_name_;

    //--------------------------------------------------------------------------
    /// Number of arguments to be valid
    const unsigned int ARG_COUNT_ = 1;

    //--------------------------------------------------------------------------
    /// Flag to quit the game
    bool quit_flag_ = false;

  public:
    //--------------------------------------------------------------------------
    // Constructor

    CommandQuit(std::string name);

    //--------------------------------------------------------------------------
    // Destructor

    ~CommandQuit();

    //--------------------------------------------------------------------------
    // Executes the command.
    // @param game The game where action should be performed on
    // @param params Possible parameters neede for the execution
    // @return Integer representing the success of the action

    int execute(GameHandler& game, std::vector<std::string>& params);

};



#endif //PROJECT_COMMANDQUIT_H
