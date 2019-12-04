//------------------------------------------------------------------------------
// Filename: HTMLWriterBalance.cpp
// Description: Class that writes the current resource balance to a .html file.
// Authors: Mirza Omerovic 1531506, Stephan Kerbl 0155521, Filip Tisaj 1530680
// Tutor: Thomas Neff
// Group ID: 15693
// Created: 12.04.2017
// Last change: 26.04.2017
//------------------------------------------------------------------------------


#include <string>
#include <sstream>
#include "HTMLWriterBalance.h"


//------------------------------------------------------------------------
HTMLWriterBalance::HTMLWriterBalance(std::string filename) : HTMLWriter(filename),
  filename_(filename)
{

}

//------------------------------------------------------------------------
HTMLWriterBalance::~HTMLWriterBalance()
{

}

//------------------------------------------------------------------------
void HTMLWriterBalance::writeFile(int lemon, int sugar, int cash, int delta)
{
  std::string lemon_pic = "https://palme.iicm.tugraz.at/wiki/images/3/35/Lemon.png";
  std::string sugar_pic = "https://palme.iicm.tugraz.at/wiki/images/a/a9/Sugar.png";
  std::string cash_pic = "https://palme.iicm.tugraz.at/wiki/images/f/f0/Coins.png";

  std::stringstream body;

  body
    << "    <table>\n"
    << "      <tbody>\n"
    << "        <tr>\n"
    << "          <td><img src=\"" << lemon_pic << 
        "\" alt=\"\" width=\"64\" height=\"64\" /></td>\n"
    << "          <td><strong>Lemons: </strong>" << lemon << "</td>\n"
    << "        </tr>\n"
    << "        <tr>\n"
    << "          <td><img src=\"" << sugar_pic << 
        "\" alt=\"\" width=\"64\" height=\"64\" /></td>\n"
    << "          <td><strong>Sugar: </strong>" << sugar << "</td>\n"
    << "        </tr>\n"
    << "        <tr>\n"
    << "          <td><img src=\"" << cash_pic << 
        "\" alt=\"\" width=\"64\" height=\"64\" /></td>\n"
    << "          <td>\n"
    << "            <p><strong>Cash: </strong>" << cash << "$</p>\n"
    << "            <p><strong>Delta: </strong>" << delta << "$</p>\n"
    << "          </td>\n"
    << "        </tr>\n"
    << "      </tbody>\n"
    << "    </table>";

  HTMLWriter::writeFile(body.str());
}
