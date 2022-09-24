#include<iomanip>
#include<fstream>
#include "TennisLog.h"

using namespace std;
namespace sdds {
   TennisMatch& operator =(TennisMatch& oldObj) {
      matchId = oldObj.matchId;
      tournamentID = oldObj.tournamentID;
      tournamentName = oldObj.tournamentName;
      winner = oldObj.winner;
      loser = oldObj.loser;

      return *this;
   }

   ostream& operator << (ostream& os, TennisMatch& tm) {
      if (tm.matchId == 0) {
         os << "Empty Match" << endl;
      }
      else {
         os << "Tourney ID : " << tm.tournamentID << endl;
         os << "Match ID : " << tm.matchId << endl;
         os << "Tourney : " << tm.tournamentName << endl;
         os << "Winner : " << tm.winner << endl;
         os << "Loser : " << tm.loser << endl;
      }
      return os;
   }

   TennisLog::TennisLog() {
      TennisMatch* match_arr{};
   }

   TennisLog::TennisLog(const char* fname) {
      ifstream infile(fname);
      int count = 0;
      string temp;
      while (!infile.EOF()) {
         getline(infile, temp);
         count++;
      }

      match_arr = new TennisMatch[count];
      for (int i = 0; i < count; i++) {
         infile.get(match_arr[i].tournamentID);
         infile.ignore(1, ',');
         infile.get(match_arr[i].tournamentName);
         infile.ignore(1, ',');
         infile >> match_arr[i].match;
         infile.ignore(1, ',');
         infile.get(match_arr[i].winner);
         infile.ignore(1, ',');
         infile.get(match_arr[i].loser);
         infile.ignore(1, ',');
      }

      matchNum = count;
   }

   void TennisLog::addMatch(TennisMatch& matchObj) {
      TennisMatch* tempObj{};
      tempObj = new TennisMatch[matchNum];
      for (int i = 0; i < matchNum; i++) {
         tempObj[i] = match_arr[i];
      }
      delete[] match_arr;
      matchNum++;
      match_arr = new TennisMatch[matchNum];

      for (int i = 0; i < matchNum-1; i++) {
         match_arr[i] = tempObj[i];
      }
      match_arr[matchNum - 1] = matchObj;

      delete[] tempObj;
   }


}