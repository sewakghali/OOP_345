#pragma once
#include<iostream>
#include"Vehicle.h"

namespace sdds{
   //enum cCondition { 'new', 'used', 'broken' };

   class Car:public Vehicle {
      std::string c_maker;
      //cCondition c_cond;
      std::string c_cond;
      double c_tSpeed;

   public:
      Car(std::istream& is);
      std::string condition() const;
      double topSpeed() const;
      void display(std::ostream& out) const;      
   };

   std::string trim(std::string& str);
}