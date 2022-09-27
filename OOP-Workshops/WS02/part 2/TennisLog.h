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

      //default constructor
      TennisMatch();

      //custom constructor
      TennisMatch(const char* tID, const char* tName, int mId, const char* mWinner, const char* mLoser);
      
      //copy assignment operator
      TennisMatch& operator=(const TennisMatch& oldObj);
      
      //returns if TennisMatch object is valid
      operator bool() const;
   }TennisMatch;

   //extraction operator overlaod for TennisMatch
   std::ostream& operator << (std::ostream& os, TennisMatch& tm);


   class TennisLog{
      TennisMatch* match_arr{}; //stores the dynamic array of TennisMatch objects
      int matchNum; //number of TennisMatch objects in match_arr
public:
   TennisLog(); //default constructor
   TennisLog(const char*); //custom constructor
   TennisLog(TennisLog&); //copy constructor
   TennisLog(TennisLog&&); //move constructor
   TennisLog& operator = (TennisLog&); //copy assignment operator
   TennisLog& operator = (TennisLog&&); //move assignment operator
   ~TennisLog(); //destructor

   void addMatch(TennisMatch&); //appends a TennisMatch object to the match_arr
   TennisLog& findMatches(const char*); //returns tennisLog object consisting of TennisMatch objects in which the argument matches the loser or the winner name
   TennisMatch& operator[](size_t); //returns the TennisMatch object from the match_arr from the index specified in the argument
   operator size_t(); //returns the matchNum member variable
   };
}