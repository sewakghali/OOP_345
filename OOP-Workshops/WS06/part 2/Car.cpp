//#include<iostream>
#include<string>
#include<algorithm>
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

      tempSub = trim(tempStr);
      std::cout << "topspeed: " << tempStr << endl;
      c_tSpeed = stod(tempSub);
   }

   std::string Car::condition() const {
      return c_cond;
   }

   double Car::topSpeed() const {
      return c_tSpeed;
   }

   void Car::display(std::ostream& out) const {
      //out << c_tSpeed << endl;
      out << "| " << setw(10) << setfill(' ') << c_maker << " | " << setw(6) << c_cond << " | " << fixed << setw(6) << setprecision(2) << c_tSpeed << " |" << endl;
      return;
   }

   std::string trim(std::string& str) {
      str.erase(str.find_last_not_of(' ')+1);
      str.erase(0, str.find_first_not_of(' '));
      return str;
   }
}