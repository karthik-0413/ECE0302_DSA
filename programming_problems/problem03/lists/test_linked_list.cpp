#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"

template class LinkedList<int>;

TEST_CASE( "TODO", "[LinkedList]" ) {

    LinkedList<int> list;
}

//Test Case to see if the insert and getLength is working properly
TEST_CASE( "Test Insert Function with getLength function", "[LinkedList]")
{
  LinkedList<int> list;
  list.insert(0, 1);
  list.insert(1, 2);
  REQUIRE(list.getLength() == 2);
}

//Test Case to see if the remove and getLength is working properly
TEST_CASE( "Test Remove Function with getLength function", "[LinkedList]")
{
  LinkedList<int> list;
  list.insert(0, 1);
  list.remove(0);
  REQUIRE(list.getLength() == 0);
}

//Test Case to see if the insert, remove and isEmpty is working properly
TEST_CASE( "Test Remove Function with isEmpty function", "[LinkedList]")
{
  LinkedList<int> list;
  list.insert(0, 1);
  list.remove(0);
  REQUIRE(list.isEmpty() == 1);
}

//Test Case to see if the insert, clear and isEmpty is working properly
TEST_CASE( "Test Remove Function with isEmpty/clear function", "[LinkedList]")
{
  LinkedList<int> list;
  list.insert(0, 1);
  list.clear();
  REQUIRE(list.isEmpty() == 1);
}

//Test Case to see if the insert and getEntry is working properly
TEST_CASE( "Test Insert Function with getEntry function", "[LinkedList]")
{
  LinkedList<int> list;
  list.insert(0, 10);
  REQUIRE(list.getEntry(0) == 10);
}

//Test Case to see if the insert, setEntry, and getEntry is working properly
TEST_CASE( "Test Insert Function with setEntry/getEntry function", "[LinkedList]")
{
  LinkedList<int> list;
  list.insert(0, 10);
  list.setEntry(0, 200);
  REQUIRE(list.getEntry(0) == 200);
}

//Test Case to see if the Copy Constructor is working properly
TEST_CASE("Test Copy Constructor Function", "[LinkedList]") {
  LinkedList<int> list;
  list.insert(0, 200);
  list.insert(1, 300);
  LinkedList<int> list2 = list;
  REQUIRE(list.getLength() == list2.getLength());
  REQUIRE(list2.getEntry(0) == 200);
  REQUIRE(list2.getEntry(1) == 300);
}