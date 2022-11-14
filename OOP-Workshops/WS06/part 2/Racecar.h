/*****************************************************************
Module: Racecar.h
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: November 5, 2022
******************************************************************/

#pragma once
#include "Car.h"

namespace sdds {
   class Racecar : public Car {
      double r_boost; //stores the booster percent

   public:
      Racecar(std::istream& in); //constructor
      void display(std::ostream& out) const; //displays the Racecar details 
      double topSpeed() const; //returns topSpeed after adding boost
   };
}