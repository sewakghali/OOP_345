#include<fstream>
#include<iomanip>
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
         for (int j = 0; j < text.length(); j++) {
            size_t index = text.find(m_badWords[i], j);
            if (index < text.length() && index >= 0) {
               text.replace(index, m_badWords[i].length(), m_goodWords[i]);
               m_numReplaced[i]++;
               j = index- m_badWords[i].length()+m_goodWords[i].length();
            }
         }
      }
      return;
   }
   
   void SpellChecker::showStatistics(std::ostream& out) const {
      cout << "Spellchecker Statistics" << endl;
      for (int i = 0; i < 6; i++) {
         out << setw(15) << right << setfill(' ') << m_badWords[i] << ": " << left << m_numReplaced[i] << " replacements" << endl;
      }
   }
}