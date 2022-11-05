#include<sstream>
#include"Utilities.h"
#include"Car.h"
#include"Van.h"
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
      }
      return instance;
   }

   /*std::string trim(std::string& str) {
      str.erase(str.find_last_not_of(' ') + 1);
      str.erase(0, str.find_first_not_of(' ') + 1);
      return str;
   }*/
}