//------------------------------------------------------------------------------
// Filename: CommandSetweather.h
// Description: Executes the setweather command.
// Authors: Mirza Omerovic 1531506, Stephan Kerbl 0155521, Filip Tisaj 1530680
// Tutor: Thomas Neff
// Group ID: 15693
// Created: 17.05.2017
// Last change: 17.05.2017
//------------------------------------------------------------------------------

#ifndef SEP17_GROUP15693_COMMANDSETWEATHER_H
#define SEP17_GROUP15693_COMMANDSETWEATHER_H


#include "Command.h"


class CommandSetweather: public Command
{
  private:

  //--------------------------------------------------------------------------
  /// Name of this command
  std::string command_name_;

  //--------------------------------------------------------------------------
  /// Number of arguments to be valid
  const unsigned int ARG_COUNT_ = 5;

  public:

  //--------------------------------------------------------------------------
  // Constructor

  CommandSetweather(std::string name);

  //--------------------------------------------------------------------------
  // Destructor

  ~CommandSetweather();

  //--------------------------------------------------------------------------
  // Executes the command.
  // @param game The game where action should be performed on
  // @param params Possible parameters neede for the execution
  // @return Integer representing the success of the action

  int execute(GameHandler& game, std::vector<std::string>& params);
};


#endif //SEP17_GROUP15693_COMMANDSETWEATHER_H


