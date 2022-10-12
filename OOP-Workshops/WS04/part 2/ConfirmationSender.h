#pragma once
#include<iostream>
#include"Reservation.h"
namespace sdds {
   class ConfirmationSender {
      const Reservation** resvArr{};
      size_t count;
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