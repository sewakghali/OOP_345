/*****************************************************************
Module: Van.cpp
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: November 5, 2022
******************************************************************/

#include <string>
#include<iomanip>
#include<regex>
#include"Utilities.h"
#include"Van.h"

using namespace std;
namespace sdds {
   std::map<std::string, std::string> vTypeMap = { 
      {"p","pickup"},
      {"P","pickup"},
      {"m","mini-bus"}, 
      {"M","mini-bus"},
      {"c","camper"},
      {"C","camper"}
   };
   std::map<std::string, std::string> vCondMap = {
      {"n","new"},
      {"N","new"},
      {"u","used"},
      {"U","used"},
      {"b","broken"},
      {"B","broken"}
   };
   std::map<std::string, std::string> vPurpMap = {
      {"d","delivery"},
      {"D","delivery"},
      {"p","passenger"},
      {"P","passenger"},
      {"c","camping"},
      {"C","camping"}
   };

   Van::Van(std::istream& is) {
      std::string tempStr;
      std::string tempSub;

      getline(is, tempStr);
      tempSub = tempStr.substr(0, tempStr.find(','));
      tempStr.erase(0, tempStr.find(',') + 1);
      trim(tempSub);

      tempSub = tempStr.substr(0, tempStr.find(','));
      tempStr.erase(0, tempStr.find(',') + 1);
      v_maker = trim(tempSub);

      tempSub = tempStr.substr(0, tempStr.find(','));
      tempStr.erase(0, tempStr.find(',') + 1);
      v_type = trim(tempSub);
      if (!(v_type == "p" || v_type == "m" || v_type == "c")) {
         throw "This record is invalid.";
      }

      tempSub = tempStr.substr(0, tempStr.find(','));
      tempStr.erase(0, tempStr.find(',') + 1);
      v_purpose = trim(tempSub);
      if (!(v_purpose == "d" || v_purpose == "p" || v_purpose == "c")) {
         throw "This record is invalid.";
      }

      tempSub = tempStr.substr(0, tempStr.find(','));
      tempStr.erase(0, tempStr.find(',') + 1);
      v_condition = trim(tempSub);
      if (v_condition == "") {
         v_condition = 'n';
      }
      if (!(v_condition == "n" || v_condition == "u" || v_condition == "b")) {
         throw "Invalid record!"; //throws error if there is any other character for condition
      }

      if (regex_search(tempStr, regex("[,]"))) { //checks if there is presence of a comma in the remaining string.
         tempSub = tempStr.substr(0, tempStr.find(','));
         tempStr.erase(0, tempStr.find(',') + 1);
         for (size_t i = 0; i < tempStr.size(); i++) {
            is.unget(); //puts back the characters that are read from istream for further use by Racecar constructor.
         }
         tempSub = trim(tempSub);
      }
      else {
         tempSub = trim(tempStr);
      }

      v_tSpeed = stod(trim(tempSub));
   }

   std::string Van::condition() const {
      return v_condition;
   }
   double Van::topSpeed()const {
      return v_tSpeed;
   }
   std::string Van::type() const {
      return v_type;
   }
   std::string Van::usage() const {
      return v_purpose;
   }
   void Van::display(std::ostream& out) const {
      out << "| " << right << setw(8) << setfill(' ') << v_maker << left << " | " << setw(12) << vTypeMap[type()] << " | " << setw(12) << setfill(' ') << vPurpMap[usage()] << " | " << setw(6) << setfill(' ') << vCondMap[condition()] << " | " << setw(6) << fixed << setprecision(2) << topSpeed() << " |";
      return;
   }
}