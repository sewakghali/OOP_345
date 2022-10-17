#include<fstream>
#include<string>
#include"SpellChecker.h"
#include"Book.h"
using namespace std;
namespace sdds {
   SpellChecker::SpellChecker(const char* filename) {
      ifstream is(filename);
      if (is.good()) {
         string temp = "";
         int i = 0;
         do {
            getline(is, temp);
            if (temp != "") {
               trim(temp);
               m_badWords[i] = temp.substr(0,temp.find(" "));
               temp.erase(0, temp.find(" ") + 1);

               m_goodWords[i] = trim(temp);
               m_numReplaced[i] = 0;
               i++;
            }
         } while (!is.eof() && i < 6);
      }
      else {
         throw "Bad file name!";
      }
   }

   void SpellChecker::operator()(std::string& text) {
      for (int i = 0; i < 6; i++) {
         text.replace(text.find(m_badWords[i], 0), m_badWords[i].length(), m_goodWords[i]);
         m_numReplaced[i]++;
      }
   }
   
   void SpellChecker::showStatistics(std::ostream& out) const {
      out << "1";
   }
}