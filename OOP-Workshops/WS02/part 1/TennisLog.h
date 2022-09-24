#pragma once

#include<iostream>
#include<string>

namespace sdds {
   typedef struct{
      int matchId{0};
      std::string tournamentID{};
      std::string tournamentName{};
      std::string winner{};
      std::string loser{};
   } TennisMatch;

   TennisMatch& operator=(TennisMatch& oldObj);
   std::ostream& operator << (std::ostream& os, TennisMatch& tm);

   class TennisLog{
      TennisMatch* match_arr{};
      int matchNum;
public:
   TennisLog();
   TennisLog(const char*);
   //TennisLog()

   void addMatch(TennisMatch&);
   TennisLog& findMatches(const char*);
   TennisMatch& operator[](size_t);
   TennisLog& operator size_t();
   };
}