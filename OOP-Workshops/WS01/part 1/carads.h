#ifndef SDDS_CARADS_H
#define SDDS_CARADS_H

#include <iostream>
using namespace std;

extern double g_taxrate;
extern double g_discount;

namespace sdds {
	int listArgs(int argc, char* argv[]){}

	class Cars {
		char car_Brand[10]{};
		char car_model[15]{};
		int car_year{};
		double car_price{};
		char car_status{};
		bool car_promotion{};

	public:
		Cars();
		void read(std::istream& is);
		void display(bool reset);
		char getStatus();
	};
}

#endif
