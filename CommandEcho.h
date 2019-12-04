//------------------------------------------------------------------------------
// Filename: CommandEcho.h
// Description: Executes the echo command.
// Authors: Mirza Omerovic 1531506, Stephan Kerbl 0155521, Filip Tisaj 1530680
// Tutor: Thomas Neff
// Group ID: 15693
// Created: 25.04.2017
// Last change: 26.04.2017
//------------------------------------------------------------------------------

#ifndef PROJECT_COMMANDECHO_H
#define PROJECT_COMMANDECHO_H

#include "Command.h"

class CommandEcho: public Command
{
  private:
    //--------------------------------------------------------------------------
    /// Name of this command
    std::string command_name_;

  public:
    //--------------------------------------------------------------------------
    // Constructor

    CommandEcho(std::string name);

    //--------------------------------------------------------------------------
    // Destructor

    ~CommandEcho();

    //--------------------------------------------------------------------------
    // Executes the command.
    // @param game The game where action should be performed on
    // @param params Possible parameters neede for the execution
    // @return Integer representing the success of the action

    int execute(GameHandler& game, std::vector<std::string>& params);

};


#endif //PROJECT_COMMANDECHO_H
