/*****************************************************************
Module: Racecar.cpp
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: November 5, 2022
******************************************************************/

#include"Racecar.h"
#include"Utilities.h"

using namespace std;
namespace sdds {
   Racecar::Racecar(std::istream& in):Car(in) {
      std::string tempStr="";

      getline(in, tempStr);
      tempStr = trim(tempStr);
      r_boost = stod(tempStr);
   }

   void Racecar::display(std::ostream& out) const {
      Car::display(out);
      out << "*";
   }

   double Racecar::topSpeed() const {
      return(Car::topSpeed() + Car::topSpeed() * r_boost);
   };
}