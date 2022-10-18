/******************************************************************
Module: Book.h
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: October 17, 2022
******************************************************************/

#pragma once
#include<iostream>
namespace sdds {
   class Book {
      double b_price; //book price
      size_t b_year; //year of publishing
      std::string b_author; //book author
      std::string b_title; //book title
      std::string b_country; //country of origin 
      std::string b_desc; // book description
      
   public:
      Book();
      Book(const std::string& strBook);
      const std::string& title() const; //returns b_title
      const std::string& country() const; //returns b_country
      const size_t& year() const; //returns b_year
      double& price(); //returns b_price

      void changePrice(const double price); //updates the price of book

      template<typename T>
      void fixSpelling(T& spellChecker); //fixes spelling mistakes in book description
   
      friend std::ostream& operator << (std::ostream& os, Book& book); //extraction overload
   };
   std::string trim(std::string& str); //custom function to remove whitespaces
   
   template<typename T>
   inline void Book::fixSpelling(T& spellChecker) {
      spellChecker(b_desc);
   }
}