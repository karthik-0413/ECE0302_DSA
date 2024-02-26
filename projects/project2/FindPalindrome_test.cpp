#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"
#include <vector>
#include <string>
using namespace std;

// There should be at least one test per FindPalindrome method
TEST_CASE("test recursion", "[FindPalindrome]"){
	FindPalindrome b;
	REQUIRE(b.add("a"));
	REQUIRE(b.add("AA"));
	REQUIRE(b.add("AaA"));
	REQUIRE(b.number() == 6);
}

// Test Case for non-allowable word
TEST_CASE( "Test adding a non-allowable word", "[FindPalindrome]" )
{
	FindPalindrome b;
	REQUIRE(b.add("kayak"));
	REQUIRE(!(b.add("kayak1")));
}

// Test Case for CutTest 2 when is suuposed to fail
TEST_CASE("test CutTest2 with a letter in the small string and not in big string",  "[FindPalindrome]"){
	FindPalindrome b;
	vector<string> arg1 = {"add", "add", "a"};
	vector<string> arg2 = {"sub", "asb"};
	REQUIRE_FALSE(b.cutTest2(arg1, arg2));
}

// Test Case for CutTest 2 when is suuposed to pass
TEST_CASE("test CutTest2 with all letters same in both strings",  "[FindPalindrome]"){
	FindPalindrome b;
	vector<string> arg1 = {"add", "add", "a"};
	vector<string> arg2 = {"add", "add"};
	REQUIRE(b.cutTest2(arg1, arg2));
}

// Test Case for CutTest 1 when is suuposed to pass
TEST_CASE("test CutTest1 with only one odd",  "[FindPalindrome]"){
	FindPalindrome b;
	vector<string> arg1 = {"add", "add", "a"};
	REQUIRE(b.cutTest1(arg1));
}

// Test Case for CutTest 1 when is suuposed to fail
TEST_CASE("test CutTest1 with two odds",  "[FindPalindrome]"){
	FindPalindrome b;
	vector<string> arg1 = {"add", "add", "ad"};
	REQUIRE_FALSE(b.cutTest1(arg1));
}

// Test Case for toVector with only one string
TEST_CASE("test toVector with one",  "[FindPalindrome]"){
	FindPalindrome b;
	REQUIRE(b.add("dad"));
	vector<vector<string>> test = b.toVector();
	REQUIRE(test.size() == 1);
}

// Test Case for toVector with no strings
TEST_CASE("test toVector with zero palindromes", "[FindPalindrome]") {
    FindPalindrome b;
    vector<vector<string>> test = b.toVector();
    REQUIRE(test.size() == 0);
}

// Test Case for checking duplicates and making sure it does not take it in
TEST_CASE("test to check for duplicates", "[FindPalindrome]") {
    FindPalindrome b;
    REQUIRE(b.add("a"));
	REQUIRE(!b.add("a"));
	REQUIRE(b.number() == 1);
}

// Test Case for making sure that the number of sentence palindromes is N!
// In this case it would be 5! = 120
TEST_CASE("test factorial as stated in instruction", "[FindPalindrome]"){
	FindPalindrome b;
	REQUIRE(b.add("r"));
	REQUIRE(b.add("rR"));
	REQUIRE(b.add("Rrr"));
	REQUIRE(b.add("rrRr"));
	REQUIRE(b.add("rRrRR"));
	REQUIRE(b.number() == 120);
}