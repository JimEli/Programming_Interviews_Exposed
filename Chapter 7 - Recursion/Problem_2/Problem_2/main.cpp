/*
   Implement a routine that prints all possible orderings of the characters
   in a string. In other words, print all permutations that use all the characters 
   from the original string. For example, given the string “hat”, your function 
   should print the strings “tha”, “aht”, “tah”, “ath”, “hta”, and “hat”. Treat 
   each character in the input string as a distinct character, even if it is 
   repeated. Given the string “aaa”, your routine should print “aaa” six times. 
   You may print the permutations in anyorder you choose.
*/
#include <iostream>
#include <string>
#include <algorithm> // For alternative STL version.

void permute(int depth, std::string sPermuted, bool used[], std::string &sOriginal)
{
	if (depth == sOriginal.length())
		// Permutation complete, display results.
		std::cout << sPermuted << std::endl;

	else
	{
		for (unsigned i = 0; i < sOriginal.length(); i++)
		{
			// Try to add an unused character.
			if (!used[i])
			{
				used[i] = true;
				// Find the permutations starting with this string.
				permute(depth + 1, sOriginal[i] + sPermuted, used, sOriginal);
				used[i] = false;
			}
		}
	}
}

int main() 
{
	// Sample permutation string of characters.
	std::string s = "1234";
	// Flag indicates number of characters used (init to false).
	bool *charsUsed = new bool[s.length()];
	std::fill(charsUsed, charsUsed + s.length(), false);
	
	permute(0, "", charsUsed, s);

	// Alternative version using C++ STL.
	std::cout << std::endl;
	{
		std::string str = "abc";

		// Lexically greater permutations.
		do {
			std::cout << str << std::endl;
		} while (std::next_permutation(str.begin(), str.end()));

		// Lexically smaller permutations.
		while (std::prev_permutation(str.begin(), str.end()))
			std::cout << str << std::endl;
	}

	delete[] charsUsed;
}

/*
template<typename T>
void permute(std::string s, T print, std::size_t start = 0)
{
	if (start == s.length())
		print(s);

	for (std::size_t i = start; i < s.length(); i++)
	{
		std::swap(s[start], s[i]);
		permute(s, print, start + 1);
	}
}

int main(void)
{
	std::string s = "123";
	permute(s, [](std::string s) {	std::cout << s << std::endl; });
}
*/

