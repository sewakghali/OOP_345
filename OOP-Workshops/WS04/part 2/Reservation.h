/******************************************************************
Module: Reservation.h
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: October 11, 2022
******************************************************************/
#pragma once

#include <iostream>

namespace sdds {
   class Reservation {
      int numPeople; //num of people
      int r_day; //day of reservation
      int r_hour; //time of the day
      std::string r_name; //name of the reservee
      std::string r_email; //email of the reservee
      std::string r_id; //reservation id

   public:
      Reservation();
      Reservation(const std::string& res);
      void update(int day, int time);
      //void operator =(Reservation& r1, Reservation& r2);

      friend std::ostream& operator << (std::ostream& os, const Reservation&);
   };
   //function to remove preceeding and trailing whitespaces
   std::string trim(std::string& str);
}