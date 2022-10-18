/******************************************************************
Module: Movie.h
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: October 17, 2022
******************************************************************/

#pragma once
#include<iostream>
namespace sdds {
   class Movie {
      size_t m_year; //year pf movie
      std::string m_title; //movie title
      std::string m_desc; //movie description

   public:
      Movie();
      const std::string& title() const;
      Movie(const std::string& strMovie);

      template<typename T>
      void fixSpelling(T& spellChecker); //fixes spelling mistakes in m_title and m_desc

      friend std::ostream& operator << (std::ostream& os, const Movie& movie); //extraction overload
   };

   template<typename T>
   inline void Movie::fixSpelling(T& spellChecker) {
      spellChecker(m_title);
      spellChecker(m_desc);
   }
}