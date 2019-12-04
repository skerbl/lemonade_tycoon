//------------------------------------------------------------------------------
// Filename: Command.h
// Description: Class representing a general command
// Authors: Tutors
// Tutor: Tutors
// Group ID: 15693
// Created: 08.08.2011
// Last change: 19.04.2017
//------------------------------------------------------------------------------

#ifndef PROJECT_COMMAND_H
#define PROJECT_COMMAND_H


class GameHandler;

class Command
{
  private:
    //--------------------------------------------------------------------------
    // Private copy constructor

    Command(const Command& original);

    //--------------------------------------------------------------------------
    // Private assignment operator

    Command& operator=(const Command& original);

    //--------------------------------------------------------------------------
    /// Name of this command
    std::string command_name_;

  public:
    //--------------------------------------------------------------------------
    // Constructor

    Command(std::string name);

    //--------------------------------------------------------------------------
    // Destructor

    virtual ~Command();

    //--------------------------------------------------------------------------
    // Executes the command.
    // @param game The game where action should be performed on
    // @param params Possible parameters neede for the execution
    // @return Integer representing the success of the action

    virtual int execute(GameHandler& game, std::vector<std::string>& params) = 0;

    //--------------------------------------------------------------------------
    // Getter Methods
    const std::string& getName() const;
};

#endif //PROJECT_COMMAND_H
