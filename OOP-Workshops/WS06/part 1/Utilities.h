#pragma once
#include<iostream>
#include<string>
#include"Vehicle.h"

namespace sdds {
   Vehicle* createInstance(std::istream& in);
   //std::string trim(std::string& str);
}