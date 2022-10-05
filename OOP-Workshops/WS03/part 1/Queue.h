#pragma once

#include<iostream>
namespace sdds {
   template<typename T,size_t arrCap>
   class Queue {
      size_t currentCap{};
      T elemArr[arrCap]{};
      T notInQ{};

   public:
      Queue();
      Queue(T* item, size_t cap);
      bool push(const T& item);
      T& pop();
      size_t size();
      void display();
      T& operator[](size_t index);
   };

   template<typename T, size_t arrCap>
   Queue<T, arrCap>::Queue() {
      currentCap = 0;
      //elemArr[arrCap] = {};
      //notInQ = {};
   }

   template<typename T, size_t arrCap>
   Queue<T, arrCap>::Queue(T* item, size_t cap) {
      currentCap = 0;
      for (int i = 0; i < cap; i++) {
         elemArr[i] = item[i];
         currentCap++;
      }
   }

   template<typename T, size_t arrCap>
   bool Queue<T, arrCap>::push(const T& item) {
      if (currentCap < arrCap) {
         elemArr[currentCap] = item;
         currentCap++;
         return true;
      }
      return false;
   }

   template<typename T, size_t arrCap>
   T& Queue<T, arrCap>::pop(){
      T* temp;
      T tempObj = elemArr[0];
      temp = new T[currentCap];
      for (int i = 0; i < currentCap; i++) {
         temp[i] = elemArr[i+1];
         elemArr[i] = temp[i];
      }
      currentCap--;
      delete[] temp;
      return tempObj;
   }

   template<typename T, size_t arrCap>
   size_t sdds::Queue<T, arrCap>::size()
   {
      return currentCap;
   }

   template<typename T, size_t  arrCap>
   void Queue<T, arrCap>::display() {
      //std::cout << "hello";
      for (int i = 0; i < currentCap; i++) {
         std::cout << elemArr[i] << std::endl;
      }
   }

   template<typename T, size_t  arrCap>
   T& Queue<T, arrCap>::operator[](size_t index) {
      return elemArr[index];
   }
 }
