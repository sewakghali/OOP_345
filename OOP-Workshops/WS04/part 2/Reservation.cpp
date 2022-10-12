#include<iomanip>
#include<algorithm>
#include<string>
#include"Reservation.h"

using namespace std;
namespace sdds {
   Reservation::Reservation() {
      numPeople = 0;
      r_day = 0;
      r_hour = 0;
      r_name = "";
      r_email = "";
      r_id = "";
   }
   Reservation::Reservation(const std::string& res) {
      string temp = res;
      string tempNumStr = "";
      r_id = temp.substr(0, temp.find(':'));
      temp.erase(0, temp.find(':')+1);
      trim(r_id);
      r_name = temp.substr(0, temp.find(','));
      temp.erase(0, temp.find(',')+1);
      trim(r_name);
      r_email = temp.substr(0, temp.find(','));
      temp.erase(0, temp.find(',')+1);
      trim(r_email);

      tempNumStr = temp.substr(0, temp.find(','));
      temp.erase(0, temp.find(',') + 1);
      tempNumStr = trim(tempNumStr);
      numPeople = stoi(tempNumStr);
      tempNumStr = temp.substr(0, temp.find(','));
      temp.erase(0, temp.find(',') + 1);
      tempNumStr = trim(tempNumStr);
      r_day = stoi(tempNumStr);
      tempNumStr = temp.substr(0, temp.find(','));
      temp.erase(0, temp.find(',') + 1);
      tempNumStr = trim(tempNumStr);
      r_hour = stoi(tempNumStr);
   }

   void Reservation::update(int day, int time) {
      r_day = day;
      r_hour = time;
   }
   std::ostream& operator << (std::ostream& os,const Reservation& res) {
      os << "Reservation " << setw(10) << setfill(' ') << right << res.r_id << ": " << setw(20) << res.r_name << setw(26) << left << "  <" + res.r_email + ">  ";
      if( res.r_hour <= 9 && res.r_hour >= 6) {
         os << "Breakfast";
      }
      else if (res.r_hour <= 15 && res.r_hour >= 11) {
         os << "Lunch";
      }
      else if (res.r_hour <= 21 && res.r_hour >= 17) {
         os << "Dinner";
      }
      else {
         os << "Drinks";
      }
      os << " on day " << res.r_day << " @ " << res.r_hour << ":00 for " << res.numPeople;

      if (res.numPeople == 1) {
         os << " person.";
      }
      else {
         os << " people.";
      }
      os << endl;
      return os;
   }

   /*void Reservation::operator =(Reservation& r1, Reservation& r2) {
      r1.numPeople = r2.numPeople;
      r1.r_day = r2.r_day;
      r1.r_hour = r2.r_hour;
      r1.r_email = r2.r_email;
      r1.r_id = r2.r_id;
      r1.r_name = r2.r_name;
   }*/

   inline std::string trim(std::string& str)
   {
      str.erase(str.find_last_not_of(' ') + 1);
      str.erase(0, str.find_first_not_of(' '));
      return str;
   }
}