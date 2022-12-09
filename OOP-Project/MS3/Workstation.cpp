//-------------------------------------------
// OOP345 Project- Milestone 3
// Module: Workstation.cpp
// Name: Sewak Singh Gill
// Student Id: 159282219
// Email: sgill116@myseneca.ca
//-------------------------------------------
#include"Workstation.h"
using namespace std;
namespace sdds {
   std::deque<CustomerOrder> g_pending{};
   std::deque<CustomerOrder> g_completed{};
   std::deque<CustomerOrder> g_incomplete{};

   Workstation::Workstation(std::string& str) : Station(str) {
      ;
   }

   void Workstation::fill(std::ostream& os) {
      if (!m_orders.empty()) {
         m_orders.front().fillItem(*this, os);
      }
      return;
   }
   
   bool Workstation::attemptToMoveOrder() {
      if (!m_orders.empty())
      {
         if (m_orders.front().isItemFilled(Station::getItemName()) || Station::getQuantity() == 0)
         {
            //if more stations?
            if (m_pNextStation != nullptr) {
               (*m_pNextStation) += std::move(m_orders.front());
            }

            //if no more stations and order is complete
            else if (m_orders.front().isOrderFilled()) {
               g_completed.push_back(std::move(m_orders.front()));
            }

            //if no more stations and order is not complete
            else {
               g_incomplete.push_back(std::move(m_orders.front()));
            }

            m_orders.pop_front();
            return true;
         }
      }
      return false;
   }

   void Workstation::setNextStation(Workstation* station) {
      m_pNextStation = station;
   }

   Workstation* Workstation::getNextStation() const {
      return m_pNextStation;
   }

   void Workstation::display(std::ostream& os) const {
      os << this->getItemName() << " --> ";
      if (this->getNextStation() == nullptr) {
         os << "End of Line\n";
      }
      else {
         os << this->getNextStation()->getItemName() << '\n';
      }
   }

   Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
      m_orders.push_back(move(newOrder));
      return *this;
   }
}