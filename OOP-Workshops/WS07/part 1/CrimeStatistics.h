#pragma once
#include<iostream>
#include<string>
#include<vector>

namespace sdds {
   typedef struct {
      std::string m_province;
      std::string m_district;
      std::string m_crime;
      size_t m_caseNum;
      size_t m_year;
      size_t m_resolved;
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