#include"Utilities.h"
#include"Car.h"
#include"Van.h"
using namespace std;

namespace sdds {
   Vehicle* createInstance(std::istream& in) {
      std::string tempStr;
      std::string tempSub;
      getline(in, tempStr);
      tempSub = tempStr.substr(0, tempStr.find(',') + 1);
      tempSub = trim(tempSub);
      Vehicle* instance=nullptr;
      if (tempSub[0] == 'c' || tempSub[0] == 'C') {
         instance = new Car(in);
      }
      else if (tempSub[0] == 'v' || tempSub[0] == 'V') {
         instance = new Van(in);
      }
      return nullptr;
   }

   /*std::string trim(std::string& str) {
      str.erase(str.find_last_not_of(' ') + 1);
      str.erase(0, str.find_first_not_of(' ') + 1);
      return str;
   }*/
}