#pragma once
#include<iostream>
#include<vector>
#include<list>
#include"Vehicle.h"

namespace sdds {
   class Autoshop {
      std::vector<Vehicle*> m_vehicles;

   public:
      Autoshop& operator +=(Vehicle* theVehicle);
      void display(std::ostream& out);
      ~Autoshop();

      template<typename T>
      void select(T test, std::list<const Vehicle*>& vehicles);
   };

   template<typename T>
   void Autoshop::select(T test, std::list<const Vehicle*>& vehicles) {
      /*testFunc = [test](const Vehicle*) {
         if (vehicle*) {
            return true;
         }
         return false;
      }*/
      vehicles.push_back(test);
   }
}