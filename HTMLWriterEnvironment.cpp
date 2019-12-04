//------------------------------------------------------------------------------
// Filename: HTMLWriterEnvironment.cpp
// Description: Class that writes the current environmental conditions to a 
// .html file.
// Authors: Mirza Omerovic 1531506, Stephan Kerbl 0155521, Filip Tisaj 1530680
// Tutor: Thomas Neff
// Group ID: 15693
// Created: 12.04.2017
// Last change: 26.04.2017
//------------------------------------------------------------------------------


#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "EnvironmentalCondition.h"
#include "HTMLWriterEnvironment.h"

using std::string;

//------------------------------------------------------------------------
HTMLWriterEnvironment::HTMLWriterEnvironment(string filename) : HTMLWriter(filename),
  filename_(filename)
{

};

//------------------------------------------------------------------------
HTMLWriterEnvironment::~HTMLWriterEnvironment()
{

}

//------------------------------------------------------------------------
string HTMLWriterEnvironment::coverToString(EnvironmentalCondition::Cover cover)
{
  string sunny = "https://palme.iicm.tugraz.at/wiki/images/9/9a/Sunny.png";
  string cloudy = "https://palme.iicm.tugraz.at/wiki/images/3/33/Cloudy.png";
  string overcast = "https://palme.iicm.tugraz.at/wiki/images/6/6f/Overcast.png";
  string very_overcast = "https://palme.iicm.tugraz.at/wiki/images/3/30/Very_overcast.png";

  switch (cover)
  {
    case EnvironmentalCondition::SUNNY :
      return sunny;
    case EnvironmentalCondition::CLOUDY :
      return cloudy;
    case EnvironmentalCondition::OVERCAST :
      return overcast;
    case EnvironmentalCondition::VERY_OVERCAST :
      return very_overcast;
    default:
      return "";
  }
}

//------------------------------------------------------------------------
string HTMLWriterEnvironment::rankToString(EnvironmentalCondition::Rank rank)
{
  string none = "none";
  string low = "low";
  string medium = "medium";
  string high = "high";

  switch (rank)
  {
    case EnvironmentalCondition::NONE :
      return none;
    case EnvironmentalCondition::LOW :
      return low;
    case EnvironmentalCondition::MEDIUM :
      return medium;
    case EnvironmentalCondition:: HIGH :
      return high;
    default:
      return "";
  }
}

//------------------------------------------------------------------------
string HTMLWriterEnvironment::boolToString(bool boolean_value)
{
  if (boolean_value)
  {
    return "true";
  }
  else
  {
    return "false";
  }
}

//------------------------------------------------------------------------
void HTMLWriterEnvironment::writeFile(EnvironmentalCondition &ec)
{
  // Maybe easier to use stringstream?
  // std::to_string doesn't work with the MinGW compiler...
  // Workaround: http://stackoverflow.com/questions/12975341/to-string-is-not-a-member-of-std-says-g-mingw
  string body =
    "    <table>\n"
    "      <tbody>\n"
    "        <tr>\n"
    "          <td><strong>Sky cover</strong></td>\n"
    "          <td></td>\n"
    "        </tr>\n"
    "        <tr>\n"
    "          <td><img src=\"";

  body += coverToString(ec.getSkyCover());
  body += "\" alt=\"\" width=\"128\" height=\"128\" /></td>\n"
    "          <td>\n"
    "            <p><strong>Precipitation: </strong>";
  body += rankToString(ec.getPrecipitation());
  body += "</p>\n"
    "            <p><strong>Temperature: </strong>";

  // This works with Linux GNU compiler, but doesn't work with Windows MinGW
  // compiler. Would need to decrease precision of float...
  //body += std::to_string(ec.getTemperature());


  // This works on both platforms. Maybe stringstream is better for the whole method?
  std::stringstream float_to_string;
  float_to_string << std::fixed << std::setprecision(1) << ec.getTemperature();
  body += float_to_string.str();


  body += "</p>\n"
    "            <p><strong>Wind: </strong>";
  body += rankToString(ec.getWind());
  body += "</p>\n"
    "            <p><strong>Hot: </strong>";
  body += boolToString(ec.isItHot());
  body += "</p>\n"
    "            <p><strong>Rainy: </strong>";
  body += boolToString(ec.isItRainy());
  body += "</p>\n"
    "            <p><strong>Stormy: </strong>";
  body += boolToString(ec.isItStormy());
  body += "</p>\n"
    "          </td>\n"
    "        </tr>\n"
    "      </tbody>\n"
    "    </table>";

  HTMLWriter::writeFile(body);
};
