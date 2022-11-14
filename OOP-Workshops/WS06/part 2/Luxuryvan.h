/*****************************************************************
Module: Luxuryvan.h
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: November 5, 2022
******************************************************************/

#pragma once
#include"Van.h"

namespace sdds {
   class Luxuryvan : public Van {
      std::string l_consumption; //stores the consumption

   public:
      Luxuryvan(std::istream& in); //constructor
      void display(std::ostream& out) const; //displays the info about class Luxuryvan
      std::string consumption() const; //returns l_consumption
   };
}