/******************************************************************
Module: ConfirmationSender.h
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: October 11, 2022
******************************************************************/
#pragma once
#include<iostream>
#include"Reservation.h"
namespace sdds {
   class ConfirmationSender {
      size_t count; //number of elements in resArr
      const Reservation** resvArr{}; //pointer for dynamic allocation of objects of type const Reservation*
   public:
      ConfirmationSender();
      ConfirmationSender(const ConfirmationSender& og);
      ConfirmationSender(ConfirmationSender&& og);
      ConfirmationSender& operator =(const ConfirmationSender& og);
      ConfirmationSender& operator =(ConfirmationSender&& og);
      ~ConfirmationSender();
      ConfirmationSender& operator+=(const Reservation& res);
      ConfirmationSender& operator-=(const Reservation& res);
      friend std::ostream& operator << (std::ostream& os, const ConfirmationSender& cs);
   };
}