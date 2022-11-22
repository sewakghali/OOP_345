#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		
		// TODO: Add your code here to build a list of employees
		//         using raw pointers

		bool found = false;
		EmployeeWage* ewage = nullptr;

		for (size_t i = 0; i < emp.size(); i++) {
			//found = false;
			for (size_t j = 0; j < sal.size(); j++) {
				found = false;
				if (emp[i].id == sal[j].id) {
					found = true;
				}

				if (found == true) {
					ewage = new EmployeeWage(emp[i].name, sal[j].salary);
					try {
						ewage->rangeValidator();
						if (activeEmp.checkSin(emp[i].id)) {
							activeEmp += *ewage;
						}
						else {
							delete ewage;
						}
					}
					catch (string msg) {
						delete ewage;
						throw msg;
					}
					
				}
			}
		}
		return activeEmp;
	}
}