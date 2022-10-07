/******************************************************************
Module: Dictionary.h
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: October 5, 2022
******************************************************************/
#pragma once

#include <iostream>

namespace sdds {
   class Dictionary
   {
      std::string m_term{}; //stores the term
      std::string m_definition{}; //stores the definition of the term
   public:
      const std::string& getTerm() const; //returns m_term
      const std::string& getDefinition() const; //returns m_definition
      Dictionary(const std::string& term, const std::string& definition); //custom constructor for Dictionary object
      Dictionary(); //default constructor
      Dictionary& operator=(const Dictionary&); //copy assignment operator
   };
   bool operator ==(const Dictionary& d1, const Dictionary& d2); //equal operator to check if 2 objects are equal or not
   std::ostream& operator <<(std::ostream&, Dictionary&); //extraction operator overload
}