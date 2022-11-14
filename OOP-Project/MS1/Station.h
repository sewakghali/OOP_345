#pragma once
#include<iostream>
namespace sdds {
   class Station {
      int sId;
      std::string sItem;
      std::string sDesc;
      size_t sNextSrl;
      size_t sStockCnt;

      size_t m_widthField;
      int id_generator;

   public:
      Station(const std::string&);
      const std::string& getItemName() const;
      size_t getNextSerialNumber();
      size_t getQuantity() const;
      void updateQuantity();
      void display(std::ostream& os, bool full) const;
   };
}