/*
  Write an efficient function to find the first nonrepeated character 
  in a string. For instance, the first nonrepeated chacter in "total" 
  is 'o' and the first nonrepeated character in "teeter" is 'r'. 
  Discuss the efficiency of your algorithm.
*/

#include <iostream>
#include <string>

using namespace std;

// Number of characters in alphabet & hash table.
constexpr int TABLE_SIZE{ 26 };

// Hash characters, A=65.
int cHash(char c) { return (isalpha(c)) ? toupper(c) - 64 : 0; }

int main()
{
	std::string s("tee34>;ter)2");
	unsigned i = 0, hTable[TABLE_SIZE] = { 0 };

	// Count of individual characters in string.
	for (; i < s.length(); i++)
		if (int h = cHash(s.at(i)))
			hTable[h - 1]++;

	// Find first non-repeating character.
	for (i = 0; i < s.length(); i++)
	{
		int h = cHash(s.at(i));
		if (h && hTable[h - 1] < 2)
			break;
	}

	// Display results.
	if (i == s.length())
		std::cout << "No non-repeating letters.\n";
	else
		std::cout << s.at(i) << std::endl;
}

