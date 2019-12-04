//------------------------------------------------------------------------------
// Filename: HTMLWriterBalance.h
// Description: Class that writes the current resource balance to a .html file.
// Authors: Mirza Omerovic 1531506, Stephan Kerbl 0155521, Filip Tisaj 1530680
// Tutor: Thomas Neff
// Group ID: 15693
// Created: 12.04.2017
// Last change: 26.04.2017
//------------------------------------------------------------------------------

#ifndef PROJECT_HTMLWRITERBALANCE_H
#define PROJECT_HTMLWRITERBALANCE_H

#include "HTMLWriter.h"

class HTMLWriterBalance: public HTMLWriter
{
  private:

    std::string filename_;

    //------------------------------------------------------------------------
    // Copy constructor
    HTMLWriterBalance(const HTMLWriterBalance &);

    //--------------------------------------------------------------------------
    // Private assignment operator

    HTMLWriterBalance& operator=(const HTMLWriterBalance& original);

  public:

    //------------------------------------------------------------------------
    // Constructor (passes filename on to base class constructor)

    HTMLWriterBalance(std::string filename);

    //------------------------------------------------------------------------
    // Destructor

    ~HTMLWriterBalance();

    //------------------------------------------------------------------------
    // Creates an HTML body string, which is passed on to HTMLWriter and written
    // into a .html file.

    void writeFile(int lemon, int sugar, int cash, int delta);

};


#endif //PROJECT_HTMLWRITERBALANCE_H
