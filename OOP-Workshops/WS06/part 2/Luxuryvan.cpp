/*****************************************************************
Module: Luxuryvan.h
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: November 5, 2022
******************************************************************/

#include"Luxuryvan.h"
#include"Utilities.h"

using namespace std;
namespace sdds {
   Luxuryvan::Luxuryvan(std::istream& in):Van(in) {
      std::string tempStr = "";

      getline(in, tempStr);
      if (!(trim(tempStr) == "e" || trim(tempStr) == "E")) {
         throw "Invalid record!"; //throws error if van is not electric
      }
      l_consumption = trim(tempStr);
   }
   void Luxuryvan::display(std::ostream& out) const {
      Van::display(out); //invokes display function of Van class
      out << " electric van  *";
   }
   std::string Luxuryvan::consumption() const {
      return l_consumption;
   }
}