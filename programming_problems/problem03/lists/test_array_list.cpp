#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "array_list.hpp"

//force class expansion
template class ArrayList<int>;

TEST_CASE( "Test", "[ArrayList]" ) {

  ArrayList<int> list;
}

//Test Case to see if the insert and getLength is working properly
TEST_CASE( "Test Insert Function with getLength function", "[ArrayList]")
{
  ArrayList<int> list;
  list.insert(0, 1);
  list.insert(1, 2);
  REQUIRE(list.getLength() == 2);
}

//Test Case to see if the remove and getLength is working properly
TEST_CASE( "Test Remove Function with getLength function", "[ArrayList]")
{
  ArrayList<int> list;
  list.insert(0, 1);
  list.remove(0);
  REQUIRE(list.getLength() == 0);
}

//Test Case to see if the insert, remove and isEmpty is working properly
TEST_CASE( "Test Remove Function with isEmpty function", "[ArrayList]")
{
  ArrayList<int> list;
  list.insert(0, 1);
  list.remove(0);
  REQUIRE(list.isEmpty() == 1);
}

//Test Case to see if the insert, clear and isEmpty is working properly
TEST_CASE( "Test Remove Function with isEmpty/clear function", "[ArrayList]")
{
  ArrayList<int> list;
  list.insert(0, 1);
  list.clear();
  REQUIRE(list.isEmpty() == 1);
}

//Test Case to see if the insert and getEntry is working properly
TEST_CASE( "Test Insert Function with getEntry function", "[ArrayList]")
{
  ArrayList<int> list;
  list.insert(0, 10);
  REQUIRE(list.getEntry(0) == 10);
}

//Test Case to see if the insert, setEntry, and getEntry is working properly
TEST_CASE( "Test Insert Function with setEntry/getEntry function", "[ArrayList]")
{
  ArrayList<int> list;
  list.insert(0, 10);
  list.setEntry(0, 200);
  REQUIRE(list.getEntry(0) == 200);
}

//Test Case to see if the Copy Constructor is working properly
TEST_CASE("Test Copy Constructor Function", "[ArrayList]") {
  ArrayList<int> list;
  list.insert(0, 200);
  list.insert(1, 300);
  ArrayList<int> list2 = list;
  REQUIRE(list.getLength() == list2.getLength());
  REQUIRE(list2.getEntry(0) == 200);
  REQUIRE(list2.getEntry(1) == 300);
}