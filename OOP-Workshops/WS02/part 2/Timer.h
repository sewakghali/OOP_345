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
      std::chrono::steady_clock::time_point begin{}; //variable to store the starting point
   public:
      void start(); //starts the timer
      long long stop(); //ends the timer and returns the time elapsed in nanoseconds.
   };
}