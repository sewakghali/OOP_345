#pragma once
#include<iostream>
namespace sdds {
   class Movie {
      size_t m_year;
      std::string m_title;
      std::string m_desc;

   public:
      Movie();
      const std::string& title() const;
      Movie(const std::string& strMovie);

      template<typename T>
      void fixSpelling(T& spellChecker);

      friend std::ostream& operator << (std::ostream& os, Movie& movie);
   };

   template<typename T>
   inline void Movie::fixSpelling(T& spellChecker) {
      spellChecker(m_title);
      spellChecker(m_desc);
   }
}