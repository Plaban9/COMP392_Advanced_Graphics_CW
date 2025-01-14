#include <iostream>

int main()
{
	std::cout << "Hello World!";

	int a = 0b1010;     //binary literal	   1 * 2^3 + 0 * 2^2 + 1 * 2^1 + 0 * 2^0 
	int b = 012;        //octal literal		   1 * 8^1 + 2 * 8^0
	int c = 10;         //decimal literal
	int d = 0xa;        //hexadecimal literal  a = 10
	int e = 1'000'000;  //with separators
	auto f{ 1.6e-19 };  //double literal in scientific notation

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;

	auto n = "Hel\
						lo";                       //two-lined string

	auto o = u"Hello";     //char16_t
	auto p = U"Hello";     //char32_t
	auto q = L"Hello";     //wchar_t
	auto r = R"(\tHello)"; //raw string

	std::cout << o << std::endl;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;


	return 1;
}