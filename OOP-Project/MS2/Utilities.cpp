//-------------------------------------------
// OOP345 Project- Milestone 2
// Module: Utilities.cpp
// Name: Sewak Singh Gill
// Student Id: 159282219
// Email: sgill116@myseneca.ca
//-------------------------------------------

#include<string>
#include"Utilities.h"
using namespace std;
namespace sdds {
   char Utilities::m_delimiter;

   void Utilities::setFieldWidth(size_t newWidth) {
      m_widthField = newWidth;
      return;
   }

   size_t Utilities::getFieldWidth() const {
      return m_widthField;
   }

   std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
      std::string tempStr = "";
      size_t findIndex = 0;
      more = false;

      //if delimiter is found at next_pos, throw an error.
      if (str.find(m_delimiter, next_pos) == next_pos) {
         throw "   ERROR: No token.";
      }
      else {
         //error handling for std::string find method in case there is nothing found.
         if (str.find(m_delimiter, next_pos) >= str.length()) {
            findIndex = str.length();
         }
         else {
            findIndex = str.find(m_delimiter, next_pos);
         }

         tempStr = str.substr(next_pos, findIndex - next_pos + 1);

         //adding current size of string to next_pos
         next_pos += tempStr.length();

         //if next_pos >= initial string's length, it sets more to false to avoid reading from the string.
         if (next_pos >= str.length()) {
            more = false;
         }
         else {
            tempStr.erase(tempStr.find(m_delimiter));
            more = true;
         }
         tempStr = trim(tempStr);
         if (m_widthField < tempStr.size()) {
            m_widthField = tempStr.size();
         }
      }
      return tempStr;
   }

   void Utilities::setDelimiter(char newDelimiter) {
      m_delimiter = newDelimiter;
      return;
   }

   char Utilities::getDelimiter() {
      return m_delimiter;
   }

   std::string trim(std::string& str) {
      str.erase(0, str.find_first_not_of(' '));
      str.erase(str.find_last_not_of(' ')+1);
      return str;
   }
}