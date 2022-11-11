/*****************************************************************
Module: Car.cpp
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: November 5, 2022
******************************************************************/

#include<string>
#include<algorithm>
#include<regex>
#include<iomanip>
#include"Utilities.h"
#include"Car.h"

using namespace std;

namespace sdds {
   std::map<std::string, std::string> cCondMap = { 
      {"n","new"},
      {"N","new"},
      {"u","used"},
      {"U","used"},
      {"b","broken"},
      {"B","broken"}
   };

   Car::Car(std::istream& is) {
      std::string tempStr = "";
      std::string tempSub = "";
         
      getline(is, tempStr);
      tempSub = tempStr.substr(0, tempStr.find(','));
      tempStr.erase(0, tempStr.find(',') + 1);
      tempSub = trim(tempSub);

      tempSub = tempStr.substr(0, tempStr.find(','));
      tempStr.erase(0, tempStr.find(',') + 1);
      c_maker = trim(tempSub);

      tempSub = tempStr.substr(0, tempStr.find(','));
      tempStr.erase(0, tempStr.find(',') + 1);
      c_cond = trim(tempSub);
      if (c_cond == "" ) {
         c_cond = 'n';
      }
      if (!(c_cond == "n" || c_cond == "u" || c_cond == "b")) {
         throw "Invalid record!";
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

      if (regex_search(tempSub, regex("[^0-9. ]"))) {
         throw "Invalid record!"; //throws error if any character other than 0123456789. or ' ' is found.
      }
      else {         
         c_tSpeed = stod(trim(tempSub));
      }
   }

   std::string Car::condition() const {
      return c_cond;
   }

   double Car::topSpeed() const {
      return c_tSpeed;
   }

   void Car::display(std::ostream& out) const {
      out << "| " << right << setw(10) << setfill(' ') << c_maker << left << " | " << setw(6) << cCondMap[condition()] << " | " << fixed << setw(6) << setprecision(2) << topSpeed() << " |";
      return;
   }
}