//-------------------------------------------
// OOP345 Project- Milestone 3
// Module: LineManager.cpp
// Name: Sewak Singh Gill
// Student Id: 159282219
// Email: sgill116@myseneca.ca
//-------------------------------------------

#include<fstream>
#include<string>
#include<algorithm>
#include"Utilities.h"
#include"LineManager.h"
using namespace std;
namespace sdds {
   LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
      ifstream inFile(file);
      if (inFile) {
         Utilities utilObj;
         bool more = false;
         size_t pos = 0;
         string temp{ "" };
         vector<string> curStatName;
         vector<string> nxtStatName;
         string firstItem{""};
         while (std::getline(inFile, temp))
         {
            pos = 0;
            more = true;
            if (!temp.empty())
            {  
               curStatName.push_back(utilObj.extractToken(temp, pos, more)); //stores names into vector
               nxtStatName.push_back(more ? utilObj.extractToken(temp, pos, more) : ""); //stores names into vector

               //used for aligning the stations' next station
               for_each(stations.begin(), stations.end(), [&](auto& stVal) {
                  if (stVal->getItemName() == curStatName.back()) {
                     if (nxtStatName.back() == "") { stVal->setNextStation(nullptr); }
                     else {
                        for_each(stations.begin(), stations.end(), [&](auto& stVal2) {
                           if (stVal2->getItemName() == nxtStatName.back() && nxtStatName.back() != "") {
                              stVal->setNextStation(stVal2);
                           }
                        });
                     }
                     m_activeLine.push_back(stVal);
                  }
               });

               //used to figure out first station in line
               all_of(curStatName.begin(), curStatName.end(), [&](auto& stObj) {
                  bool found = false;
                 
                  for_each(nxtStatName.begin(), nxtStatName.end(), [&](auto& val) {
                     if (val != "" && stObj == val) {
                        found = true;
                     }
                    
                  });

                  if (found == false) {
                     firstItem = stObj;
                  }
                  return found;
               });
            }
         }

         inFile.close();

        
         for_each(stations.begin(), stations.end(), [&](Workstation* first) {
            if (first->getItemName() == firstItem) {
               m_firstStation = first;
            }
         });
         m_cntCustomerOrder = g_pending.size();
      }
   }

   void LineManager::reorderStations() {
      std::vector<Workstation*> temp;
      Workstation* ws;
      temp.push_back(m_firstStation);
      while ((ws = temp.back()->getNextStation())) temp.push_back(ws);
      m_activeLine.clear();
      m_activeLine = temp;
   }
   
   bool LineManager::run(std::ostream& os) {
      static int i = 0;
      os << "Line Manager Iteration: "<< ++i << endl;
      
      if (!g_pending.empty()) {
         *m_firstStation += std::move(g_pending.front());
         g_pending.pop_front();
      }
      for_each(m_activeLine.begin(), m_activeLine.end(), [&](auto& elem) {
         elem->fill(os);
         });
      for_each(m_activeLine.begin(), m_activeLine.end(), [&](auto& elem) {
         elem->attemptToMoveOrder();
         });
      
      return g_completed.size() + g_incomplete.size() == m_cntCustomerOrder;
   }

   void LineManager::display(std::ostream& os) const {
      for (auto elem : m_activeLine) {
         elem->display(os);
      }
   }
}