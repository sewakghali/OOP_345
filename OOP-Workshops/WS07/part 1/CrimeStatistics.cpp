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
         throw("wrong fileName");
      }
   }

   void CrimeStatistics::display(std::ostream& out) const {
      size_t numCases = 0;
      size_t numResolved = 0;
      for (Crime* var : cs_CrimeVect)
      {
         numCases += var->m_caseNum;
         numResolved += var->m_resolved;
         out << *var;
      }
      out << "Total: " << numCases << endl;
      out << "Resolved: " << numResolved << endl;
   }
   std::ostream& operator << (std::ostream& os, const Crime& crime) {
      os << "| " << setfill(' ') << setw(21) << left << crime.m_province << " | " << setw(15) << left << crime.m_district << " | " << setw(20) << left << crime.m_crime << " | " << setw(6) << right << crime.m_year << " | "  <<setw(4) << right << crime.m_caseNum << " | " << setw(3) << left << crime.m_resolved << " | " << endl;
   }

   std::string trim(std::string& str) {
      str.erase(0, str.find_first_not_of(' '));
      str.erase(str.find_last_not_of(' ')+1);
      return str;
   }
};