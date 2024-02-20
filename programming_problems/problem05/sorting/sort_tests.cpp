#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"
#include "sort.hpp"

// write your test cases here
TEST_CASE("Test case", "sorting"){

  LinkedList<int> lst;

  lst.insert(0, 100);
  lst.insert(1, 4);
  lst.insert(2, 10);
  lst.insert(3, 25);
  lst.insert(4, 11);

  LinkedList<int> sorted = sort(lst);

  // check sorted list
  REQUIRE(sorted.getEntry(0) == 4);
  REQUIRE(sorted.getEntry(1) == 10);
  REQUIRE(sorted.getEntry(2) == 11);
  REQUIRE(sorted.getEntry(3) == 25);
  REQUIRE(sorted.getEntry(4) == 100);
}

// Test Case that sorts negative numbers
TEST_CASE("Test case with Negative Numbers", "sorting"){

  LinkedList<int> lst;

  lst.insert(0, -5);
  lst.insert(1, -10);
  lst.insert(2, -4);

  LinkedList<int> sorted = sort(lst);

  // check sorted list
  REQUIRE(sorted.getEntry(0) == -10);
  REQUIRE(sorted.getEntry(1) == -5);
  REQUIRE(sorted.getEntry(2) == -4);
  REQUIRE(sorted.getLength() == 3);
}

// Test Case that sorts numbers with isEmpty/getLength functions
TEST_CASE("Test case with isEmpty/getLength function implemented", "sorting"){

  LinkedList<int> lst;

  lst.insert(0, 67);
  lst.insert(1, 66);

  LinkedList<int> sorted = sort(lst);

  // check sorted list
  REQUIRE(sorted.getEntry(0) == 66);
  REQUIRE(sorted.getEntry(1) == 67);

  REQUIRE_FALSE(sorted.isEmpty() == true);
  REQUIRE(sorted.getLength() == 2);
}

// Test Case that sorts numbers with remove function
TEST_CASE("Test case with remove function", "sorting"){

  LinkedList<int> lst;

  lst.insert(0, 100);
  lst.remove(0);
  lst.insert(1, 10);
  lst.remove(1);
  lst.insert(0, 25);

  LinkedList<int> sorted = sort(lst);

  // check sorted list
  REQUIRE(sorted.getEntry(0) == 25);
  REQUIRE(sorted.getLength() == 1);
}

// Test Case that sorts strings
TEST_CASE("Test case with strings instead of integers", "sorting"){

  LinkedList<std::string> lst;

  lst.insert(0, "adam");
  lst.insert(1, "cat");
  lst.insert(2, "bat");
  lst.insert(3, "ace");

  LinkedList<std::string> sorted = sort(lst);

  // check sorted list
  REQUIRE(sorted.getEntry(0) == "ace");
  REQUIRE(sorted.getEntry(1) == "adam");
  REQUIRE(sorted.getEntry(2) == "bat");
  REQUIRE(sorted.getEntry(3) == "cat");
  REQUIRE(sorted.getLength() == 4);
}

// Test Case that sorts characters
TEST_CASE("Test case with chars instead of integers", "sorting"){

  LinkedList<char> lst;

  lst.insert(0, 'z');
  lst.insert(1, 'f');
  lst.insert(2, 'c');
  lst.insert(3, 'g');
  lst.insert(4, 'a');

  LinkedList<char> sorted = sort(lst);

  // check sorted list
  REQUIRE(sorted.getEntry(0) == 'a');
  REQUIRE(sorted.getEntry(1) == 'c');
  REQUIRE(sorted.getEntry(2) == 'f');
  REQUIRE(sorted.getEntry(3) == 'g');
  REQUIRE(sorted.getEntry(4) == 'z');
  REQUIRE(sorted.getLength() == 5);
}

// Test Case that sorts boolean values
TEST_CASE("Test case with bools instead of integers", "sorting"){

  LinkedList<bool> lst;

  lst.insert(0, 1);
  lst.insert(1, 0);
  lst.insert(2, 1);
  lst.insert(3, 0);

  LinkedList<bool> sorted = sort(lst);

  // check sorted list
  REQUIRE(sorted.getEntry(0) == 0);
  REQUIRE(sorted.getEntry(1) == 0);
  REQUIRE(sorted.getEntry(2) == 1);
  REQUIRE(sorted.getEntry(3) == 1);
  REQUIRE(sorted.getLength() == 4);
}

// Test Case that sorts float numbers
TEST_CASE("Test case with floats instead of integers", "sorting"){

  LinkedList<float> lst;

  lst.insert(0, 45.6698);
  lst.insert(1, 23.4535);
  lst.insert(2, 69.3591);
  lst.insert(3, 47.4598);
  lst.insert(4, 56.4558);

  LinkedList<float> sorted = sort(lst);

  // check sorted list
  REQUIRE(sorted.getEntry(0) == 23.4535f);
  REQUIRE(sorted.getEntry(1) == 45.6698f);
  REQUIRE(sorted.getEntry(2) == 47.4598f);
  REQUIRE(sorted.getEntry(3) == 56.4558f);
  REQUIRE(sorted.getEntry(4) == 69.3591f);
  REQUIRE(sorted.getLength() == 5);
}

// Test Case that sorts double numbers
TEST_CASE("Test case with doubles instead of integers", "sorting"){

  LinkedList<double> lst;

  lst.insert(0, 2.34);
  lst.insert(1, 1.59);
  lst.insert(3, 8.34);
  lst.insert(4, 7.48);

  LinkedList<double> sorted = sort(lst);

  // check sorted list
  REQUIRE(sorted.getEntry(0) == 1.59);
  REQUIRE(sorted.getEntry(1) == 2.34);
  REQUIRE(sorted.getEntry(2) == 7.48);
  REQUIRE(sorted.getEntry(3) == 8.34);
  REQUIRE(sorted.getLength() == 4);
}