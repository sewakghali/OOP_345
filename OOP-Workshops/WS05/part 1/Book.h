#pragma once
#include<iostream>
namespace sdds {
   class Book {
      double b_price;
      size_t b_year;
      std::string b_author;
      std::string b_title;
      std::string b_country;
      std::string b_desc;
      
   public:
      Book();
      Book(const std::string& strBook);
      const std::string& title() const;
      const std::string& country() const;
      const size_t& year() const;
      double& price();

      void changePrice(const double price);
   
      friend std::ostream& operator << (std::ostream& os, Book& book);
   };
   std::string trim(std::string& str);
}