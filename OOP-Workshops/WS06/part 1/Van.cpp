#include <string>
#include"Van.h"

using namespace std;
namespace sdds {
   Van::Van(std::istream& is) {
      std::string tempStr;
      std::string tempSub;
      //for (size_t i = 0; !eof(); i++) {

      getline(is, tempStr);
      tempSub = tempStr.substr(0, tempStr.find(',') + 1);
      trim(tempSub);

      getline(is, tempStr);
      tempSub = tempStr.substr(0, tempStr.find(',') + 1);
      v_maker = trim(tempSub);

      getline(is, tempStr);
      tempSub = tempStr.substr(0, tempStr.find(',') + 1);
      v_type = trim(tempSub);

      getline(is, tempStr);
      tempSub = tempStr.substr(0, tempStr.find(',') + 1);
      v_purpose = trim(tempSub);

      getline(is, tempStr);
      tempSub = tempStr.substr(0, tempStr.find(',') + 1);
      v_condition = trim(tempSub);

      getline(is, tempStr);
      tempSub = tempStr.substr(0, tempStr.find(',') + 1);
      v_tSpeed = stod(trim(tempSub));
   }

   std::string Van::condition() const {
      return v_condition;
   }
   double Van::topSpeed()const {
      return v_tSpeed;
   }
   std::string Van::type() const {
      return v_type;
   }
   std::string Van::usage() const {
      return v_purpose;
   }
   void Van::display(std::ostream& out) const {
      cout << "trial" << endl;
   }

   /*std::string trim(string& str) {
      str.erase(str.find_last_not_of(' ') + 1);
      str.erase(0, str.find_first_not_of(' ') + 1);
      return str;
   }*/
}