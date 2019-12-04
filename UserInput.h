//------------------------------------------------------------------------------
// Filename: UserInput.cpp
// Description: Class that listens for user input string, segments it an writes 
// the segments to a string vector provided by the caller.
// Authors: Mirza Omerovic 1531506, Stephan Kerbl 0155521, Filip Tisaj 1530680
// Tutor: Thomas Neff
// Group ID: 15693
// Created: 19.04.2017
// Last change: 26.04.2017
//------------------------------------------------------------------------------

#ifndef PROJECT_USERINPUT_H
#define PROJECT_USERINPUT_H


class UserInput
{
  public:
    //--------------------------------------------------------------------------
    // Gets an input string and splits it into single words.
    // @param args: reference to a string vector provided by game handler
    static void listen(std::vector<std::string> &args);

  private:
    //--------------------------------------------------------------------------
    // Private constructor
    UserInput() {}

    //--------------------------------------------------------------------------
    // Private copy constructor

    UserInput(const UserInput& original);

    //--------------------------------------------------------------------------
    // Private assignment operator

    UserInput& operator=(const UserInput& original);

};


#endif //PROJECT_USERINPUT_H
