//------------------------------------------------------------------------------
// Filename: CommandQuote.h
// Description: Executes the quote command.
// Authors: Mirza Omerovic 1531506, Stephan Kerbl 0155521, Filip Tisaj 1530680
// Tutor: Thomas Neff
// Group ID: 15693
// Created: 25.04.2017
// Last change: 26.04.2017
//------------------------------------------------------------------------------

#ifndef PROJECT_COMMANDQUOTE_H
#define PROJECT_COMMANDQUOTE_H


#include "Command.h"

class CommandQuote: public Command
{
  private:
    //--------------------------------------------------------------------------
    /// Name of this command
    std::string command_name_;

    //--------------------------------------------------------------------------
    /// Number of arguments to be valid
    const unsigned int ARG_COUNT_ = 1;

  public:
    //--------------------------------------------------------------------------
    // Constructor

    CommandQuote(std::string name);

    //--------------------------------------------------------------------------
    // Destructor

    ~CommandQuote();

    //--------------------------------------------------------------------------
    // Executes the command.
    // @param game The game where action should be performed on
    // @param params Possible parameters neede for the execution
    // @return Integer representing the success of the action

    int execute(GameHandler& game, std::vector<std::string>& params);

};


#endif //PROJECT_COMMANDQUOTE_H
