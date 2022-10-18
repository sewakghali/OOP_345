/******************************************************************
Module: SpellChecker.cpp
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: October 17, 2022
******************************************************************/

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
         //loops through all the elements of string to check more than one occurences of same bad word
         for (size_t j = 0; j < text.length(); j++) {
            size_t index = text.find(m_badWords[i], j);

            //if the index of bad word is found, it replaces the badword by good word at the specified index
            if (index < text.length() && index >= 0) {
               text.replace(index, m_badWords[i].length(), m_goodWords[i]);
               m_numReplaced[i]++;

               //now since there is no possibility of a bad word being in the place of the good word that we inserted just now, we set the index of the loop to the end of the good word that we just inserted.
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