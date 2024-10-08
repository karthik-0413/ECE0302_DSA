#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include <iostream>
#include "bitset.hpp"

TEST_CASE( "Test bitset default construction", "[bitset]" ) {

    Bitset b;  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
}

TEST_CASE( "Test bitset construction with asString", "[bitset]" ) {
    Bitset b;
    REQUIRE(b.asString().compare("00000000") == 0);
}

TEST_CASE( "Test bitset construction size", "[bitset]" ) {
    Bitset b(64);
    std::string s(64, '0');
    REQUIRE(b.size() == 64);
    REQUIRE(b.good());
}

TEST_CASE( "Test bitset construction string", "[bitset]" ) {
    std::string s("00101110000011000001101000001");
    Bitset b(s);
    REQUIRE(b.size() == s.size());
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);
}

TEST_CASE( "Test bitset construction invalid string", "[bitset]" ) {
    std::string s("00101110000011002001101000001");
    Bitset b(s);
    REQUIRE_FALSE(b.good());
}

TEST_CASE( "Test set", "[bitset]" ) {
    std::string s("00010001");
    Bitset b;
    b.set(3);
    b.set(7);
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);
}

TEST_CASE( "Test set with size init", "[bitset]" ) {
    std::string s("00010");
    Bitset b(5);
    b.set(3);
    REQUIRE(b.size() == 5);
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);
}

TEST_CASE( "Test combined", "[bitset]" ) {
    std::string s((1<<15) + 3, '0');
    Bitset b(s);
    REQUIRE(b.size() == s.size());
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);

    for (int i = 1; i < (1<<10); i++) {
        b.set(i);
        b.reset(i + (1<<10));
        b.toggle(i + (1<<11));
        REQUIRE(b.good());
        REQUIRE(b.test(i));
        REQUIRE_FALSE(b.test(i + (1<<10)));
        REQUIRE(((b.test(i + (1<<11)) == true && s.at(i + (1<<11)) == '0') || (b.test(i + (1<<11)) == false && s.at(i + (1<<11)) == '1')));
    }
}

// **********************
// PERSONAL TEST CASES  *
// **********************

//Test Case that tests if the reset function is working properly
TEST_CASE( "Test reset", "[bitset]") {
    std::string bitv ("00011111");
    Bitset box(bitv);
    box.reset(2);
    REQUIRE(box.size() == 8);
    REQUIRE(box.good());
    REQUIRE(box.asString().compare(bitv) == 0);
}

//Test Case that checks if the set and reset member function works properly
TEST_CASE( "Test set/reset", "[bitset]") {
    std::string bitv ("00011001");
    Bitset box(bitv);
    box.reset(2);
    box.set(2);
    REQUIRE(box.size() == 8);
    REQUIRE(box.good());
    REQUIRE(box.asString().compare(bitv) == 1);
}

//Test Case that checks if the toggle member function works properly
TEST_CASE( "Test toggle", "[bitset]") {
    std::string bitv ("11001101");
    Bitset box(bitv);
    box.toggle(2);
    REQUIRE(box.size() == 8);
    REQUIRE(box.good());
    REQUIRE(box.asString().compare(bitv) == 1);
}

//Test Case that checks if the asString member function works properly
TEST_CASE ("Length Check", "[bitset]")
{
    std::string bitv("10111001");
    Bitset box(bitv);
    REQUIRE(box.asString().compare(bitv) == 0);
    REQUIRE(box.size() == bitv.size());
}

//Test Case that checks if the toggle member function works properly
TEST_CASE( "Test toggle2", "[bitset]") {
    std::string bitv  ("11001101");
    std::string bitv2 ("00110010");
    Bitset box(bitv);
    box.toggle(0);
    box.toggle(1);
    box.toggle(2);
    box.toggle(3);
    box.toggle(4);
    box.toggle(5);
    box.toggle(6);
    box.toggle(7);
    REQUIRE(box.size() == 8);
    REQUIRE(box.good());
    REQUIRE(box.asString().compare(bitv2) == 0);
}