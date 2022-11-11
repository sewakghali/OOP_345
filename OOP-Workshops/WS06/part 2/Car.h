/*****************************************************************
Module: Car.h
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: November 5, 2022
******************************************************************/

#pragma once
#include<iostream>
#include<map>
#include"Vehicle.h"

namespace sdds{
   extern std::map<std::string, std::string> cCondMap; //map for corresponding c_cond characters to corresponding condition string. E.g. 'b' for broken. Used in display function to avoid conditionals

   class Car:public Vehicle {
      std::string c_maker; //car maker
      std::string c_cond; //car condition
      double c_tSpeed; //car top speed

   public:
      Car(std::istream& is); //constructor
      std::string condition() const; //returns car condition
      virtual double topSpeed() const; //returns top speed
      void display(std::ostream& out) const; //displays car details    
   };
}