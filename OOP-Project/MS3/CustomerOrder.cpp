//-------------------------------------------
// OOP345 Project- Milestone 3
// Module: CustomerOrder.cpp
// Name: Sewak Singh Gill
// Student Id: 159282219
// Email: sgill116@myseneca.ca
//-------------------------------------------
#include<iomanip>
#include<string>
#include"CustomerOrder.h"
#include"Utilities.h"

using namespace std;
namespace sdds {
   size_t CustomerOrder::m_widthField{ 0 };

	CustomerOrder::CustomerOrder() {
		m_name = "";
		m_product = "";
		m_cntItem = 0;
      m_lstItem = { nullptr };
	}

   CustomerOrder::CustomerOrder(const std::string& str) {
      string subStr = "";
      Utilities uObj = Utilities();
      bool more = false;
      size_t pos = 0;

      m_cntItem = 0;
      try {
         Item** listArr{};
         m_name = uObj.extractToken(str, pos, more);
         m_product = uObj.extractToken(str, pos, more);

         Item* newItem = nullptr;
         for (size_t i = 0; more == true; i++) {
            subStr = uObj.extractToken(str, pos, more);
            subStr = const_cast<string&>(subStr);
            newItem = new Item(subStr);

            listArr = m_lstItem;
            m_lstItem = nullptr;

            if (m_widthField < uObj.getFieldWidth()) {
               m_widthField = uObj.getFieldWidth();
            }

            m_cntItem++;
            m_lstItem = new Item* [m_cntItem];
            for (size_t j = 0; j < m_cntItem - 1; j++) {
               m_lstItem[j] = listArr[j];
               listArr[j] = nullptr;
            }

            m_lstItem[m_cntItem - 1] = newItem;
            delete[] listArr;
            listArr = nullptr;
         }
      }
      catch (const char* msg) {
         cout << "Error: " << msg << endl;
      }
   }

   CustomerOrder::CustomerOrder(const CustomerOrder&) {
      throw "Error: copy constructor not available";
   }

   CustomerOrder::CustomerOrder(CustomerOrder&& original) noexcept {
      *this = move(original);
   }

   CustomerOrder& CustomerOrder::operator = (CustomerOrder&& original) {
      if (this == &original) {
         return *this;
      }
      if (m_lstItem != nullptr) {
         for (size_t i = 0; i < m_cntItem; i++) {
            delete m_lstItem[i]; //deletes allocated Item object
         }
         delete[] m_lstItem;
      }
      m_name = original.m_name;
      m_product = original.m_product;
      m_cntItem = original.m_cntItem;
      m_lstItem = original.m_lstItem;
      original.m_lstItem = nullptr;

      return *this;
   }

   CustomerOrder::~CustomerOrder() {
      if (m_lstItem != nullptr) {
         for (size_t i = 0; i < m_cntItem; i++) {
            delete m_lstItem[i]; //deletes allocated Item objects in m_lstItem array
         }
      }
      delete[] m_lstItem;
   }

   bool CustomerOrder::isOrderFilled()const {
      bool isFilled = true;
      for (size_t i = 0; i < m_cntItem; i++) {
         if (m_lstItem[i]->m_isFilled == false) {
            isFilled = false;
         }
      }
      return isFilled;
   }

   bool CustomerOrder::isItemFilled(const std::string& itemName) const {
      bool isFilled = true;
      for (size_t i = 0; i < m_cntItem; i++) {
         if (m_lstItem[i]->m_itemName == itemName) {
            if (m_lstItem[i]->m_isFilled == false)
               isFilled = false;
         }
      }
      return isFilled;
   }

   void CustomerOrder::fillItem(Station& station, std::ostream& os) {
      for (size_t i = 0; i < m_cntItem; i++) {
         if (m_lstItem[i]->m_itemName == station.getItemName() && !m_lstItem[i]->m_isFilled) {
            if (station.getQuantity() > 0) {
               m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
               m_lstItem[i]->m_isFilled = true;
               station.updateQuantity();
               os << "    Filled "<< m_name <<", "<< m_product <<" [" << m_lstItem[i]->m_itemName << "]" << endl;
               return; //returns because it fills only one item
            }
            else {
               m_lstItem[i]->m_isFilled = false;
               os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
            }
         }
      }
      return;
   }

   void CustomerOrder::display(std::ostream& os) const {
      os << m_name << " - " << m_product << endl;
      for (size_t i = 0; i < m_cntItem; i++) {
         os << "[" << right << setw(6) << setfill('0') << m_lstItem[i]->m_serialNumber << "] " << setw(m_widthField+2) << left << setfill(' ') << m_lstItem[i]->m_itemName;
         os << " - " << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << endl;
      }
      return;
   }
}