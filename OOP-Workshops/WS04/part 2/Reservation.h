#pragma once

#include <iostream>

namespace sdds {
   class Reservation {
      int numPeople;
      int r_day;
      int r_hour;
      std::string r_name;
      std::string r_email;
      std::string r_id;

   public:
      Reservation();
      Reservation(const std::string& res);
      void update(int day, int time);
      //void operator =(Reservation& r1, Reservation& r2);

      friend std::ostream& operator << (std::ostream& os, const Reservation&);
   };
   std::string trim(std::string& str);
}