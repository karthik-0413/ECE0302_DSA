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
	// Checking if the vectors pass the cutTest 2 'prerountine' before going into the recursive steps
	if (!cutTest2(candidateStringVector, currentStringVector))
	{
		return;
	}

	// Checking to see if the recursive function meets the requirements for the BASE CASE (which terminates the recursive function)
	else if (currentStringVector.size() == 0)
	{
		string final3;

		// Copying the candidate string over to the string declared above
		for (int i = 0; i < candidateStringVector.size(); i++)
		{
			final3 += candidateStringVector[i];
		}

		// Eliminating case sensitive situations
		convertToLowerCase(final3);

		// Using given function to add the string to the vector and incrementing number of palindromes
		if(isPalindrome(final3))
		{
			Answers.push_back(candidateStringVector);
			numPalindromes++;
		}
	}

	// Iterating through the recursive part of the recursive function (calling the function within itself)
	else
	{
		// For-Loop to iterate through the current vector 
		for (int i = 0; i < currentStringVector.size(); i++)
		{
			string final4 = currentStringVector[i];

			// Transferring the index of the current vector into the back of the candidate vector
			candidateStringVector.push_back(final4);

			// Removing the index of the current vector from the currect vector
			currentStringVector.erase(currentStringVector.begin() + i);

			// Recursively calling the function within itself
			recursiveFindPalindromes(candidateStringVector, currentStringVector);

			// Inserting back the deleted word
			currentStringVector.insert(currentStringVector.begin() + i, final4);

			// Remove top element in the candidate vector
			candidateStringVector.pop_back();
		}
	}


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
	// Since only vectors are being used, the clear function will do the job
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
	// Declaring an empty string to help concatenate easier
	string final;

	// For-Loop to iterate through all of the strings and concatenating it to the empty string
	for (int i = 0; i < stringVector.size(); i++)
	{
		final += stringVector[i];
	}

	// Eliminating case sensitive situations
	convertToLowerCase(final);

	int final5 = 0;

	// For-Loop that iterates through all of the letters in the alphabet 
	for (char c = 'a'; c <= 'z'; ++c)
	{
		int oddCount = 0;
		for (int i = 0; i < final.size(); i++)
		{
			// If statement to check if the character in the final array is equal to the letter in the for loop
			if (final[i] == c)
			{
				// If so, iterate oddCount variable
				oddCount++;
			}
		}

		// Only adding to the final5 variable if the oddCount is odd
		if (oddCount % 2 == 1)
        {
            final5++;
        }
	}

	// Returning if the number of odd instances is more than 1 or not
	return (final5 < 2);
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	// Declaring an empty string to help concatenate easier
	string final1;

	// For-Loop to iterate through all of the strings and concatenating it to the empty string
	for (int i = 0; i < stringVector1.size(); i++)
	{
		final1 += stringVector1[i];
	}

	// Eliminating case sensitive situations
	convertToLowerCase(final1);
;
	// Declaring an empty string to help concatenate easier
	string final2;

	// For-Loop to iterate through all of the strings and concatenating it to the empty string
	for (int i = 0; i < stringVector2.size(); i++)
	{
		final2 += stringVector2[i];
	}

	// Eliminating case sensitive situations
	convertToLowerCase(final2);

	// Declaring string to figure out which string is 
	bool result = false;

	// If-Else Statement to decide which string has the biggest size
	if (final1.size() < final2.size())
	{
		// Nest For-Loops to compare and check if there is a pair for each letter in the big vector
		for (int i = 0; i < final1.size(); i++)
		{
			for (int j = 0; j < final2.size(); j++)
			{
				if (final1[i] == final2[j])
				{
					// If there is a match, then the letter in the big vector will be deleted by a dash
					final2[j] = '-';
					result = true;
					break;
				}
			}
			// If result was false, then stop the function here and return false
			if (result == false)
			{
				return false;
			}
		}
	}
	else
	{
		// Nest For-Loops to compare and check if there is a pair for each letter in the big vector
		for (int i = 0; i < final2.size(); i++)
		{
			for (int j = 0; j < final1.size(); j++)
			{
				if (final2[i] == final1[j])
				{
					// If there is a match, then the letter in the big vector will be deleted by a dash
					final1[j] = '-';
					result = true;
					break;
				}
			}
			// If result was false, then stop the function here and return false
			if (result == false)
			{
				return false;
			}
		}
	}
	return true;
}

bool FindPalindrome::add(const string & value)
{
	string final7 = value;

	// Eliminating case sensitive situations
	convertToLowerCase(final7);

	bool result3 = true;

	// Making a string with the characters that are allowed for this program
	string allow = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (int i = 0; i < final7.size(); i++)
	{
		bool result4 = false;
		for (int j = 0; j < allow.size(); j++)
		{
			// If statement to see if the value in the value string matches any one of the allow string declared above
			if (value[i] == allow[j])
			{
				result4 = true;
				break;
			}
			else
			{
				result4 = false;
			}
		}
		// Copying the bool value of result4 over to result3
		if (result4 == false)
		{
			return false;
		}
		else
		{
			result3 = true;
		}
	}

	// By above copying, if result3 was true, then the adding takes place
	if (result3)
	{
		// For-Loop to check if the 'value' parameter if already in the Words vector
		for (int i = 0; i < Words.size(); i++)
		{
			string final8 = Words[i];

			// Eliminating case sensitive situations
			convertToLowerCase(final8);

			// Checking for ONLY unique letter
			if(final8 == final7)
			{
				return false;
			}
		}

		// Adding the value in the parameter to the the words vector of strings
		Words.push_back(value);

		// Temp empty variable in order to call the recursive function
		vector<string> temp;

		// Resetting numPalindromes variable so that it does not increment too many times
		numPalindromes = 0;
		Answers.clear();

		// Testing if the string can go into the recursive function with implementing the cutTest1 test
		if (cutTest1(Words))
		{
			recursiveFindPalindromes(temp, Words);
		}

		return result3;
	}
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	bool result = true;

	// Making a string with the characters that are allowed for this program
	string allow = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (int j = 0; j < stringVector.size(); j++)
	{
		string temp = stringVector[j];
		// Eliminating case sensitive situations
		convertToLowerCase(temp);
		for (int i = 0; i < stringVector[j].size(); i++)
		{
			bool result5 = false;
			for (int k = 0; k < allow.size(); k++)
			{
				// If statement to see if the value in the value string matches any one of the allow string declared above
				if (temp[i] == allow[k])
				{
					result5 = true;
					break;
				}
				else
				{
					result5 = false;
				}
			}
			// Copying the bool value of result5 over to result
			if (result5 == true)
			{
				result = true;
				break;
			}
			else
			{
				return false;
				break;
			}
		}
	}

	// By above copying, if result was true, then the adding takes place
	if (result)
	{
		// For-Loop to check if the 'value' parameter if already in the Words vector
		for (int i = 0; i < stringVector.size(); i++)
		{
			bool result2 = false;
			string final6 = stringVector[i];

			// Eliminating case sensitive situations
			convertToLowerCase(final6);
			// For-Loop to check if the 'value' parameter if already in the Words vector
			for (int i = 0; i < Words.size(); i++)
			{
				string temp2 = Words[i];

				// Eliminating case sensitive situations
				convertToLowerCase(temp2);

				// Checking for ONLY unique letter
				if(temp2 == final6)
				{
					return false;
				}
			}
			// Inserting the final6 string value into the Words vector
			if(result2 == false)
			{
				Words.push_back(final6);
				result = true;
			}
		}

		// Temp empty variable in order to call the recursive function
		vector<string> temp;

		// Resetting numPalindromes variable so that it does not increment too many times
		numPalindromes = 0;

		// Clearing the Answers vector of vector of strings in order to correctly implement the toVector test
		Answers.clear();

		// Testing if the string can go into the recursive function with implementing the cutTest1 test
		if (cutTest1(Words))
		{
			recursiveFindPalindromes(temp, Words);
		}

		return result;
	}
}

vector< vector<string> > FindPalindrome::toVector() const
{
	// Returning the vector of vector of strings
	return Answers;
}