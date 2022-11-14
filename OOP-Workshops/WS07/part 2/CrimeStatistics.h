/*****************************************************************
Module: CrimeStatistics.h
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: November 12, 2022
******************************************************************/

#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<list>

namespace sdds {
   typedef struct {
      std::string m_province; //province name
      std::string m_district; //district name
      std::string m_crime; //crime type
      size_t m_caseNum; //number of cases of crime type
      size_t m_year; //year
      size_t m_resolved; //number of resolved cases
   }Crime;

   class CrimeStatistics {
      std::vector<Crime*> cs_CrimeVect; //vector containing pointers to Crime objects
   public:
      CrimeStatistics(const char* fname); //custom constructor
      ~CrimeStatistics(); //destructor
      void display(std::ostream& out) const; //display data from cs_CrimeVect
      void sort(std::string param); //sorts the objects in the cs_CrimeVect on the basis of param
      void cleanList(); //replaces "[None]" as crime name by ""
      bool inCollection(std::string) const; //checks whether a crime is in collection
      std::list<Crime> getListForProvince(std::string)const; //returns the list of crimes by province
   };

   std::ostream& operator << (std::ostream& os, const Crime& crime); //insertion operator overload for Crime object
   std::string trim(std::string&); //removes leading and ending whitespaces
}