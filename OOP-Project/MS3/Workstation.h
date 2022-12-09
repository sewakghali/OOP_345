//-------------------------------------------
// OOP345 Project- Milestone 3
// Module: Workstation.h
// Name: Sewak Singh Gill
// Student Id: 159282219
// Email: sgill116@myseneca.ca
//-------------------------------------------

#pragma once
#include<iostream>
#include<deque>
#include"Station.h"
#include"CustomerOrder.h"
namespace sdds {
   extern std::deque<CustomerOrder> g_pending;
   extern std::deque<CustomerOrder> g_completed;
   extern std::deque<CustomerOrder> g_incomplete;

   class Workstation :public Station {
      std::deque<CustomerOrder> m_orders;
      Workstation* m_pNextStation;

   public:
      Workstation(std::string&); //1 argument constructor
      void fill(std::ostream& os); //fills the orders
      bool attemptToMoveOrder(); //moves order at the front to next station
      void setNextStation(Workstation* station); //updates m_pNextStation
      Workstation* getNextStation() const; //returns *m_pNextStation
      void display(std::ostream& os) const; //displays wstation info
      Workstation& operator+=(CustomerOrder&& newOrder); //adds order to queue

   };
}