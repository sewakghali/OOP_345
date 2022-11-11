/*****************************************************************
Module: Van.h
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: November 5, 2022
******************************************************************/

#pragma once
#include<iostream>
#include<map>
#include"Vehicle.h"

namespace sdds {
   extern std::map<std::string, std::string> vCondMap;//map for corresponding v_condition characters to corresponding condition string. E.g. 'b' for broken. Used in display function to avoid conditionals
   extern std::map<std::string, std::string> vTypeMap; //map for corresponding v_type characters to corresponding type string.
   extern std::map<std::string, std::string> vPurpMap; //map for corresponding v_purpose characters to corresponding purpose string.

   class Van :public Vehicle {
      std::string v_maker; //van maker
      std::string v_type; //type of van
      std::string v_condition; //condition of van
      std::string v_purpose; //purpose of van
      double v_tSpeed; //topspeed of van

   public:
      Van(std::istream& is); //constructor
      std::string condition() const; //returns v_conditon
      double topSpeed()const; //returns v_tSpeed
      std::string type() const; //returns v_type
      std::string usage() const; //returns v_purpose
      void display(std::ostream& out) const; //displays van details
   };
}