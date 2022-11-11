/*****************************************************************
Module: Utilities.cpp
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: November 5, 2022
******************************************************************/

#include<sstream>
#include"Utilities.h"
#include"Car.h"
#include"Van.h"
#include"Luxuryvan.h"
#include"Racecar.h"
using namespace std;

namespace sdds {
   Vehicle* createInstance(std::istream& in) {
      std::string tempStr = "";
      std::string tempSub = "";
      getline(in, tempStr);
      std::stringstream ss;
      Vehicle* instance=nullptr;
      if (tempStr != "") {
         tempSub = tempStr.substr(0, tempStr.find(',') + 1);
         tempSub = trim(tempSub);
         if (tempSub[0] == 'c' || tempSub[0] == 'C') {
            ss << tempStr;
            instance = new Car(ss);
         }
         else if (tempSub[0] == 'v' || tempSub[0] == 'V') {
            ss << tempStr;
            instance = new Van(ss);
         }
         else if (tempSub[0] == 'r' || tempSub[0] == 'R') {
            ss << tempStr;
            instance = new Racecar(ss);
         }
         else if (tempSub[0] == 'l' || tempSub[0] == 'L') {
            ss << tempStr;
            instance = new Luxuryvan(ss);
         }
         else {
            std::string errMsg = "Unrecognized record type: [";
            errMsg += tempSub[0];
            errMsg += "]";
            throw errMsg;
         }
      }
      return instance;
   }

   std::string trim(std::string& str) {
      str.erase(str.find_last_not_of(' ') + 1);
      str.erase(0, str.find_first_not_of(' '));
      return str;
   }
}