#pragma once
#include<iostream>
#include"Vehicle.h"
#include"Car.h"

namespace sdds {
   /*enum vType{"pickup", "minibus", "camper" };
   enum vCondition{"new", "used", "broken" };
   enum vPurpose{"deliverey", "passenger", "camping" };*/

   class Van :public Vehicle {
      std::string v_maker;
      //vType v_type;
      //vCondition v_condition;
      //vPurpose v_purpose;
      std::string v_type;
      std::string v_condition;
      std::string v_purpose;
      double v_tSpeed;

   public:
      Van(std::istream& is);
      std::string condition() const;
      double topSpeed()const;
      std::string type() const;
      std::string usage() const;
      void display(std::ostream& out) const;
   };

   //std::string trim(std::string& str);
}