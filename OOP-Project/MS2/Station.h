//-------------------------------------------
// OOP345 Project- Milestone 2
// Module: Station.h
// Name: Sewak Singh Gill
// Student Id: 159282219
// Email: sgill116@myseneca.ca
//-------------------------------------------

#pragma once
#include<iostream>
namespace sdds {
   class Station {
      int sId; //station id
      std::string sItem; //current item habdled
      std::string sDesc; //desc of item
      size_t sNextSrl; //next serial num to be assigned
      size_t sStockCnt; //num of items in inventory

      static size_t m_widthField; //used for formatting output
      static int id_generator; //id generator for station

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