/******************************************************************
Module: Book.cpp
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: October 17, 2022
******************************************************************/

#include<iomanip>
#include<algorithm>
#include<string>
#include"Book.h"

using namespace std;
namespace sdds {
   Book::Book() {
      b_price = 0;
      b_year = 0;
      b_author = "";
      b_title = "";
      b_country = "";
      b_desc = "";
   }
   Book::Book(const std::string& strBook) {
      string temp = strBook;
      string tempStr = "";
      tempStr = temp.substr(0, temp.find(','));
      temp.erase(0, temp.find(',') + 1);
      b_author = trim(tempStr);

      tempStr = temp.substr(0, temp.find(','));
      temp.erase(0, temp.find(',') + 1);
      b_title = trim(tempStr);

      tempStr = temp.substr(0, temp.find(','));
      temp.erase(0, temp.find(',') + 1);
      b_country = trim(tempStr);

      tempStr = temp.substr(0, temp.find(','));
      temp.erase(0, temp.find(',') + 1);
      tempStr = trim(tempStr);
      b_price = stod(tempStr);

      tempStr = temp.substr(0, temp.find(','));
      temp.erase(0, temp.find(',') + 1);
      tempStr = trim(tempStr);
      b_year = stoi(tempStr);

      //tempStr = temp.substr(0, temp.find(','));
      //temp.erase(0, temp.find(',') + 1);
      b_desc = trim(temp);

   }
   const std::string& Book::title() const {
      return b_title;
   }
   const std::string& Book::country() const {
      return b_country;
   }
   const size_t& Book::year() const {
      return b_year;
   }
   double& Book::price() {
      return b_price;
   }

   void Book::changePrice(const double price) {
      b_price = price;
   }

   std::ostream& operator << (std::ostream& os, Book& book) {
      os << setw(20) << setfill(' ') << right << book.b_author << " | " << setw(22) << book.b_title << " | " << setw(5) << book.b_country << " | " << setw(4) << book.b_year << " | " << setw(6) << fixed << setprecision(2) << book.b_price  << " | " << left << book.b_desc << endl;
      return os;
   }

   inline std::string trim(std::string& str)
   {
      str.erase(str.find_last_not_of(' ') + 1);
      str.erase(0, str.find_first_not_of(' '));
      return str;
   }
}