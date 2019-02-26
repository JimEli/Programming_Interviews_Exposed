/*
   Write a function that reverses the order of the words in a string. 
   For example, your function should transform the string "Do or do not, 
   there is no try." to "try. no is there not, do or Do". Assume that all 
   words are space delimited and treat punctuation the same as letters.
*/

#include <iostream>
#include <string>

int main()
{
	std::string s("Now is the time for all good men to come to the aid of their country.");
	std::cout << s << '\n';

	// Reverse entire sequence.
	std::size_t i = 0, j = s.length();
	while (i < j--)
		std::swap(s[i++], s[j]);

	// Reverse each word.
	i = 0;
	while (s[i])
	{
		// Skip whitespace, i=beginning of word.
		while (isspace(s[i]))
			++i;

		// Skip until whitespace or EOS, j=end of word+1.
		j = i;
		while (s[j] && !isspace(s[j]))
			++j;

		// Remember last position.
		std::size_t last = j;
		while (i < j--)
			std::swap(s[i++], s[j]);

		// Start at last position.
		i = last;
	}

	std::cout << s << '\n';
}

/*
#include <string>    // for storing strings in a C++ way
#include <sstream>   // to easily separate sentences into words
#include <vector>    // to dynamically store arbitrary amounts of words
#include <algorithm> // for std::reverse
#include <iostream>  // for printing the result

int main()
{
	std::string sentence = "Your sentence which contains ten words, two of them numbers";
	std::stringstream stream(sentence);
	std::string word;
	std::vector<std::string> words;

	while (stream >> word)
		words.push_back(word);

	std::reverse(words.begin(), words.end());

	for (size_t i=0; i<words.size(); ++i)
		std::cout << words[i] << " ";
	std::cout << "\n";
}
*/