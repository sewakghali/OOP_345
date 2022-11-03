//#include<algorithm>
#include"Autoshop.h"

using namespace std;
namespace sdds {
   Autoshop& Autoshop::operator +=(Vehicle* theVehicle) {
      m_vehicles.push_back(theVehicle);
   }
   void Autoshop::display(std::ostream& out) {
      for (size_t i =0; i< m_vehicles.size(); i++)
      //{
      cout << m_vehicles[i] << endl;
      //}
   }
}