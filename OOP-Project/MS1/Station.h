//-------------------------------------------
// OOP345 Project- Milestone 1
// Module: Station.h
// Name: Sewak Singh Gill
// Student Id: 159282219
// Email: sgill116@myseneca.ca
//-------------------------------------------

#pragma once
#include<iostream>
namespace sdds {
   class Station {
      int sId;
      std::string sItem;
      std::string sDesc;
      size_t sNextSrl;
      size_t sStockCnt;

      static size_t m_widthField;
      static int id_generator;

   public:
      //constructor
      Station(const std::string&);

      //returns sItem
      const std::string& getItemName() const;

      //returns sNextSrl and updates it
      size_t getNextSerialNumber();

      //returns  sStockCnt
      size_t getQuantity() const;

      //substracts 1 from sStockCnt and returns sStockCnt
      void updateQuantity();

      //displays Station data
      void display(std::ostream& os, bool full) const;
   };
}