#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include <iostream>
#include "catch.hpp"
#include "XMLParser.hpp"

using namespace std;

// TODO Implement tests of your Stack class and XMLParser class here
// ****************************
// STACK PERSONAL TEST CASES  *
// ****************************

// Testing to see if push and pop functions work properly
TEST_CASE( "Test Stack1", "[ADT Bag]" )
{
	   Stack<int> stack;
		stack.push(1);
        stack.push(2);
        stack.push(3);
        REQUIRE(stack.pop() == 1);
        REQUIRE(stack.pop() == 1);
        REQUIRE(stack.pop() == 1);
		REQUIRE(stack.pop() == 0);
        REQUIRE(stack.isEmpty());
}
// Testing to see if push, peek, and pop functions work properly
TEST_CASE( "Test Stack2", "[ADT Bag]" )
{
	   Stack<int> stack;
		stack.push(1);
        stack.push(2);
        stack.push(3);
		REQUIRE(stack.peek() == 3);
        REQUIRE(stack.pop() == 1);
		REQUIRE(stack.peek() == 2);
        REQUIRE(stack.pop() == 1);
		REQUIRE(stack.peek() == 1);
        REQUIRE(stack.pop() == 1);
        REQUIRE(stack.isEmpty());
}
// Testing to see if push, pop, and clear functions work properly
TEST_CASE( "Test Stack3", "[ADT Bag]" )
{
	   Stack<int> stack;
		stack.push(1);
        stack.push(2);
        stack.push(3);
		stack.clear();
        REQUIRE_FALSE(stack.pop() == 1);
        REQUIRE(stack.isEmpty());
}
// Testing to see if the stack updates the current size each time an item is pushed into it
TEST_CASE( "Test Stack4", "[ADT Bag]" )
{
	   Stack<char> stack;
		stack.push('a');
        stack.push('a');
        stack.push('b');
		stack.push('a');
        REQUIRE(stack.size() == 4);
        REQUIRE(stack.isEmpty() == 0);
}

// TODO Implement tests of your Stack class and XMLParser class here
// ********************************
// XMLParser PERSONAL TEST CASES  *
// ********************************

// Testing to check if invalid strings return false and valid strings return true
TEST_CASE( "Test XMLParser1", "[XMLParser]" )
{
		// Create an instance of XMLParse
		XMLParser myXMLParser;

        REQUIRE(myXMLParser.tokenizeInputString("") == 0);
        REQUIRE(myXMLParser.tokenizeInputString(" ") == 0);
        REQUIRE(myXMLParser.tokenizeInputString("<!>") == 0);

        REQUIRE(myXMLParser.tokenizeInputString("<test></test>") == 1);
        REQUIRE(myXMLParser.tokenizeInputString("<test>content</test>") == 1);
        REQUIRE(myXMLParser.tokenizeInputString("<test attribute=\"value\"></test>") == 1);
}
// Testing to check if flipping the end and start tag return true in tokenize function, but return false in parse function
TEST_CASE( "Test XMLParser2", "[XMLParser]" )
{
		// Create an instance of XMLParse
		XMLParser myXMLParser;

        myXMLParser.tokenizeInputString("<test></test>");
        REQUIRE(myXMLParser.parseTokenizedInput() == true);

		myXMLParser.tokenizeInputString("</test><test>");
        REQUIRE_FALSE(myXMLParser.parseTokenizedInput() == true);
}
// Testing to check if the contains and frequency functions are working properly
TEST_CASE( "Test XMLParser3", "[XMLParser]" )
{
		// Create an instance of XMLParse
		XMLParser myXMLParser;

        myXMLParser.tokenizeInputString("<test></test>");
        REQUIRE(myXMLParser.parseTokenizedInput() == true);
		REQUIRE(myXMLParser.containsElementName("test") == 1);
		REQUIRE(myXMLParser.frequencyElementName("test") == 1);
}
// Testing to check if the parse function returns false because the string I declared is not under one root element
TEST_CASE( "Test XMLParser4", "[XMLParser]" )
{
		// Create an instance of XMLParse
		XMLParser myXMLParser;

		string practice = "<root><test></root></test>";

        myXMLParser.tokenizeInputString("<root><test></root></test>");
		REQUIRE(myXMLParser.parseTokenizedInput() == false);
        REQUIRE(myXMLParser.tokenizeInputString(practice) == true);
}
// Testing to check if the clear function works and erases the tokenizedInputVector
TEST_CASE( "Test XMLParser5", "[XMLParser]" )
{
		// Create an instance of XMLParse
		XMLParser myXMLParser;

        myXMLParser.tokenizeInputString("<test>stuff</test>");
		myXMLParser.parseTokenizedInput();
		myXMLParser.clear();
		REQUIRE(myXMLParser.returnTokenizedInput().size() == 0);
		REQUIRE(myXMLParser.containsElementName("test") == 0);
		REQUIRE(myXMLParser.frequencyElementName("test") == 0);
}


// *******************
// GIVEN TEST CASES  *
// *******************
TEST_CASE( "Test Bag add", "[ADT Bag]" )
{
	   INFO("Hint: testing Bag add()");
		// Create a Bag to hold ints
		Bag<int> intBag;
		int testSize = 2;
		int bagSize;
		bool success;
		for (int i=0; i<testSize; i++) {
			success = intBag.add(i);
			REQUIRE(success);
			bagSize = intBag.size();
			success = (bagSize == (i+1));
			REQUIRE(success);
		}
}

TEST_CASE( "Test Stack push and size", "[ADT Stack]" )
{
	   INFO("Hint: testing Stack push()");
		// Create a Stack to hold ints
		Stack<int> intStack;
		int testSize = 3;
		int stackSize;
		bool success;
		for (int i=0; i<testSize; i++) {
			success = intStack.push(i);
			REQUIRE(success);
			stackSize = intStack.size();
			success = (stackSize == (i+1));
			REQUIRE(success);
		}
}

TEST_CASE( "Test XMLParser tokenizeInputString", "[XMLParser]" )
{
	   INFO("Hint: tokenize single element test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "<test>stuff</test>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
}


TEST_CASE( "Test Stack handout-0", "[XMLParser]" )
{
		// Create a Stack to hold ints
		Stack<int> intStack;
		int testSize = 10;
		int stackSize;
		bool success = false;
		for (int i=0; i<testSize; i++) {
			intStack.push(i);
			stackSize = intStack.size();
			success = (stackSize == (i+1));
			REQUIRE(success);
		}
		for (int i = testSize-1; i>=0; i--) {
			REQUIRE(intStack.isEmpty() == false);
            int elem = intStack.peek();
			REQUIRE(elem == i);
            REQUIRE(intStack.isEmpty() == false);
			intStack.pop();
		}
        REQUIRE(intStack.isEmpty() == true);
}

TEST_CASE( "Test Stack handout-1", "[XMLParser]" )
{
	   Stack<char> charStack;
       std::string s("Hello world");
       int i = 1;
       for (auto c:s) {
           charStack.push(c);
           REQUIRE(charStack.size() == i);
           i++;
       }
       for (i = 0; i < 5; i++) {
           REQUIRE(charStack.isEmpty() == false);
           char c = charStack.peek();
           REQUIRE(c == s[s.length()-1-i]);
           REQUIRE(charStack.isEmpty() == false);
           charStack.pop();
       }
       REQUIRE(charStack.size() == 6);
       charStack.clear();
       REQUIRE(charStack.isEmpty() == true);      
}

// You can assume that the beginning and the end of CONTENT will not be filled with whitespace
TEST_CASE( "Test XMLParser tokenizeInputString Handout-0", "[XMLParser]" )
{
	   INFO("Hint: tokenize single element test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "<test>stuff</test>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		std::vector<TokenStruct> result = {TokenStruct{StringTokenType::START_TAG, std::string("test")},
											TokenStruct{StringTokenType::CONTENT, std::string("stuff")},
											TokenStruct{StringTokenType::END_TAG, std::string("test")}};
		std::vector<TokenStruct> output = myXMLParser.returnTokenizedInput();
		REQUIRE(result.size() == output.size());
		for (int i = 0; i < result.size(); i++) {
			REQUIRE(result[i].tokenType == output[i].tokenType);
			REQUIRE(result[i].tokenString.compare(output[i].tokenString) == 0);
		}
}


// You can assume that the beginning and the end of CONTENT will not be filled with whitespace
TEST_CASE( "Test XMLParser tokenizeInputString Handout-1", "[XMLParser]" )
{
	   INFO("Hint: tokenize multiple elements test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><Note src='gmail'>  <From>Tom</From> <To>Alice</To> </Note>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		std::vector<TokenStruct> result = { TokenStruct{StringTokenType::DECLARATION, std::string("xml version=\"1.0\" encoding=\"UTF-8\"")},
									TokenStruct{StringTokenType::START_TAG, std::string("Note")},
									TokenStruct{StringTokenType::START_TAG, std::string("From")},
									TokenStruct{StringTokenType::CONTENT, std::string("Tom")},
									TokenStruct{StringTokenType::END_TAG, std::string("From")},
									TokenStruct{StringTokenType::START_TAG, std::string("To")},
									TokenStruct{StringTokenType::CONTENT, std::string("Alice")},
									TokenStruct{StringTokenType::END_TAG, std::string("To")},
									TokenStruct{StringTokenType::END_TAG, std::string("Note")}};
		std::vector<TokenStruct> output = myXMLParser.returnTokenizedInput();
		REQUIRE(result.size() == output.size());
		for (int i = 0; i < result.size(); i++) {
			REQUIRE(result[i].tokenType == output[i].tokenType);
			REQUIRE(result[i].tokenString.compare(output[i].tokenString) == 0);
		}
}

TEST_CASE( "Test XMLParser parseTokenizedInput Handout-0", "[XMLParser]" )
{
	   INFO("Hint: tokenize single element test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "<test myattr='abcdef'>stuff<this_is_empty_tag/></test>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		std::vector<TokenStruct> result = {TokenStruct{StringTokenType::START_TAG, std::string("test")},
											TokenStruct{StringTokenType::CONTENT, std::string("stuff")},
											TokenStruct{StringTokenType::EMPTY_TAG, std::string("this_is_empty_tag")},
											TokenStruct{StringTokenType::END_TAG, std::string("test")}};
		std::vector<TokenStruct> output = myXMLParser.returnTokenizedInput();
		REQUIRE(result.size() == output.size());
		success = myXMLParser.parseTokenizedInput();
		REQUIRE(success);
		output = myXMLParser.returnTokenizedInput();
		REQUIRE(result.size() == output.size());
		for (int i = 0; i < result.size(); i++) {
			REQUIRE(result[i].tokenType == output[i].tokenType);
			REQUIRE(result[i].tokenString.compare(output[i].tokenString) == 0);
		}
}

TEST_CASE( "Test XMLParser Final Handout-0", "[XMLParser]" )
{
	   INFO("Hint: TestFile");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		ifstream myfile ("./TestFile.txt");
		std::string inputString((std::istreambuf_iterator<char>(myfile) ), (std::istreambuf_iterator<char>()) );

		bool success;
		success = myXMLParser.tokenizeInputString(inputString);
		REQUIRE(success);
		success = myXMLParser.parseTokenizedInput();
		REQUIRE(success);
		REQUIRE(myXMLParser.containsElementName("catalog"));
		REQUIRE(myXMLParser.frequencyElementName("catalog") == 1);
		REQUIRE(myXMLParser.containsElementName("product"));
		REQUIRE(myXMLParser.frequencyElementName("product") == 1);
		REQUIRE(myXMLParser.containsElementName("catalog_item"));
		REQUIRE(myXMLParser.frequencyElementName("catalog_item") == 2);
		REQUIRE(myXMLParser.containsElementName("item_number"));
		REQUIRE(myXMLParser.frequencyElementName("item_number") == 2);
		REQUIRE(myXMLParser.containsElementName("size"));
		REQUIRE(myXMLParser.frequencyElementName("size") == 6);
		REQUIRE(myXMLParser.containsElementName("color_swatch"));
		REQUIRE(myXMLParser.frequencyElementName("color_swatch") == 15);
}
