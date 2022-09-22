#pragma once

#include<iostream>

namespace sdds {
   Typedef Struct{
      int matchId;
      string tournamentID;
      string tournamentName;
      string winner;
      string loser;
   } TennisMatch;
   std::ostream& operator << (std::ostream& os, TennisMatch& tm);

   Class TennisLog{
public:
   TennisLog();
   TennisLog(char*);
   //TennisLog()

   void addMatch(TennisMatch&);
   TennisLog& findMatch(char*);
   TennisLog& operator[](size_t);
   TennisLog& operator size_t();
   };
}