//------------------------------------------------------------------------------
// Filename: CommandPlay.h
// Description: Executes the play command.
// Authors: Mirza Omerovic 1531506, Stephan Kerbl 0155521, Filip Tisaj 1530680
// Tutor: Thomas Neff
// Group ID: 15693
// Created: 11.05.2017
// Last change: 11.05.2017
//------------------------------------------------------------------------------

#ifndef SEP17_GROUP15693_COMMANDPLAY_H
#define SEP17_GROUP15693_COMMANDPLAY_H

#include "Command.h"

class CommandPlay: public Command
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

  CommandPlay(std::string name);

  //--------------------------------------------------------------------------
  // Destructor

  ~CommandPlay();

  //--------------------------------------------------------------------------
  // Executes the command.
  // @param game The game where action should be performed on
  // @param params Possible parameters neede for the execution
  // @return Integer representing the success of the action

  int execute(GameHandler& game, std::vector<std::string>& params);

};

#endif //SEP17_GROUP15693_COMMANDPLAY_H
