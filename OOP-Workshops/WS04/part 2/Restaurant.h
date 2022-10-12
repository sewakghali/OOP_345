/******************************************************************
Module: Restaurant.h
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: October 11, 2022
******************************************************************/
#pragma once
#include<iostream>
#include"Reservation.h"

namespace sdds {
   class Restaurant {
      size_t arrCnt; //number of elements in resArr
      const Reservation** resArr{}; //pointer for dynamic allocation of objects of type const Reservation*

   public:
      Restaurant();
      Restaurant(const Restaurant& og);
      Restaurant(Restaurant&& og);
      Restaurant& operator =(const Restaurant& og);
      Restaurant& operator =(Restaurant&& og);
      Restaurant(const Reservation* reservations[], size_t cnt);
      ~Restaurant();
      size_t size();

      friend std::ostream& operator << (std::ostream& os, const Restaurant&);
   };
}