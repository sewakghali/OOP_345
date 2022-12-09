//-------------------------------------------
// OOP345 Project- Milestone 3
// Module: LineManager.h
// Name: Sewak Singh Gill
// Student Id: 159282219
// Email: sgill116@myseneca.ca
//-------------------------------------------
#pragma once
#include<iostream>
#include<vector>
#include"Workstation.h"

namespace sdds {
   class LineManager {
      std::vector<Workstation*> m_activeLine;
      size_t m_cntCustomerOrder;
      Workstation* m_firstStation;

   public:
      LineManager(const std::string& file, const std::vector<Workstation*>& stations); //custom constructor
      void reorderStations(); //reorders stations in m_activeLine
      bool run(std::ostream& os); //performs 1 iteration of each operation.
      void display(std::ostream& os) const; //displays LineManager info
   };
}