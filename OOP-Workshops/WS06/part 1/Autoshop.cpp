//#include<algorithm>
#include"Autoshop.h"

using namespace std;
namespace sdds {
   Autoshop& Autoshop::operator +=(Vehicle* theVehicle) {
      m_vehicles.push_back(theVehicle);
   }
   void Autoshop::display(std::ostream& out) {
      for (vector<Vehicle*>::iterator i = m_vehicles.begin(); i < m_vehicles.end(); i++)
         //{
        (*i)->display(out);
      //}
   }
}