/******************************************************************
Module: UniqueQueue.h
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: October 5, 2022
******************************************************************/

#pragma once
#include "Queue.h"

namespace sdds {
   template<typename T>
   class UniqueQueue:public Queue<T, 100> {
   public:
      bool push(const T& item); //dervied function from the base class with added logic for not adding duplicate data
   };
   
   template<typename T>
   bool UniqueQueue<T>::push(const T& item) {
      if (this->currentCap < 100) {
         for (int i = 0; i < this->currentCap; i++) {
            if (this->elemArr[i] == item) return false;
         }
         this->elemArr[this->currentCap] = item;
         this->currentCap++;
         return true;
      }
      return false;
   }

   //specialised template for push(...) functiom
   template<>
   inline bool UniqueQueue<double>::push(const double& item) {
      if (this->currentCap < 100) {
         for (int i = 0; i < this->currentCap; i++) {
            if ((this->elemArr[i] == item) || ((this->elemArr[i]-item ) <= 0.005 && (item - this->elemArr[i]) <= 0.005)) return false;
         }
         this->elemArr[this->currentCap] = item;
         this->currentCap++;
         return true;
      }
      return false;
   }
}