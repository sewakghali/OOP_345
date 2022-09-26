/******************************************************************
Module: Timer.h
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: September 25, 2022
******************************************************************/

#pragma once
#include<iostream>
#include<chrono>

namespace sdds {
   class Timer {
      std::chrono::steady_clock::time_point begin;
      std::chrono::steady_clock::time_point end;
   public:
      void start();
      long long stop();
   };
}