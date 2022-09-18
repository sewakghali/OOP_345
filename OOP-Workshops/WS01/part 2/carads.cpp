 #include <iomanip>
#include "carads.h"

using namespace std;
namespace sdds {
	int listArgs(int argc, char* argv[]) {
		 cout << "Command Line:" << endl;
		 cout << "--------------------------" << endl;
		 for (int i = 0; i < argc; i++) {
			  cout << right << setw(2) << i + 1 << ": " << left << argv[i] << endl;
		 }
		 cout << "--------------------------" << endl;
	}

	Cars::Cars() {
		car_Brand[0] = '\0';
		car_model[0] = '\0';
		car_year = 0;
		car_price = 0;
		car_status = 'N';
		car_promotion = false;
	}

	void Cars::read(istream& is) {
		if(is.good()) {
			is >> car_status;
			is.ignore();
			is.get(car_Brand, 9, ',');
			is.ignore();
			is.get(car_model, 14, ',');
			is.ignore();
			is >> car_year;
			is.ignore();
			is >> car_price;
			is.ignore();
			char temp;
			is >> temp;
			if (temp == 'Y') {
				car_promotion = true;
			}else{
				car_promotion = false;
			}
		}
	}

	void Cars::display(bool reset) {
		static int counter = 0;
		if (car_Brand[0] == '\0') {
			 counter = 0;
			cout << "COUNTER. No Car" << endl;
		}
		else 
		{
			counter++;
			//cout << "COUNTER. Brand     | Model          | Year |Price w/Tax |Special Price" << endl;
			cout << setw(2) << left  << counter << ". " << setw(10) << left << car_Brand << "| " << left << setw(15) << car_model << "| " << car_year << " | " << fixed << setw(14) << setprecision(2) << car_price << "|";

			if (car_promotion) {
				 cout << fixed << right << setw(12) << setprecision(2) << (g_discount) ;
			}
			cout << endl;
		}
	}

	char Cars::getStatus() {
		 return car_status;
	}
}