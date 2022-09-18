#ifndef SDDS_CARADS_H
#define SDDS_CARADS_H

#include <iostream>

extern double g_taxrate;
extern double g_discount;

namespace sdds {
	 int listArgs(int argc, char* argv[]);

	class Cars {
		double car_price{};
		int car_year{};
		bool car_promotion{};
		char car_status{};
		char* car_Brand{};
		char car_model[15]{};

	public:
		Cars();
		Cars(Cars&);
		~Cars();
		Cars& operator = (Cars&);

		std::istream& read(std::istream& is);
		void display(bool reset);
		char getStatus();

		operator bool() const;
	};

	double taxedval(double val);
	std::istream& operator>>(std::istream& is, Cars& car);
	void operator>>( Cars& car1, Cars& car2);
}

#endif
