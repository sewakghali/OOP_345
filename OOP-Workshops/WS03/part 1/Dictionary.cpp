#include"Dictionary.h"
using namespace std;
namespace sdds {
   /*std::string m_term{};
   std::string m_definition{};*/
   
   const string& Dictionary::getTerm() const { return m_term; }
   const string& Dictionary::getDefinition() const { return m_definition; }
   Dictionary::Dictionary(const string& term, const string& definition) : m_term{ term }, m_definition{ definition } {}

   Dictionary::Dictionary() {}

   Dictionary& Dictionary::operator=(const Dictionary& ogDict) {
      m_term = ogDict.getTerm();
      m_definition = ogDict.getDefinition();
   }

   std::ostream& operator <<(std::ostream& os, Dictionary& dict) {
      os << dict.getTerm() << ": " << dict.getDefinition() << endl;
   };
}