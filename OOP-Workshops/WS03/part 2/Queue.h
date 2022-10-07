/******************************************************************
Module: Queue.h
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: October 5, 2022
******************************************************************/
#pragma once

#include<iostream>
#include<iomanip>
#include"Dictionary.h"

namespace sdds {

   template<typename T,size_t arrCap = 100>
   class Queue {
   protected:
      size_t currentCap{}; //holds the current capacity of elemArr
      T elemArr[arrCap]{}; //holds the objects of type T
      T notInQ{}; //contains the object after pop() from elemArr;

   public:
      Queue(); //default constructor
      Queue(T* item, size_t cap); //custom constructor
      virtual ~Queue(); //destructor
      virtual bool push(const T& item); //adds a new element in elemArr
      T& pop(); //removes first element from elemArr and returns it
      size_t size(); //returns the current size of elemArr
      void display(); //outputs the info
      T& operator[](size_t index); //returns the object at the specified index of elemArr
   };

   template<typename T, size_t arrCap>
   Queue<T, arrCap>::Queue() {
      currentCap = 0;
   }

   template<typename T, size_t arrCap>
   Queue<T, arrCap>::Queue(T* item, size_t cap) {
      currentCap = 0;
      for (size_t i = 0; i < cap; i++) {
         elemArr[i] = item[i];
         currentCap++;
      }
   }


   template<typename T, size_t arrCap>
   inline bool Queue<T, arrCap>::push(const T& item) {
      if (currentCap < arrCap) {
         elemArr[currentCap] = item;
         currentCap++;
         return true;
      }
      return false;
   }

   template<typename T, size_t arrCap>
   inline Queue<T, arrCap>::~Queue() {}

   template<typename T, size_t arrCap>
   T& Queue<T, arrCap>::pop(){
      T temp[arrCap]{};
      notInQ = elemArr[0];
      for (size_t i = 0; i < currentCap; i++) {
         temp[i] = elemArr[i+1];
         elemArr[i] = temp[i];
      }
      currentCap--;
      return notInQ;
   }

   template<typename T, size_t arrCap>
   size_t sdds::Queue<T, arrCap>::size()
   {
      return currentCap;
   }

   template<typename T, size_t  arrCap>
   void Queue<T, arrCap>::display() {
      std::cout << "----------------------\n| Dictionary Content |\n----------------------" << std::endl;
      for (size_t i = 0; i < currentCap; i++) {
         std::cout << elemArr[i] << "\n";
      }
      std::cout << "----------------------" << std::endl;
   }

   //specialised template for Dictionary object
   template<>
   inline void Queue<Dictionary, 100>::display() {
      std::cout << "----------------------\n| Dictionary Content |\n----------------------" << std::endl;
      for (size_t i = 0; i < currentCap; i++) {
         std::cout.width(21);
         std::cout << std::setfill(' ') << elemArr[i].getTerm();
         std::cout << ": " << elemArr[i].getDefinition() << std::endl;
      }
      std::cout << "----------------------" << std::endl;
   }

   template<typename T, size_t  arrCap>
   T& Queue<T, arrCap>::operator[](size_t index) {
      return elemArr[index];
   }
 }
