//-------------------------------------------
// OOP345 Project- Milestone 3
// Module: Station.cpp
// Name: Sewak Singh Gill
// Student Id: 159282219
// Email: sgill116@myseneca.ca
//-------------------------------------------

#include<string>
#include<iomanip>
#include"Station.h"
#include"Utilities.h"
using namespace std;

namespace sdds {
   int Station::id_generator = 1;
   size_t Station::m_widthField = 0;

   Station::Station(const std::string& str) {
      string subStr = "";
      Utilities uObj = Utilities();
      bool more = false;
      size_t pos = 0;
      //catches error thrown from extractToken method from Utilities object.
      try {
         sItem = uObj.extractToken(str, pos, more);
         
         if (uObj.getFieldWidth() > m_widthField) {
            m_widthField = uObj.getFieldWidth();
         }
         uObj.setFieldWidth(m_widthField);
         if (more == true) {
            subStr = uObj.extractToken(str, pos, more);
            sNextSrl = stoi(subStr);
            subStr = uObj.extractToken(str, pos, more);
            sStockCnt = stoi(subStr);
            sDesc = uObj.extractToken(str, pos, more);
            sId = id_generator; //sets id
            id_generator++;
         }
      }
      catch (const char* msg) {
         cout <<  "Error: " << msg << endl;
      }
   }

   const std::string& Station::getItemName() const {
      return sItem;
   }

   size_t Station::getNextSerialNumber() {
      sNextSrl++;
      return sNextSrl-1;
   }

   size_t Station::getQuantity() const {
      return sStockCnt;
   }

   void Station::updateQuantity() {
      sStockCnt--;
      return;
   }

   void Station::display(std::ostream& os, bool full) const {
      os << right << setw(3) << std::setfill('0') << sId << " | " << left << setw(m_widthField+1) << setfill(' ') << sItem << " | " << right << setfill('0') << setw(6) << sNextSrl << setfill(' ') << " | ";

      if (!full) {
         os << endl;
      }
      else {
         os << setw(4) << sStockCnt << " | " << left << sDesc << endl;
      }
      return;
   }
}