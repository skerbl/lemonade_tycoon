//------------------------------------------------------------------------------
// HTMLWriter.cpp
//
// Group: Group ID: 15693, study assistant Thomas Neff
//
// Authors: Omerovic Mirza 1531506
// Stephan Kerbl 0155521
// Filip Tisaj 1530680
//------------------------------------------------------------------------------


#include <string>
#include <iostream>
#include <fstream>
#include "HTMLWriter.h"


//------------------------------------------------------------------------
HTMLWriter::HTMLWriter() : filename_("")
{

};


//------------------------------------------------------------------------
HTMLWriter::HTMLWriter(std::string filename) : filename_(filename)
{

};

//------------------------------------------------------------------------
HTMLWriter::~HTMLWriter()
{

};

//------------------------------------------------------------------------
void HTMLWriter::writeFile(std::string body)
{
  std::ofstream html_file;
  html_file.open(filename_);
  if (html_file.is_open())
  {
    html_file << header_;
    html_file << "  <body>\n" << body << "\n  </body>\n" "</html>\n";
    html_file.close();
  }
}

