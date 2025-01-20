#include "Week2_Date.h"
namespace Week_2
{
	Week2_Date::Week2_Date(int year = 2025, int month = 1, int day = 1)
	{
		std::cout << "Parameterized  Constructor for Week2_Date Called!!\n";

		_year = year;
		_month = month;
		_day = day;
	}

	Week2_Date::Week2_Date()
	{
		std::cout << "Default Constructor for Week2_Date Called!!";
		_year = 2025;
		_month = 1;
		_day = 1;
	}

	Week2_Date::~Week2_Date()
	{
		std::cout << "Destructor for Week2_Date Called!!\n";
	}

	Week2_Date Week2_Date::operator+(Week2_Date const& date)
	{
		Week2_Date new_date = Week2_Date(_year + date._year, _month + date._month, _day + date._day);
		new_date.normalize();

		return new_date;
	}

	Week2_Date Week2_Date::operator+(int days)
	{
		Week2_Date new_date = Week2_Date(_year, _month, _day + days);
		new_date.normalize();

		return new_date;
	}

	void Week2_Date::normalize()
	{
		int total_days = _day;
		int actual_day = total_days % 30 == 0 ? 30 : total_days % 30;

		int total_months = _month;
		int month_carry_over = total_days == 30 ? 0 : int(total_days / 30);
		int actual_month = (total_months + month_carry_over) % 12 == 0 ? 12 : (total_months + month_carry_over) % 12;

		int year_carry_over = (total_months + month_carry_over) == 12 ? 0 : int((total_months + month_carry_over) / 12);
		int total_years = _year + year_carry_over;

		// Boundary Checks
		_year = total_years < 0 ? 2025 : total_years;
		_month = (actual_month < 1 || actual_month > 12) ? 1 : actual_month;
		_day = (actual_day < 1 || actual_day > 30) ? 1 : actual_day;
	}
}

std::ostream& Week_2::operator<<(std::ostream& os, const Week2_Date& date)
{
	return os << date._year << "-" << date._month << "-" << date._day;
}
