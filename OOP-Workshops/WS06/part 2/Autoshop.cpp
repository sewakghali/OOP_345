/*****************************************************************
Module: Autoshop.cpp
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: November 5, 2022
******************************************************************/

#include"Autoshop.h"

using namespace std;
namespace sdds {
   Autoshop& Autoshop::operator +=(Vehicle* theVehicle) {
      m_vehicles.push_back(theVehicle);
      return *this;
   }
   void Autoshop::display(std::ostream& out) {
      for (vector<Vehicle*>::iterator i = m_vehicles.begin(); i < m_vehicles.end(); i++){
         (*i)->display(out);
         out << std::endl;
      }
      return;
   }

   Autoshop::~Autoshop() {
      for (vector<Vehicle*>::iterator i = m_vehicles.begin(); i < m_vehicles.end(); i++) {
         delete *i; //deletes dynamically allocated mem for Vehicle objects
      }
   }
}