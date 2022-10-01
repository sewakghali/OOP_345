#pragma once

#include<iostream>
namespace sdds {
   template<typename T,size_t arrCap>
   class Queue {
      size_t currentCap;
      T elemArr[arrCap]{};
      T notInQ{};

   public:
      bool push(const T& item);
      T& pop();
      size_t size();
      void display();
      T& operator[](size_t index);
   };
 }
