/*****************************************************************
Module: WritingRecord.cpp
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: November 21, 2022
******************************************************************/
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
					}
					catch (string msg) {
						delete ewage;
						throw msg;
					}
					delete ewage;
				}
			}
		}
		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using smart pointers
		bool found = false;
		for (size_t i = 0; i < emp.size(); i++) {
			//found = false;
			for (size_t j = 0; j < sal.size(); j++) {
				found = false;
				if (emp[i].id == sal[j].id) {
					found = true;
				}

				if (found == true) {
					std::unique_ptr<EmployeeWage> ewage(new EmployeeWage(emp[i].name, sal[j].salary));
					try {
						ewage->rangeValidator();
						if (activeEmp.checkSin(emp[i].id)) {
							activeEmp += *ewage;
						}
					}
					catch (string msg) {
						throw msg;
					}

				}
			}
		}
		return activeEmp;
	}
}