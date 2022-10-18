/******************************************************************
Module: Restaurant.cpp
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: October 11, 2022
******************************************************************/
#include"Restaurant.h"

using namespace std;
namespace sdds {
   Restaurant::Restaurant() {
      resArr = nullptr;
   }
   Restaurant::Restaurant(const Restaurant& og) {
      *this = og;
   }
   Restaurant::Restaurant(Restaurant&& og) {
      *this = move(og);
   }
   Restaurant& Restaurant::operator =(const Restaurant& og) {
      if (&og != this) {
         if (resArr != nullptr) {
            delete[] resArr;
         }
         resArr = new const Reservation*[og.arrCnt];
         for (size_t i = 0; i < og.arrCnt; i++) {
            resArr[i] = og.resArr[i];
         }
         arrCnt = og.arrCnt;
      }
      return *this;
   }
   Restaurant& Restaurant::operator =(Restaurant&& og) {
      if (&og != this) {
         if (resArr != nullptr) {
            delete[] resArr;
         }
         resArr = og.resArr;
         arrCnt = og.arrCnt;

         og.resArr = nullptr;
         og.arrCnt = 0;
      }
      return *this;
   }

   Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {
      if (!*reservations) {
         resArr = nullptr;
         arrCnt = 0;
      }
      else {
         resArr = new const Reservation * [cnt];
         for (size_t i = 0; i < cnt; i++) {
            resArr[i] = reservations[i];
         }
         arrCnt = cnt;
      }
   }

   Restaurant::~Restaurant() {
      delete[] resArr;
   }

   size_t Restaurant::size() {
      return arrCnt;
   }

   std::ostream& operator << (std::ostream& os,const Restaurant& res) {
      static size_t call_Cnt= 1;
      os << "--------------------------\nFancy Restaurant (" << call_Cnt <<")\n--------------------------" << endl;
      if (res.arrCnt <= 0) {
         os << "This restaurant is empty!" << endl;
      }
      else {
         for (size_t i = 0; i < res.arrCnt; i++) {
            os << *res.resArr[i];
         }
      }
      os << "--------------------------" << endl;
      call_Cnt++;

      return os;
   }
}