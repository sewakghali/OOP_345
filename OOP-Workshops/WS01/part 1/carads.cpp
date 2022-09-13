 #include <iomanip>
#include "carads.h"
using namespace std;
namespace sdds {
	Cars::Cars() {
		car_Brand[0] = '\0';
		car_model[0] = '\0';
		car_year = 0;
		car_price = 0;
		car_status = 'N';
		car_promotion = false;
	}

	void Cars::read(std::istream& is) {
		if (is.good()) {
			is >> car_status;
			is.ignore();
			is >> car_Brand;
			is.ignore();
			is >> car_model;
			is.ignore();
			is >> car_year;
			is.ignore();
			is >> car_price;
			is >> car_promotion;
		}
	}

	void Cars::display(bool reset) {
		static int counter = 0;
		if (reset) {
			 counter = 0;
			cout << "COUNTER. No Car" << endl;
		}
		else {
			counter++;
			cout << "COUNTER. Brand     | Model          | Year |Price w/Tax |Special Price" << endl;
			cout << left << setw(2) << counter << left << setw(10) << car_Brand << left << setw(15) << car_model << car_year << left << setw(14) << setprecision(2) << car_price << endl;
		}
	}

	char Cars::getStatus() {
		 return car_status;
	}
}