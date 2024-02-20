#include <string>
#include <vector>
#include <iostream>
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string & value)
{
	for (int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i]);
	}
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
        candidateStringVector, vector<string> currentStringVector)
{



	return;
}

// private function to determine if a string is a palindrome (given, you
// may change this if you want)
bool FindPalindrome::isPalindrome(string currentString) const
{
	locale loc;
	// make sure that the string is lower case...
	convertToLowerCase(currentString);
	// see if the characters are symmetric...
	int stringLength = currentString.size();
	for (int i=0; i<stringLength/2; i++) {
		if (currentString[i] != currentString[stringLength - i - 1]) {
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome()
{
	// Setting numPalindromes to 0 as Constructor
	numPalindromes = 0;
}

FindPalindrome::~FindPalindrome()
{
	clear();
}

int FindPalindrome::number() const
{
	// Returning the variable that keeps track of the number of palindromes present
	return numPalindromes;
}

void FindPalindrome::clear()
{
	// Setting the variables to either be 0 or empty so that the data is all cleared
	numPalindromes = 0;
	Words.clear();
	Answers.clear();
}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
	string final = "";

	for (int i = 0; i < stringVector.size(); i++)
	{
		final += stringVector[i];
	}

	if (isPalindrome(final))
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	// TODO need to implement this...
	return false;
}

bool FindPalindrome::add(const string & value)
{
	// For-Loop to check if the 'value' parameter if already in the Words vector
	for (int i = 0; i < Words.size(); i++)
	{
		if(Words[i] == value)
		{
			return false;
		}
	}
	Words.push_back(value);
	return true;
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	
}

vector< vector<string> > FindPalindrome::toVector() const
{
	// TODO need to implement this...
	return vector< vector<string> >();
}

