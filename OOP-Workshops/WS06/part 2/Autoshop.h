/*****************************************************************
Module: Autoshop.h
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: November 5, 2022
******************************************************************/

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
      for (const auto vehicle : m_vehicles) {
         if (test(vehicle)) {
            vehicles.push_back(vehicle);
         }
      }
      return;
   }
}