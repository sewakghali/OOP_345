#include"Dictionary.h"
using namespace std;
namespace sdds {
   /*std::string m_term{};
   std::string m_definition{};*/
   
   const string& Dictionary::getTerm() const { return m_term; }
   const string& Dictionary::getDefinition() const { return m_definition; }
   Dictionary::Dictionary(const string& term, const string& definition) : m_term{ term }, m_definition{ definition } {}

   // TODO: Code the missing prototype functions and operators
   //       that the class needs in order to work with the Queue class.
   //       Implement them in the Dictionary.cpp file.
}