//#include<iostream>
#include<string>
#include<algorithm>
#include<regex>
#include<iomanip>
#include"Car.h"

using namespace std;

namespace sdds {
   Car::Car(std::istream& is) {
      std::string tempStr = "";
      std::string tempSub = "";
         
      getline(is, tempStr);
      tempSub = tempStr.substr(0, tempStr.find(','));
      tempStr.erase(0, tempStr.find(',') + 1);
      tempSub = trim(tempSub);

      tempSub = tempStr.substr(0, tempStr.find(','));
      tempStr.erase(0, tempStr.find(',') + 1);
      c_maker = trim(tempSub);

      tempSub = tempStr.substr(0, tempStr.find(','));
      tempStr.erase(0, tempStr.find(',') + 1);
      c_cond = trim(tempSub);
      if (c_cond == "" ) {
         c_cond = 'n';
      }
      if (!(c_cond == "n" || c_cond == "u" || c_cond == "b")) {
         throw "This record is invalid.";
      }

      /*if (!regex_match(tempSub, regex("[,]"))) {
         tempSub = tempStr.substr(0, tempStr.find(','));
         tempStr.erase(0, tempStr.find(',') + 1);
         tempSub = trim(tempSub);
      }
      else {*/
         tempSub = trim(tempStr);
      //}
      cout << "trial 0: " << trim(tempStr) << endl;

      if (regex_match(trim(tempStr), regex("^[1234567890.,]"))) {
         cout << "temSub 1: " << trim(tempStr) << endl;
         throw "This record is invalid.";
      }
      else {
         cout << "temSub 2: " << tempSub << endl;
         c_tSpeed = stod(trim(tempStr));
      }
      cout << "final: " << tempStr << endl;
   }

   std::string Car::condition() const {
      return c_cond;
   }

   double Car::topSpeed() const {
      return c_tSpeed;
   }

   void Car::display(std::ostream& out) const {
      out << "| " << setw(10) << setfill(' ') << c_maker << " | " << setw(6) << c_cond << " | " << fixed << setw(6) << setprecision(2) << c_tSpeed << " |";
      return;
   }

   std::string trim(std::string& str) {
      str.erase(str.find_last_not_of(' ')+1);
      str.erase(0, str.find_first_not_of(' '));
      return str;
   }
}