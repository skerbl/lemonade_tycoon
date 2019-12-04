//------------------------------------------------------------------------------
// HTMLWriter.h
//
// Group: Group ID: 15693, study assistant Thomas Neff
//
// Authors: Omerovic Mirza 1531506
// Stephan Kerbl 0155521
// Filip Tisaj 1530680
//------------------------------------------------------------------------------
//

#ifndef PROJECT_HTMLWRITER_H
#define PROJECT_HTMLWRITER_H

#include <string>


class HTMLWriter
{
  private:
    std::string filename_;
    const std::string header_ =
      "<!DOCTYPE html>\n\n"
        "<html lang=\"en\">\n"
        "  <head>\n"
        "    <meta charset=\"utf-8\">\n"
        "    <meta http-equiv=\"refresh\" content=\"3\">\n"
        "    <title>SEP 2017</title>\n"
        "    <style>body{margin: 0px; padding: 0px;}</style>\n"
        "  </head>\n";

    //------------------------------------------------------------------------
    // Copy constructor

    HTMLWriter(const HTMLWriter &);

    //--------------------------------------------------------------------------
    // Private assignment operator

    HTMLWriter& operator=(const HTMLWriter& original);

  public:

    //------------------------------------------------------------------------
    // Default Constructor

    HTMLWriter();

    //------------------------------------------------------------------------
    // Constructor

    HTMLWriter(std::string filename);

    //------------------------------------------------------------------------
    // Destructor

    virtual ~HTMLWriter();

    //------------------------------------------------------------------------
    // Write file

    void writeFile(std::string body);

};


#endif //PROJECT_HTMLWRITER_H
