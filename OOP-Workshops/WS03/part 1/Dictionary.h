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
      Dictionary();
      Dictionary& operator=(const Dictionary&);
   };
   std::ostream& operator <<(std::ostream&, Dictionary&);
}