/******************************************************************
Module: Collection.h
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: October 17, 2022
******************************************************************/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include<iostream>
#include<algorithm>
#include<string>

namespace sdds {
   template<typename T>
   class Collection { //templated class
      std::string c_name; //name of the collection
      size_t c_arrLen = 0; //length of c_arr
      T* c_arr{}; //dynamic array to store the objects of type T
      void (*addObs)(const Collection<T>&, const T&){}; //pointer to function for callback operations

   public:
      Collection(const std::string& name);
      ~Collection();
      const std::string& name() const; //returns c_name
      size_t size() const; //returns c_arrLen
      void setObserver(void (*observer)(const Collection<T>&, const T&)); //sets the value of addObs function pointer
      Collection<T>& operator+=(const T& item); //adds a new item of type T in the c_arr
      T* operator[](const std::string& title) const; //returns the element from c_arr whose title matches the argument value
      T& operator[](size_t idx) const; //returns idxth element of c_arr

   };
   template<typename T>
   std::ostream& operator << (std::ostream& os, Collection<T>& collection); //insertion operator overload

   std::string trim(std::string& str); //custom function to remove whitespaces

   inline std::string trim(std::string& str)
   {
      str.erase(str.find_last_not_of(' ') + 1);
      str.erase(0, str.find_first_not_of(' '));
      return str;
   }

   template<typename T>
   inline Collection<T>::Collection(const std::string& name) {
      c_name = name;
      c_arrLen = 0;
      c_arr = nullptr;
      addObs = nullptr;
   }

   template<typename T>
   inline Collection<T>::~Collection() {
      delete[] c_arr;
   }

   template<typename T>
   inline const std::string& Collection<T>::name() const {
      return c_name;
   }

   template<typename T>
   inline size_t Collection<T>::size() const {
      return c_arrLen;
   }

   template<typename T>
   inline void Collection<T>::setObserver(void (*observer)(const Collection<T>&, const T&)) {
      addObs = observer;
      return;
   }

   template<typename T>
   inline Collection<T>& Collection<T>::operator+=(const T& item) {
      for (size_t i = 0; i < c_arrLen; i++) {
         if (c_arr[i].title() == item.title()) return *this;
      }

      T* temp;
      temp = new T[c_arrLen];
      for (size_t i = 0; i < c_arrLen; i++) {
         temp[i] = c_arr[i];
      }
      delete[] c_arr;
      c_arrLen++;
      c_arr = new T [c_arrLen];
      for (size_t i = 0; i < c_arrLen-1; i++) {
         c_arr[i] = temp[i];
      }
      delete[] temp;
      c_arr[c_arrLen - 1] = item;
      if (addObs != nullptr) {
         addObs(*this, item);
      }
      return *this;
   }

   template<typename T>
   inline T* Collection<T>::operator[](const std::string& title) const {
      for (size_t i = 0; i < c_arrLen; i++) {
         if (c_arr[i].title() == title) return &c_arr[i];
      }
      return nullptr;
   }

   template<typename T>
   inline T& Collection<T>::operator[](size_t idx) const {
      if (idx < c_arrLen) {
         return c_arr[idx];
      }
      else {
         std::string err = "Bad index ["+ std::to_string(idx)+ "]. Collection has [" + std::to_string(idx) +"] items.";
            throw std::out_of_range(err);
      }
   }

   template<typename T>
   inline std::ostream& operator << (std::ostream& os, Collection<T>& collection) {
      for (size_t i = 0; i < collection.size(); i++) {
         os << collection[i];
      }
      return os;
   }
}
#endif