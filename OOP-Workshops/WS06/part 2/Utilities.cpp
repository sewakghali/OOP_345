#include<sstream>
#include"Utilities.h"
#include"Car.h"
#include"Van.h"
#include"Luxuryvan.h"
#include"Racecar.h"
using namespace std;

namespace sdds {
   Vehicle* createInstance(std::istream& in) {
      std::string tempStr = "";
      std::string tempSub = "";
      getline(in, tempStr);
      std::stringstream ss;
      Vehicle* instance=nullptr;
      if (tempStr != "") {
         tempSub = tempStr.substr(0, tempStr.find(',') + 1);
         //std::cout << "utils trial 1: " << tempStr << std::endl;
         tempSub = trim(tempSub);
         if (tempSub[0] == 'c' || tempSub[0] == 'C') {
            ss << tempStr;
            //cout << "car" << endl;
            instance = new Car(ss);
         }
         else if (tempSub[0] == 'v' || tempSub[0] == 'V') {
            ss << tempStr;
            instance = new Van(ss);
            //cout << "Van" << endl;
         }
         else if (tempSub[0] == 'r' || tempSub[0] == 'R') {
            ss << tempStr;
            instance = new Racecar(ss);
            //cout << "Van" << endl;
         }
         else if (tempSub[0] == 'l' || tempSub[0] == 'L') {
            ss << tempStr;
            instance = new Luxuryvan(ss);
            //cout << "Van" << endl;
         }
         else {
            throw "Records contains unknown vehicle.";
         }
      }
      return instance;
   }

   /*std::string trim(std::string& str) {
      str.erase(str.find_last_not_of(' ') + 1);
      str.erase(0, str.find_first_not_of(' ') + 1);
      return str;
   }*/
}