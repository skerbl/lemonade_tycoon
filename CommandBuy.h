//------------------------------------------------------------------------------
// Filename: CommandEcho.h
// Description: Executes the echo command.
// Authors: Mirza Omerovic 1531506, Stephan Kerbl 0155521, Filip Tisaj 1530680
// Tutor: Thomas Neff
// Group ID: 15693
// Created: 14.05.2017
// Last change: 18.05.2017
//------------------------------------------------------------------------------


#ifndef SEP17_GROUP15693_COMMANDBUY_H
#define SEP17_GROUP15693_COMMANDBUY_H

#include "Command.h"

class CommandBuy : public Command
{
  private:
    //--------------------------------------------------------------------------
    /// Name of this command
    std::string command_name_;

    //--------------------------------------------------------------------------
    /// Number of arguments to be valid
    const unsigned int ARG_COUNT_ = 3;

  public:
    //--------------------------------------------------------------------------
    // Constructor

    CommandBuy(std::string name);

    //--------------------------------------------------------------------------
    // Destructor

    ~CommandBuy();

    //--------------------------------------------------------------------------
    // Executes the command.
    // @param game The game where action should be performed on
    // @param params Possible parameters neede for the execution
    // @return Integer representing the success of the action

    int execute(GameHandler& game, std::vector<std::string>& params);

};


#endif //SEP17_GROUP15693_COMMANDBUY_H
