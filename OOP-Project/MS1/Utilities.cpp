#include<string>
#include"Utilities.h"
using namespace std;
namespace sdds {
   void Utilities::setFieldWidth(size_t newWidth) {
      m_widthField = newWidth;
      return;
   }
   size_t Utilities::getFieldWidth() const {
      return m_fieldWidth;
   }
   std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {

   }
   static void Utilities::setDelimiter(char newDelimiter) {
      m_delimiter = newDelimiter;
      return;
   }
   static char Utilities::getDelimiter() {
      return m_delimiter;
   }
}