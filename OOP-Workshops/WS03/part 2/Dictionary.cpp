/******************************************************************
Module: Dictionary.cpp
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: October 5, 2022
******************************************************************/
#include"Dictionary.h"
using namespace std;
namespace sdds {

   const string& Dictionary::getTerm() const { return m_term; }
   const string& Dictionary::getDefinition() const { return m_definition; }
   Dictionary::Dictionary(const string& term, const string& definition) : m_term{ term }, m_definition{ definition } {}

   Dictionary::Dictionary() {}

   Dictionary& Dictionary::operator=(const Dictionary& ogDict) {
      m_term = ogDict.getTerm();
      m_definition = ogDict.getDefinition();
   }

   bool operator ==(const Dictionary& d1, const Dictionary& d2){
      if (d1.getTerm() == d2.getTerm() && d1.getDefinition() == d2.getDefinition()) return true;
      return false;
   }

   std::ostream& operator <<(std::ostream& os, Dictionary& dict) {
      os << dict.getTerm() << ": " << dict.getDefinition();
   };
}