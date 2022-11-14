/*****************************************************************
Module: CrimeStatistics.cpp
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: November 12, 2022
******************************************************************/

#include<algorithm>
#include<fstream>
#include<iomanip>
#include"CrimeStatistics.h"

using namespace std;
namespace sdds {
   CrimeStatistics::CrimeStatistics(const char* fname) {
      ifstream is(fname);
      if (is.good()) {
         Crime* temp;
         string tempStr = "";
         string subStr = "";
         for (size_t i = 0; !is.eof(); i++) {
            temp = new Crime;
            tempStr = "";
            getline(is, tempStr);
            subStr = tempStr.substr(0, 25);
            tempStr.erase(0, 25);
            temp->m_province = trim(subStr);

            subStr = tempStr.substr(0, 25);
            tempStr.erase(0, 25);
            temp->m_district = trim(subStr);

            subStr = tempStr.substr(0, 25);
            tempStr.erase(0, 25);
            temp->m_crime = trim(subStr);

            subStr = tempStr.substr(0, 5);
            tempStr.erase(0, 5);
            temp->m_year = stoi(trim(subStr));

            subStr = tempStr.substr(0, 5);
            tempStr.erase(0, 5);
            temp->m_caseNum = stoi(trim(subStr));

            subStr = tempStr.substr(0, 5);
            tempStr.erase(0, 5);
            temp->m_resolved = stoi(trim(subStr));

            cs_CrimeVect.push_back(temp);
         }
      }
      else {
         throw("Error: wrong filename");
      }
   }

   CrimeStatistics::~CrimeStatistics() {
      for (Crime* var : cs_CrimeVect) {
         delete var; //deletes dynamically allocated Crime objects
       }
   }

   void CrimeStatistics::display(std::ostream& out) const {
      //out.flush();
      size_t numCases = 0;
      size_t numResolved = 0;
      for(auto var:cs_CrimeVect)
      {
         numCases += var->m_caseNum; //total num of cases in cs_CrimeVect
         numResolved += var->m_resolved; //total resolved cases in cs_CrimeVect
         out << *var << endl;
      }

      out << std::setfill('-') << std::setw(88) << '-' << '\n';
      out << "|" << right << setfill(' ') << setw(79) << "Total Crimes: " << setw(6) << numCases << " |" << '\n';
      out << "|" << setw(79) <<"Total Resolved Cases: " << setw(6) << numResolved << " |" << endl;

      return;
   }

   void CrimeStatistics::sort(std::string param) {
      if (param == "Province") {
         std::sort(cs_CrimeVect.begin(), cs_CrimeVect.end(), [](auto& lhs, auto& rhs) { return lhs->m_province
            < rhs->m_province; }); //sorting by province
      }
      else if (param == "Crime")
      {
         std::sort(cs_CrimeVect.begin(), cs_CrimeVect.end(), [](auto& lhs, auto& rhs) { return lhs->m_crime
            < rhs->m_crime;}); //sorting by crime name
      }
      else if (param == "Cases") {
         std::sort(cs_CrimeVect.begin(), cs_CrimeVect.end(), [](auto& lhs, auto& rhs) { return lhs->m_caseNum
            < rhs->m_caseNum; }); //sorting by number of cases
      }
      else if (param == "Resolved") {
         std::sort(cs_CrimeVect.begin(), cs_CrimeVect.end(), [](auto& lhs, auto& rhs) { return lhs->m_resolved
            < rhs->m_resolved; }); //sorting by number of resolved cases
      }
   }
   void CrimeStatistics::cleanList() {
      //replaces "[None]" keyword as crime name by "".
      std::transform(cs_CrimeVect.begin(), cs_CrimeVect.end(), cs_CrimeVect.begin(), [](auto& crimeObj) {
         if (crimeObj->m_crime == "[None]") {
            crimeObj->m_crime.replace(0, 6, "");
         }
         return crimeObj;
      });
   }
   bool CrimeStatistics::inCollection(std::string cName) const {
      //returns true of any object in cs_CrimeVect contains crime name same as cName
      return any_of(cs_CrimeVect.begin(), cs_CrimeVect.end(), [cName](auto& crimeObj) {
         if (crimeObj->m_crime == cName)return true;
         return false;
         });
   }

   std::list<Crime> CrimeStatistics::getListForProvince(std::string provName)const {
      list<Crime> crimesByProv;
      for_each(cs_CrimeVect.begin(), cs_CrimeVect.end(), [&crimesByProv, provName](auto& crimeObj) {
         if (crimeObj->m_province == provName) {
            crimesByProv.push_back(*crimeObj);
         }
      });
      return crimesByProv;
   }

   std::ostream& operator << (std::ostream& os, const Crime& crime) {
      os << "| " << setfill(' ') << setw(21) << left << crime.m_province << " | " << setw(15) << crime.m_district << " | " << setw(20) << crime.m_crime << " | " << setw(6) << right << crime.m_year << " | " << setw(4) << crime.m_caseNum << " | " << setw(3) << crime.m_resolved << " |";
      return os;
   }

   std::string trim(std::string& str) {
      str.erase(0, str.find_first_not_of(' '));
      str.erase(str.find_last_not_of(' ')+1);
      return str;
   }
};