/*
   Implement a function that prints all possible combinations of the
   characters in a string. These combinations range in length from one 
   to the length of the string. Two combinations that differ only in 
   ordering of their characters are the same combination. In other words, 
   “12” and “31” are different combinations from the input string “123”, 
   but “21” is the same as “12”.
*/

#include <iostream>
#include <string>

// Iterative version.
void iPermute(std::string str, std::size_t n = 0)
{
	while (n < str.length())
	{
		for (std::size_t i = n; i < str.length(); i++)
		{
			for (std::size_t j = n; j <= i; j++)
				std::cout << str[j];
			std::cout << std::endl;
		}

		for (std::size_t i = n + 2; i < str.length(); i++)
			std::cout << str[n] << str[i] << std::endl;

		n++;
	}
}

// Recursive version.
void rPermute(std::string str, std::size_t n=0)
{
	if (n < str.length())
	{
		rPermute(str, n + 1);

		for (std::size_t i = n; i < str.length(); i++)
		{
			for (std::size_t j = n; j <= i; j++)
				std::cout << str[j];
			std::cout << std::endl;
		}

		for (std::size_t i = n + 2; i < str.length(); i++)
			std::cout << str[n] << str[i] << std::endl;
	}
}

int main()
{
	// Sample string.
	std::string s("123");
	
	// Iteratvie version.
	iPermute(s);

	std::cout << std::endl;
	// Recursive version.
	rPermute(s);
}