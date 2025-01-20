#include <iostream>

namespace Week_2
{
	class Week2_Date
	{
	private:
		int _year;
		int _month;
		int _day;

	public:
		Week2_Date();
		Week2_Date(int year, int month, int day);
		~Week2_Date();
		Week2_Date operator+ (Week2_Date const& date);
		Week2_Date operator+ (int days);
		friend std::ostream& operator<<(std::ostream& os, const Week2_Date&);
		void normalize();
	};
}

