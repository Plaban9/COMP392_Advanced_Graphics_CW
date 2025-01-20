#include <iostream>
#include "Week2_Date.h"

int main()
{
	std::cout << "\n--------------------- Testing Date ---------------------";

	std::cout << "\nCreating an anonymous object - 1\n";
	std::cout << Week_2::Week2_Date(2025, 12, 1) << '\n';

	std::cout << "\nCreating a named object - 2\n";
	Week_2::Week2_Date d1(2020, 3, 28);
	std::cout << d1 << '\n';

	std::cout << "\nCreating another named object - 3\n";
	Week_2::Week2_Date d2(2, 10, 14);
	std::cout << d2 << '\n';

	std::cout << "\nCreating another named object - 4\n";
	Week_2::Week2_Date d3 = d1 + d2;
	std::cout << d1 << " + " << d2 << " = " << d3 << '\n';
	int days = 84;

	//Setting a new object to d3
	std::cout << "\nSetting a new object to an existing variable:\n";
	d3 = d2 + days;
	std::cout << d2 << " + " << days << " = " << d3 << '\n';

	std::cout << d1 << '\n';
	std::cout << d2 << '\n';
	std::cout << d3 << '\n';

	return 1;
}