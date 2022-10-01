#pragma once

#include <iostream>

namespace sdds {
   class Dictionary
   {
      std::string m_term{};
      std::string m_definition{};
   public:
      const std::string& getTerm() const;
      const std::string& getDefinition() const;
      Dictionary(const std::string& term, const std::string& definition);

      // TODO: Code the missing prototype functions and operators
      //       that the class needs in order to work with the Queue class.
      //       Implement them in the Dictionary.cpp file.
   };
}