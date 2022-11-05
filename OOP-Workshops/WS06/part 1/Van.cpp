#include <string>
#include<iomanip>
#include"Van.h"

using namespace std;
namespace sdds {
   Van::Van(std::istream& is) {
      std::string tempStr;
      std::string tempSub;

      getline(is, tempStr);
      tempSub = tempStr.substr(0, tempStr.find(','));
      tempStr.erase(0, tempStr.find(',') + 1);
      trim(tempSub);

      tempSub = tempStr.substr(0, tempStr.find(','));
      tempStr.erase(0, tempStr.find(',') + 1);
      v_maker = trim(tempSub);

      tempSub = tempStr.substr(0, tempStr.find(','));
      tempStr.erase(0, tempStr.find(',') + 1);
      v_type = trim(tempSub);

      tempSub = tempStr.substr(0, tempStr.find(','));
      tempStr.erase(0, tempStr.find(',') + 1);
      v_purpose = trim(tempSub);

      tempSub = tempStr.substr(0, tempStr.find(','));
      tempStr.erase(0, tempStr.find(',') + 1);
      v_condition = trim(tempSub);

      v_tSpeed = stod(trim(tempStr));
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
      out << "| " << setw(8) << setfill(' ') << v_maker << " | " << setw(12) << v_type << " | " << setw(12) << setfill(' ') << v_purpose << " | " << setw(6) << setfill(' ') << v_condition << " | " << setw(6) << fixed << setprecision(2) << v_tSpeed << " |" << endl;
      return;
   }

   /*std::string trim(string& str) {
      str.erase(str.find_last_not_of(' ') + 1);
      str.erase(0, str.find_first_not_of(' ') + 1);
      return str;
   }*/
}