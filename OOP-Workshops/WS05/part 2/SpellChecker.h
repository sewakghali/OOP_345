#pragma once
#include<iostream>
namespace sdds {
   class SpellChecker {
      //std::string m_strArr[][];
      std::string m_badWords[6];
      std::string m_goodWords[6];
      int m_numReplaced[6];

   public:
      SpellChecker(const char* filename);
      void operator()(std::string& text);
      void showStatistics(std::ostream& out) const;

   };
}