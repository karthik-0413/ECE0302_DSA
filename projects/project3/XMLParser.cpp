// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"

// TODO: Implement the constructor here
XMLParser::XMLParser()
{
	// Allocating memory for the already declared variables in the .hpp file
	elementNameBag = new Bag<std::string>();
	parseStack = new Stack<std::string>();
	first = false;
	second = false;
}  // end default constructor

// TODO: Implement the destructor here
XMLParser::~XMLParser()
{
	// Deallocating memory for the already declared variables in the .hpp file
	delete elementNameBag;
	delete parseStack;
}  // end destructor

// TODO: Implement the tokenizeInputString method
bool XMLParser::tokenizeInputString(const std::string &inputString)
{	
	//Clearing the tokenizedInputVector every iteration of the function (as said in instructions)
	tokenizedInputVector.clear();

	// Declaring needed variables
	TokenStruct token;
	string notallowed = "!\'#$%&\"()*+,/;<>=?@[]\\^`~{}|";
	int size;
	int counter = 0;
    vector<int> delimiterPosition;
    vector<char> delimiterArrow;
    string tag;
    string content;
	bool allowedToCheck = false;

	// For-Loop that goes through the inputString and checks if the string is just a string full of spaces
	for (char c : inputString)
	{
		if (isspace(c))
		{
			counter++;
		}
	}
	// If the string is full of spaces, then returning false to the function and getting out of it (TEST #15)
	if (counter == inputString.size())
	{
		first = false;
		return false;
	}
	

    // Search for bracket locations in inputString
    for (int i = 0; i < inputString.size(); i++)
    {
        char c = inputString[i];

        if (c == '<')
        {
			// Allowing the first element to be a '<' symbol
			if (delimiterArrow.size() == 0)
			{
				delimiterArrow.push_back('<');
				delimiterPosition.push_back(i);
			}
			// Only allowing more elements into the vector if there is a '>' before the next '<' symbol
			else if (delimiterArrow.back() == '<')
			{
				first = false;
				return false;
			}
			else
			{
				delimiterArrow.push_back('<');
				delimiterPosition.push_back(i);
			}
        }
        else if (c == '>')
        {
			// Allowing the first element to be a '>' symbol
            if (delimiterArrow.size() == 0)
			{
				delimiterArrow.push_back('>');
				delimiterPosition.push_back(i);
			}
			// Only allowing more elements into the vector if there is a '<' before the next '>' symbol
			else if (delimiterArrow.back() == '>')
			{
				first = false;
				return false;
			}
			else
			{
				delimiterArrow.push_back('>');
				delimiterPosition.push_back(i);
			}
        }
    }

	// "Base Case #1" if there are no brackets to be found in the string, then make everything CONTENT
	if (delimiterArrow.size() == 0)
	{
		token.tokenString = inputString;
		token.tokenType = CONTENT;
		tokenizedInputVector.push_back(token);

		first = true;
		return true;
	}

	// "Base Case #2" if there is only one bracket
	else if (delimiterArrow.size() == 1)
	{
		content = inputString.substr(0, delimiterArrow.size());
		counter = 0;
		
		// For-Loop that goes through the inputString and checks if the string is just a string full of spaces
		for (char c : content)
		{
			if (isspace(c))
			{
				counter++;
			}
		}
		// If the string is full of spaces, then returning false to the function and getting out of it (TEST #15)
		if (counter == content.size())
		{
			first = false;
			return false;
		}

		// If test above passes, then adding the content string to the tokenizedInputVector
		token.tokenString = content;
		token.tokenType = CONTENT;
		tokenizedInputVector.push_back(token);

		// Since only one bracket, the function is done here
		first = true;
		return true;
	}

	// "Base Case #3" if the last delimiter is a '<' symbol that means that it does not have a pair associated with it
	// So, remove the last element in both vectors if that is the case
	else if (delimiterArrow.size() == '<')
	{
		// For-Loop that skips the last element in the vector
		for (int i = 0; i < delimiterArrow.size() - 1; i++)
		{
			delimiterArrow[i] = delimiterArrow[i];
		}

		// For-Loop that skips the last element in the vector
		for (int i = 0; i < delimiterPosition.size() - 1; i++)
		{
			delimiterPosition[i] = delimiterPosition[i];
		}
	}

	// If-Statements that check to get the size of the vector
	if (delimiterArrow.size() != 0 && delimiterPosition[0] > 0)
	{
		size = delimiterPosition[0] - 1;

		// Transferring the data of the delimiterArrow string to the content string
		for (int i = 0; i < size; i++)
		{
			delimiterArrow[i] = content[i];
		}

		// Resetting counter variable in order to count again from zero
		counter = 0;
		// For-Loop that goes through the inputString and checks if the string is just a string full of spaces
		for (char c : content)
		{
			if (isspace(c))
			{
				counter++;
			}
		}
		// If the string is full of spaces, then returning false to the function and getting out of it (TEST #15)
		if (counter == content.size())
		{
			first = false;
		}
		// If not, then adding the content string to the tokenizedInputVector
		else
		{
			token.tokenString = content;
			token.tokenType = CONTENT;
			tokenizedInputVector.push_back(token);
		}
	}

    // Extract tag and content substrings from inputString using delimiterPosition values
    for (int i = 0; i < delimiterPosition.size() - 1; i++)
    {
		// Making sure to get only odd index
		bool result = i % 2 != 0;

		// If the index is odd, then it is a delimiter
		if (result)
		{
			// Shortening size variable with each iteration
			size = (delimiterPosition[i + 1] - delimiterPosition[i] - 1);

			if (size != 0)
			{
				// Resetting counter variable in order to count again from zero
				// 
				counter = 0;
				content.clear();
				content = inputString.substr(delimiterPosition[i] + 1, size);
 
				// For-Loop that goes through the inputString and checks if the string is just a string full of spaces
				for (char c : content)
				{
					if (isspace(c))
					{
						counter++;
					}
				}
				// If the string is full of spaces, then returning false to the function and getting out of it (TEST #15)
				if (counter == content.size())
				{
					first = false;
				}
				// If not, then adding the content string to the tokenizedInputVector
				else
				{
					token.tokenString = content;
					token.tokenType = CONTENT;
					tokenizedInputVector.push_back(token);
				}
			}
		}
		// If the index is even, then move character to random TAG type
        else
		{
			size = (delimiterPosition[i + 1] - delimiterPosition[i] - 1);

			//Pushing the character back to a random TAG type in order to move on to the program
			token.tokenString = inputString.substr(delimiterPosition[i] + 1, size);
			token.tokenType = EMPTY_TAG;
			tokenizedInputVector.push_back(token);
		}
    }

	if (delimiterPosition.back() != inputString.size() - 1)
	{
		counter = 0;
		size = inputString.size() - delimiterPosition.back() - 1;
		content = inputString.substr(delimiterPosition.back() + 1, size);

		// For-Loop that goes through the inputString and checks if the string is just a string full of spaces
		for (char c : content)
		{
			if (isspace(c))
			{
				counter++;
			}
		}
		// If the string is full of spaces, then returning false to the function and getting out of it (TEST #15)
		if (counter == content.size())
		{
			first = false;
		}
		// If not, then adding the content string to the tokenizedInputVector
		else
		{
			token.tokenString = content;
			token.tokenType = CONTENT;
			tokenizedInputVector.push_back(token);
		}
	}

	// For-Loop that goes through the tokenizedInputVector and assigns the strings to the proper TAGs
    for (int i = 0; i < tokenizedInputVector.size(); i++)
    {
		// Contents are already done, so this can be skipped (Since it has no brackets)
        if (tokenizedInputVector[i].tokenType != CONTENT)
        {
			// Temp variables to check which TAG the string is
            tag = tokenizedInputVector[i].tokenString;
            size = tag.size();

			// "Base Case" if the string is empty, then string is invalid
			if (tag.size() == 0)
			{
				first = false;
			}
			// Assigning the string to END_TAG if is has a / in the end
            else if (tag[size - 1] == '/')
            {
				// For-Loop that takes everything before the first space (if there is one) and uses that string as the string for the EMPTY TAG
				int k = 0;
				for (char c : tag)
				{
					if (isspace(c))
					{
						tag = tag.substr(0, k - 1);
						break;
					}
					k++;
				}
               
			    // Getting rid of the '/' at the end of the TAG as per instructions 
                if (tag[tag.size() - 1] == '/')
				{
					tag.resize(tag.size() - 1);
				}

				allowedToCheck = true;
				// Pushing the string to the tokenizedInputVector
                tokenizedInputVector[i].tokenType = EMPTY_TAG;
                tokenizedInputVector[i].tokenString = tag;
            }
			// Assigning the string to END_TAG if is has a / in the beginning
			else if (tag[0] == '/')
            {
				// Not including the '/' as per the instructions and then pushing the string to the tokenizedInputVector
                tag = tag.substr(1, size - 1);
				allowedToCheck = true;
                tokenizedInputVector[i].tokenType = END_TAG;
                tokenizedInputVector[i].tokenString = tag;
            }
			// Assigning the string to DECLARATION if is has a ? in the beginning and end 
            else if (tag[0] == '?' && tag[size - 1] == '?')
            {
				// Not including the ?'s as per the instructions and then pushing the string to the tokenizedInputVector
                tag = tag.substr(1, size - 2);
                tokenizedInputVector[i].tokenType = DECLARATION;
                tokenizedInputVector[i].tokenString = tag;
            }
			// Assigning the string to START_TAG if has no symbols in it 
            else
            {
				// For-Loop that takes everything before the first space (if there is one) and uses that string as the string for the START TAG
				int k = 0;
				for (char c : tag)
				{
					if (isspace(c))
					{
						tag = tag.substr(0, k);
                        break;
					}
					k++;
				}

				allowedToCheck = true;
				// Pushing the string to the tokenizedInputVector
                tokenizedInputVector[i].tokenType = START_TAG;
                tokenizedInputVector[i].tokenString = tag;
            }
        }
 
       
    }
 
	// For-Loop that iterates through the tokenizedInputVector to make sure all of the 
    for(int i = 0; i < tokenizedInputVector.size(); i++)
    {
		// Only check the START, END, and EMPTY tags for their vailidty
        if ((tokenizedInputVector[i].tokenType == START_TAG) || (tokenizedInputVector[i].tokenType == END_TAG) || (tokenizedInputVector[i].tokenType == EMPTY_TAG))
        {
			// If the first element is a '-', then string is invalid
            if (tokenizedInputVector[i].tokenString[0] == '-')
            {
                first = false;
				return false;
            }
			// If the first element is a '.', then string is invalid
			else if (tokenizedInputVector[i].tokenString[0] == '.')
            {
                first = false;
				return false;
            }
			// If the first element is a ' ', then string is invalid
			else if (tokenizedInputVector[i].tokenString[0] == ' ')
            {
                first = false;
				return false;
            }
			// If the vector is empty, then string is invalid
			else if ((tokenizedInputVector[i]).tokenString.empty())
            {
                first = false;
				return false;
            }
 
			// Nested For-Loop that goes through the tokenizedInputString check for invalid characters
            for(int j = 0; j < (tokenizedInputVector[i]).tokenString.size(); j++)
            {
                for(int a = 0; a < notallowed.size(); a++)
                {
                    if ((tokenizedInputVector[i]).tokenString[j] == notallowed[a])
                    {
                        first = false;
						return false;
                    }
                }
            }
        }
    }

	// Setting the tokenized bool value to true since it made it through all of the tests
	first = true;
 
    // Returns true if all tokens are valid, false if at least one token is notallowed
    return first;
}


// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput()
{
	// Checking to see if the string can been tokenized first
	if (first == 0)
	{
		second = false;
		return false;
	}
	else
	{
		// Resetting all variables before parsing 
		parseStack->clear();
		elementNameBag->clear();
	}

	// temp variable to hold each token
	StringTokenType temp;
	// temp variable to hold each token
	TokenStruct temp2;
	// String to keep track of token string
	string one;
	// String to keep track of peek string to make sure they match
	string two;
	// String to compare the top of the stack to the token string
	int count;
	// Vector to hold all of the tokens
	std::vector<TokenStruct> allTokens;

	// For-Loop to iterate through each of the characters in the tokenizedInputVector
	for (int i = 0; i < tokenizedInputVector.size(); i++)
	{
		// If-Statement to avoid DECLARATION tags
		if (tokenizedInputVector[i].tokenType != DECLARATION)
		{
			// If-Statement to make sure that START tags is the root element
			if (tokenizedInputVector[i].tokenType == START_TAG)
			{
				count = i;
				one = tokenizedInputVector[i].tokenString;
			}
			// Else, making that start point the variable count
			else
			{
				second = false;
				return false;
			}
			break;
		}
		// If START tag, then add the element bag
		else
        {
            elementNameBag->add(tokenizedInputVector[i].tokenString);
        }
	}

	// Checking to see root element (as said in annoucement made) AND checking to see if the code ends with an END tag
	if (tokenizedInputVector.back().tokenString != one || tokenizedInputVector.back().tokenType != END_TAG)
	{
		second = false;
		return false;
	}

	// Starting from the root element index 
	for (int i = count; i < tokenizedInputVector.size(); i++)
	{
		// Temp variable to store value of tokenizedInputVector
		temp = tokenizedInputVector[i].tokenType;

		// Only pushing back START and END tags to check if they are matching
		if (temp == START_TAG)
		{
			allTokens.push_back(tokenizedInputVector[i]);
		}
		else if (temp == END_TAG)
		{
			allTokens.push_back(tokenizedInputVector[i]);
		}
		// Cannot be a DECLARATION tag
		else if (temp == DECLARATION)
		{
			second = false;
			return false;
		}
	}

	// 'Preps' the START and END tags to be compared to 
	// Nested For-Loops AND If-Statement to extract only the START and END tags
	for (int i = 0; i < allTokens.size(); i++)
	{
		if (allTokens[i].tokenType == END_TAG)
		{
			for (int j = 0; j < allTokens.size(); j++)
			{
				if (allTokens[j].tokenType == START_TAG)
				{
					// If pairs of the tags are made, then they are set to CONTENT type tag
					allTokens[i].tokenType = CONTENT;
                    allTokens[j].tokenType = CONTENT;
                    break;
				}
			}
		}
	}

	// For-Loop that only allows CONTENT tag values through
	for(unsigned int i = 0; i < allTokens.size(); i++)
    {
		// If START tag, then returning false and getting out of the function
        if (allTokens[i].tokenType == START_TAG)
        {
            second = false;
            return false;
        }
		// If END tag, then returning false and getting out of the function
		else if (allTokens[i].tokenType == END_TAG)
        {
            second = false;
            return false;
        }
		// If EMPTY tag, then returning false and getting out of the function
		else if (allTokens[i].tokenType == EMPTY_TAG)
        {
            second = false;
            return false;
        }
		// If DECLARATION tag, then returning false and getting out of the function
		else if (allTokens[i].tokenType == DECLARATION)
        {
            second = false;
            return false;
        }
		// If CONTENT tag, then breaking out of the for loop and moving on with the function
		else
		{
			break;
		}
    }

	// For-Loop to iterate through each of the characters in the tokenizedInputVector
	for (int i = count; i < tokenizedInputVector.size(); i++)
	{
		temp = tokenizedInputVector[i].tokenType;
		one = tokenizedInputVector[i].tokenString;

		// Checking to see if the tag type is END tag
		// If so, CMP it to the START tag
		if (temp == END_TAG)
		{
			// Checking to see if the stack has items in it
			if (parseStack->isEmpty())
			{
				second = false;
				return false;
			}
			else
			{
				// Obtaining value of top of stack
				two = parseStack->peek();
				// Making sure the START and END tags are the EXACT same
                if (two != one)
                {
					second = false;
                    return false;
                }
                else
                {
                    parseStack->pop();
                }
			}
		}
		// Checking to see if the tag type is EMPTY tag
		// If so, add it to the bag
		else if (temp == EMPTY_TAG)
		{
			elementNameBag->add(one);
		}
		// Checking to see if the tag type is CONTENT tag
		// If so, add it to the bag
		else if (temp == CONTENT)
		{
			elementNameBag->add(one);
		}
		// Checking to see if the tag type is START tag
		// If so, add it to the bag and push to stack
		else if (temp == START_TAG)
        {
            elementNameBag->add(one);
 
            parseStack->push(one);
        }
	}

	// If there are still elements in the stack, then return false
	if (parseStack->size() != 0)
	{
		second = false;
    }

	// Setting the parse bool value to true since it made it through all of the tests
	second = true;

	// Returning true
	return second;
}

// TODO: Implement the clear method here
void XMLParser::clear()
{
	// Resetting (clearing) all of the variable values
	elementNameBag->clear();
	parseStack->clear();
	tokenizedInputVector.clear();
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{   
	// Returns a vector containing all the tokenized input as a vector
	return tokenizedInputVector;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const
{
	// Throwing an exception to see the the input has been tokenized and parsed 
	if (first == 0 || second == 0)
	{
		throw std::logic_error("The input has not been tokenized and parsed.");
	
	}
	else
	{
		// Using function from Bag ADT to help see if it contains the parameter string
		return elementNameBag->contains(inputString);
	}
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString) const
{
	// Throwing an exception to see the the input has been tokenized and parsed 
	if (first == 0 || second == 0)
	{
		throw std::logic_error("The input has not been tokenized and parsed.");
	
	}
	else
	{
		// Using function from Bag ADT to help see if it contains the parameter string
		return elementNameBag->getFrequencyOf(inputString);
	}
}
