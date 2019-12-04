//------------------------------------------------------------------------------
// Filename: HTMLWriterEnvironment.h
// Description: Class that writes the current environmental conditions to a 
// .html file.
// Authors: Mirza Omerovic 1531506, Stephan Kerbl 0155521, Filip Tisaj 1530680
// Tutor: Thomas Neff
// Group ID: 15693
// Created: 12.04.2017
// Last change: 26.04.2017
//------------------------------------------------------------------------------

#ifndef PROJECT_HTMLWRITERENVIRONMENT_H
#define PROJECT_HTMLWRITERENVIRONMENT_H

#include "HTMLWriter.h"

class HTMLWriterEnvironment: public HTMLWriter
{
  private:
    std::string filename_;

    //------------------------------------------------------------------------
    // Copy constructor

    HTMLWriterEnvironment(const HTMLWriterEnvironment &);

    //--------------------------------------------------------------------------
    // Private assignment operator

    HTMLWriterEnvironment& operator=(const HTMLWriterEnvironment& original);

    //------------------------------------------------------------------------
    // Takes an enum of type Cover and returns a corresponding string containing
    // a link to an appropriate image.

    std::string coverToString(EnvironmentalCondition::Cover cover);

    std::string rankToString(EnvironmentalCondition::Rank rank);

    std::string boolToString(bool value);

  public:

    //------------------------------------------------------------------------
    // Constructor (passes filename on to base class constructor)

    HTMLWriterEnvironment(std::string filename);

    //------------------------------------------------------------------------
    // Destructor

    ~HTMLWriterEnvironment();

    //------------------------------------------------------------------------
    // Write file

    void writeFile(EnvironmentalCondition &ec);

};


#endif //PROJECT_HTMLWRITERENVIRONMENT_H
