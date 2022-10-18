/******************************************************************
Module: SpellChecker.h
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: October 17, 2022
******************************************************************/

#pragma once
#include<iostream>
namespace sdds {
   class SpellChecker {
      std::string m_badWords[6] = {""}; //array of bad words
      std::string m_goodWords[6] = {""}; //array of good words; parallel to m_badWords
      int m_numReplaced[6] = {0}; //keeps record of how many times a bad word was updated

   public:
      SpellChecker(const char* filename);
      void operator()(std::string& text); //functor for fixing spelling mistakes
      void showStatistics(std::ostream& out) const; //shows bad words and how many times they were corrected

   };
}