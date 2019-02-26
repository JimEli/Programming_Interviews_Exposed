/*
   People in the United States often give others their telephone number
   as a word representing the seven-digit number after the area code. For
   example, if my telephone number were 866-2665, I could tell people my 
   number is “TOOCOOL,” instead of the hard-to-remember seven-digit number. 
   Note that many other possibilities (most of which are nonsensical) can 
   represent 866-2665. You can see how letters correspond to numbers on a 
   telephone keypad:

     --- ABC DEF
      1   2   3
     GHI JKL MNO
      4   5   6
	 PRS TUV WXY
      7   8   9
     --- --- ---
      *   0   #
   
   Write a function that takes a seven-digit telephone number and prints out 
   all of the possible “words” or combinations of letters that can represent 
   the given number. Because the 0 and 1 keys have no letters on them, you 
   should change only the digits 2–9 to letters. You’ll be passed an array of 
   seven integers, with each element being one digit in the number. You may 
   assume that only valid phone numbers will be passed to your function. You 
   can use the helper function:
   
   char getCharKey( int telephoneKey, int place )
   
   which takes a telephone key (0–9) and a place of either 1, 2, 3 and returns 
   the character corresponding to the letter in that position on the specified 
   key. For example, GetCharKey(3,2) will return ‘E’ because the telephone key 
   3 has the letters “DEF” on it and ‘E’ is the second letter.
*/
#include <iostream>
#include <string>

constexpr std::size_t CHARS_PER_DIGIT{ 3 };
const std::string charKey[10] { "000", "111", "abc", "def", "ghi", "jkl", "mno", "prs", "tuv", "wxz" };

auto getCharKey = [&](int telephoneKey, int place) { return charKey[telephoneKey][place]; };
auto toDigit = [](char c) { return (c - '0'); };

void printWords(std::string number, std::string word, int digit=0)
{
	if (digit == number.length())
	{
		std::cout << word << std::endl;
		return;
	}

	for (std::size_t i = 0; i < CHARS_PER_DIGIT; i++)
	{
		word += getCharKey(toDigit(number[digit]), i);
		printWords(number, word, digit + 1);
		word.resize(digit);
		if (toDigit(number[digit]) <= 1)
			return;
	}
}

int main(void)
{
	std::string s("3604107861"), output;

	printWords(s, output);
	std::cout << std::endl;
}