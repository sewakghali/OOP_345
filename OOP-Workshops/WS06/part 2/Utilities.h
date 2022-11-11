/*****************************************************************
Module: Utilities.h
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: November 5, 2022
******************************************************************/

#pragma once
#include<iostream>
#include<string>
#include"Vehicle.h"

namespace sdds {
   Vehicle* createInstance(std::istream& in);
   std::string trim(std::string& str);
}