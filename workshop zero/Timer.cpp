/******************************************************************
Module: Timer.cpp
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: September 25, 2022
******************************************************************/

#include "Timer.h"
using namespace std;
using namespace std::chrono;

namespace sdds {
   void Timer::start() {
      begin = steady_clock::now();
   }
   long long Timer::stop() {
      steady_clock::time_point end{};
      end = steady_clock::now();
      return duration_cast<nanoseconds>(end - begin).count();
   }
}