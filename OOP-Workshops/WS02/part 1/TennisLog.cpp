#include<iomanip>
#include<fstream>
#include<cstring>
#include "TennisLog.h"

using namespace std;
namespace sdds {
   TennisMatch::TennisMatch() {
      matchId = 0;
      tournamentID = "";
      tournamentName = "";
      winner = "";
      loser = "";
   }
   TennisMatch::TennisMatch(const char* tID, const char* tName, int mId, const char* mWinner, const char* mLoser) {
      this->matchId = mId;
      this->tournamentID = string(tID);
      this->tournamentName = string(tName);
      this->winner = string(mWinner);
      this->loser = string(mLoser);
   }

   inline TennisMatch& TennisMatch::operator=(const TennisMatch& oldObj) {
      this->matchId = oldObj.matchId;
      this->tournamentID = oldObj.tournamentID;
      this->tournamentName = oldObj.tournamentName;
      this->winner = oldObj.winner;
      this->loser = oldObj.loser;

      return *this;
   }

   ostream& operator << (ostream& os, TennisMatch& tm) {
      TennisMatch* ptr = &tm;
      if (ptr) {
         os << right << setw(20) << setfill('.') << "Tourney ID" << " : " << left << setw(30) << tm.tournamentID << endl;
         os << right << setw(20) << setfill('.') << "Match ID" << " : " << left << setw(30) << tm.matchId << endl;
         os << right << setw(20) << setfill('.') << "Tourney" << " : " << left << setw(30) << tm.tournamentName << endl;
         os << right << setw(20) << setfill('.') << "Winner" << " : " << left << setw(30) << tm.winner << endl;
         os << right << setw(20) << setfill('.') << "Loser" << " : " << left << setw(30) << tm.loser << endl;
      }
      else {
         os << "Empty Match";
      }
      return os;
   }

   TennisLog::TennisLog() {
      match_arr = { nullptr };
      matchNum = 0;
   }

   TennisLog::TennisLog(const char* fname) {
      ifstream infile(fname);
      int count = 0;
      string temp;
      while (!infile.eof()) {
         getline(infile, temp);
         count++;
      }
      infile.clear();
      infile.seekg(0);

      match_arr = new TennisMatch[count];
      getline(infile, temp);
      for (int i = 0; i < count - 1; i++) {
         getline(infile, match_arr[i].tournamentID, ',');
         getline(infile, match_arr[i].tournamentName, ',');
         infile >> match_arr[i].matchId;
         infile.ignore(1, ',');
         getline(infile, match_arr[i].winner, ',');
         getline(infile, match_arr[i].loser);
      }
      matchNum = count;
   }

   TennisLog::TennisLog(TennisLog& ogLog) {
      *this = ogLog;
   }

   TennisLog::TennisLog(TennisLog&& ogLog) {
      *this = ogLog;
   }

   TennisLog& TennisLog::operator = (TennisLog&& ogLog) {
      if (matchNum > 0) {
         delete[] match_arr;
         match_arr = nullptr;
      }

      match_arr = new TennisMatch[ogLog.matchNum];
      for (int i = 0; i < ogLog.matchNum; i++) {
         match_arr[i] = ogLog.match_arr[i];
      }

      matchNum = ogLog.matchNum;
      return *this;
   }

   TennisLog::~TennisLog() {
      delete[] match_arr;
   }

   TennisLog& TennisLog::operator = (TennisLog& ogLog) {
      if(matchNum > 0) {
         delete[] match_arr;
         match_arr = nullptr;
      }

      match_arr = new TennisMatch[ogLog.matchNum];
      for (int i = 0; i < ogLog.matchNum; i++) {
         match_arr[i] = ogLog.match_arr[i];
      }

      matchNum = ogLog.matchNum;
      return *this;
   }

   void TennisLog::addMatch(TennisMatch& matchObj) {
      TennisMatch* tempObj{};
      if (matchNum > 0) {
         tempObj = new TennisMatch[matchNum];
      }
      for (int i = 0; i < matchNum; i++) {
         tempObj[i] = this->match_arr[i];
      }
      delete[] match_arr;
      matchNum++;
      match_arr = new TennisMatch[matchNum];

      for (int i = 0; i < matchNum - 1; i++) {
         match_arr[i] = tempObj[i];
      }
      match_arr[matchNum - 1] = matchObj;

      delete[] tempObj;
   }

   TennisLog& TennisLog::findMatches(const char* player) {
      static TennisLog tempObj;
      tempObj = {};
      string playerName = string(player);
      for (int i = 0; i < matchNum; i++) {
         if (playerName == match_arr[i].loser || playerName == match_arr[i].winner) {
            tempObj.addMatch(match_arr[i]);
         }
      }
      return tempObj;
   }
   TennisMatch& TennisLog::operator[](size_t arrIndex) {
      if (arrIndex > size_t(matchNum)) {
         return match_arr[0];
      }
      return match_arr[arrIndex];
   }
   TennisLog::operator size_t() {
      return matchNum;
   }
}