#include<string>
#include"Station.h"
using namespace std;
namespace sdds {
   Station::Station(const std::string&);
   const std::string& Station::getItemName() const;
   size_t Station::getNextSerialNumber() {

   }
   size_t Station::getQuantity() const {
      return sStockCnt;
   }
   void Station::updateQuantity() {
      sStockCnt--;
      return;
   }
   void Station::display(std::ostream& os, bool full) const;
}