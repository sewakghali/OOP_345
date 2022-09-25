#include<iomanip>
#include<fstream>
#include<cstring>
#include "TennisLog.h"

using namespace std;
namespace sdds {
   TennisMatch::TennisMatch() {
      matchId = 0;
      tournamentID = "\0";
      tournamentName = "\0";
      winner = "\0";
      loser = "\0";
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

   /*TennisMatch::operator bool()const {
      if(this.)
   }*/

   ostream& operator << (ostream& os, TennisMatch& tm) {
      //std::cout << "extraction overload begins" << std::endl;
      TennisMatch* ptr = &tm;
      if (ptr) {
         //os << "adress = " << &ptr << endl;
         os << "Tourney ID : " << tm.tournamentID << endl;
         os << "Match ID : " << tm.matchId << endl;
         os << "Tourney : " << tm.tournamentName << endl;
         os << "Winner : " << tm.winner << endl;
         os << "Loser : " << tm.loser << endl;
      }
      else {
         os << "Empty Match";
      }
      //std::cout << "extraction overload ends" << std::endl;

      return os;
   }

   TennisLog::TennisLog() {
      TennisMatch* match_arr{ nullptr };
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

      cout << "adding recs begins" << endl;

      match_arr = new TennisMatch[count];
      getline(infile, temp);
      for (int i = 0; i < count - 1; i++) {
         getline(infile, match_arr[i].tournamentID, ',');
         getline(infile, match_arr[i].tournamentName, ',');
         infile >> match_arr[i].matchId;
         infile.ignore(1, ',');
         getline(infile, match_arr[i].winner, ',');
         getline(infile, match_arr[i].loser);
         //infile.ignore(1, '\n');
      }

      cout << "adding recs ends" << endl;

      matchNum = count;
   }

   void TennisLog::addMatch(TennisMatch& matchObj) {
      TennisMatch* tempObj{};
      if (matchNum > 0) {
         tempObj = new TennisMatch[matchNum];
      }
      else {

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
      TennisLog tempObj;
      string playerName = string(player);
      for (int i = 0; i < matchNum; i++) {
         if (playerName == match_arr[i].loser || playerName == match_arr[i].winner) {
            tempObj.addMatch(match_arr[i]);
         }
      }
      return tempObj;
   }
   TennisMatch& TennisLog::operator[](size_t arrIndex) {
      if (arrIndex > matchNum) {
         return match_arr[0];
      }
      return match_arr[arrIndex];
   }
   TennisLog::operator size_t() {
      return matchNum;
   }
}