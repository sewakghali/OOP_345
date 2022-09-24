#pragma once

#include<iostream>

namespace sdds {
   typedef struct{
      int matchId{0};
      std::string tournamentID{};
      std::string tournamentName{};
      std::string winner{};
      std::string loser{};

      TennisMatch& operator =(TennisMatch&);
   } TennisMatch;

   std::ostream& operator << (std::ostream& os, TennisMatch& tm);

   class TennisLog{
      TennisMatch* match_arr{};
      int matchNum;
public:
   TennisLog();
   TennisLog(const char*);
   //TennisLog()

   void addMatch(TennisMatch&);
   TennisLog& findMatch(const char*);
   TennisLog& operator[](size_t);
   TennisLog& operator size_t();
   };
}