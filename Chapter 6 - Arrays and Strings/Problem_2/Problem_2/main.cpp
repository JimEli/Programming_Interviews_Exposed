/*
   Write an efficient fuction that deletes characters from a string. 
   Use the prototype:

   std::string removeChars( std::string str, std::string remove );

   where any character existing in remove must be deleted from str. 
   For example, given a str of "Battle of the Vowels: Hawaii vs. Grozny" 
   and a remove of "aeiou", the function should transform str to 
   "Bttl f th Vwls: Hw vs. Grzny".  Justify any design decisions you 
   make and discuss the efficiency of your solution.
*/

#include <iostream>
#include <algorithm>
#include <string>

// Size of character table.
constexpr int TABLE_SIZE{ 256 };

int main()
{
	// Source and removal character strings.
	std::string s("Now is the time for all good men to come to the aid of their country.");
	std::string r("aeiou");
	// Character removal table.
	bool cTable[TABLE_SIZE] = { false };

	// Build table.
	for (auto c : r)
		cTable[c] = true;

	// Scan/remove characters.
	std::size_t dst = 0;
	std::for_each(s.begin(), s.end(), [&](int c) { if (!cTable[c]) s[dst++] = c; });

	// Resize string.
	s.resize(dst);

	// Display results.
	std::cout << s << std::endl;
}
