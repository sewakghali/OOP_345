//-------------------------------------------
// OOP345 Project- Milestone 3
// Module: Utilities.h
// Name: Sewak Singh Gill
// Student Id: 159282219
// Email: sgill116@myseneca.ca
//-------------------------------------------

#pragma once
#include<iostream>
namespace sdds {
   class Utilities {
      size_t m_widthField {1};
      static char m_delimiter;

   public:
      //updates m_widthField
      void setFieldWidth(size_t newWidth);

      //returns m_widthField
      size_t getFieldWidth() const;

      //returns extracted string from provided string
      std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

      //sets m_delimiter
      static void setDelimiter(char newDelimiter);

      //returns m_delimiter
      static char getDelimiter();
   };

   //removes preceding and trailing whitespaces
   std::string trim(std::string& str);
}