#pragma once
#include<iostream>
#include<string>
#include<vector>

namespace sdds {
   typedef struct {
      std::string c_province;
      std::string c_district;
      std::string c_crime;
      size_t c_caseNum;
      size_t c_year;
      size_t c_resolved;
   }Crime;

   class CrimeStatistics {
      std::vector<Crime*> cs_CrimeVect;
   public:
      CrimeStatistics(const char* fname);
      void display(std::ostream& out) const;
   };

   std::ostream& operator << (std::ostream& os, const Crime& crime);
   std::string trim(std::string&);
}