#include<string>
#include"Movie.h"
#include"Book.h"

using namespace std;
namespace sdds {
   Movie::Movie() {
      m_year = 0;
      m_title = "";
      m_desc = "";
   }

   const std::string& Movie::title() const {
      return m_title;
   }

   Movie::Movie(const std::string& strMovie) {
      string temp = strMovie;
      string tempStr = "";
      tempStr = temp.substr(0, temp.find(','));
      temp.erase(0, temp.find(',') + 1);
      m_title = trim(tempStr);

      tempStr = temp.substr(0, temp.find(','));
      temp.erase(0, temp.find(',') + 1);
      tempStr = trim(tempStr);
      m_year = stoi(tempStr);

      m_desc = trim(temp);
   }
   
   std::ostream& operator << (std::ostream& os, Movie& movie) {
      os << movie.m_title << " " << movie.m_year << " " << movie.m_desc << endl;
      return os;
   }
}