/******************************************************************
Module: TennisLog.h
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: September 25, 2022
******************************************************************/


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
   TennisLog(TennisLog&);
   TennisLog(TennisLog&&);
   TennisLog& operator = (TennisLog&);
   TennisLog& operator = (TennisLog&&);
   ~TennisLog();

   void addMatch(TennisMatch&);
   TennisLog& findMatches(const char*);
   TennisMatch& operator[](size_t);
   operator size_t();
   };
}