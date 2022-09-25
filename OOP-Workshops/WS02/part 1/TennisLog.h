#pragma once

#include<iostream>
#include<string>

namespace sdds {
   typedef struct TennisMatch{
      int matchId{0};
      std::string tournamentID{};
      std::string tournamentName{};
      std::string winner{};
      std::string loser{};
      TennisMatch();
      TennisMatch(const char* tID, const char* tName, int mId, const char* mWinner, const char* mLoser);
      TennisMatch& operator=(const TennisMatch& oldObj);
      operator bool() const;
   }TennisMatch;
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
   operator size_t();
   };
}