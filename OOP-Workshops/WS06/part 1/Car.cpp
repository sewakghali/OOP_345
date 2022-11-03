#include<iostream>
#include<string>
#include<algorithm>
#include"Car.h"

using namespace std;

namespace sdds {
   Car::Car(std::istream& is) {
      std::string tempStr;
      std::string tempSub;
      //for (size_t i = 0; !eof(); i++) {
         
      getline(is, tempStr);
         tempSub = tempStr.substr(0, tempStr.find(',')+1);
         trim(tempSub);

         getline(is, tempStr);
         tempSub = tempStr.substr(0, tempStr.find(',')+1);
         c_maker = trim(tempSub);

         getline(is, tempStr);
         tempSub = tempStr.substr(0, tempStr.find(',')+1);
         c_cond = trim(tempSub);

         getline(is, tempStr);
         tempSub = tempStr.substr(0, tempStr.find(',')+1);
         c_tSpeed = stod(trim(tempSub));
      //}
   }

   std::string Car::condition() const {
      return c_cond;
   }

   double Car::topSpeed() const {
      return c_tSpeed;
   }

   void Car::display(std::ostream& out) const {
      return;
   }

   std::string trim(std::string& str) {
      str.erase(str.find_last_not_of(' ') + 1);
      str.erase(0, str.find_first_not_of(' ') + 1);
      return str;
   }
}