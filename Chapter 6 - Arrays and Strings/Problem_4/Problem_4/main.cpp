/*
   Write two conversion routines. The first routine converts a 
   string to a signed integer. You may assume that the string only 
   contains digits and the minus character ('-'), that it is a 
   properly formatted integer number, and that the number is within 
   the range of an int type. The second routine converts a signed 
   integer stored as an int back to a string.
*/

#include <iostream>
#include <string>

using namespace std;

// Absolute value.
#define abs(val) ((val >= 0) ? val : -val)
// Number base.
#define	RADIX 10

// String to integer conversion.
int Atoi(std::string str)
{
	int num = 0, sign = 1;
	std::size_t i = 0;

	if (str[i] == '-')
	{
		i++;
		sign = -1;
	}

	for (; i < str.size(); i++)
		num = num * 10 + str[i] - '0';

	return num * sign;
}

// Character length of integer.
std::size_t nbrlen(int input)
{
	std::size_t i = 1;

	if (input < 0)
		++i;
	while (input /= RADIX)
		++i;

	return i;
}

// Integer to string conversion.
void Itoa(int input, std::string& buffer)
{
	int num = input;
	// Special case of zero.
	buffer[0] = '0';

	// Determine character count.
	std::size_t i = 0;
	if (input < 0)
		++i;
	while (input /= RADIX)
		++i;
	buffer.resize(i + 1);

	// If negative.
	if (num < 0)
		buffer[0] = '-';

	// Iterate integer building string.
	while (num)
	{
		buffer[i--] = '0' + abs(num) % RADIX;
		num /= RADIX;
	}
}

int main()
{
	std::string str("-12345");
	cout << Atoi(str) << endl;
	str = "1";
	cout << Atoi(str) << endl;
	str = "-1";
	cout << Atoi(str) << endl;
	str = "0";
	cout << Atoi(str) << endl;
	str = "-0";
	cout << Atoi(str) << endl;

	std::string buffer;
	Itoa(-12345, buffer);
	cout << buffer << endl;
	Itoa(1, buffer);
	cout << buffer << endl;
	Itoa(-1, buffer);
	cout << buffer << endl;
	Itoa(0, buffer);
	cout << buffer << endl;
	Itoa(-0, buffer);
	cout << buffer << endl;
}

/*
#include <sstream>

int main()
{
	int i = -123;
	std::string s;
	std::stringstream out;
	out << i;
	s = out.str();
	std::cout << s << endl;
}
*/

