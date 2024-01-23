#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "limited_size_bag.hpp"

// force template expansion for ints
template class LimitedSizeBag<int>;

//Checking if the member functions are able to be called
TEST_CASE("Calling all public members", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  b.add(0);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.clear();
  b.getFrequencyOf(0);
  b.contains(0);

}

//Test Case to see if the Copy Constructor is working properly
TEST_CASE("Test Copy Constructor Function", "[LimitedSizeBag]") {
  LimitedSizeBag<int> b;
  b.add(200);
  b.add(300);
  LimitedSizeBag<int> a = b;
  REQUIRE(b.getCurrentSize() == a.getCurrentSize());
}

//Test Case to see if the Copy Assignment is working properly
TEST_CASE("Test Copy Assignment Function", "[LimitedSizeBag]") {
  LimitedSizeBag<int> b;
  b.add(200);
  b.add(300);
  LimitedSizeBag<int> a;
  a = b;
  REQUIRE(a.contains(200));
  REQUIRE(a.contains(200));
  REQUIRE(b.getCurrentSize() == a.getCurrentSize());
}

//Test Case to see if the Remove Function is working properly
TEST_CASE("Test Remove Function", "[LimitedSizeBag]") {
  LimitedSizeBag<int> b;
  b.add(200);
  b.remove(200);
  REQUIRE(!b.contains(200));
}

//Test Case to see if the Add Function is working properly
TEST_CASE("Test Add Function", "[LimitedSizeBag]") {
  LimitedSizeBag<int> b;
  b.add(200);
  REQUIRE(b.contains(200));
}

//Test Case to see if the Clear Function is working properly
TEST_CASE("Test Clear Function", "[LimitedSizeBag]") {
  LimitedSizeBag<int> b;
  b.add(200);
  b.clear();
  REQUIRE(b.isEmpty());
  REQUIRE(b.getCurrentSize() == 0);
}

//Test Case to see if the getCurrentSize Function is working properly
TEST_CASE("Test getCurrentSize Function", "[LimitedSizeBag]") {
  LimitedSizeBag<int> b;
  b.add(1);
  b.add(2);
  b.add(3);
  REQUIRE(b.getCurrentSize() == 3);
}

//Test Case to see if the getFrequencyOf Function is working properly
TEST_CASE("Test getFrequencyOf Function", "[LimitedSizeBag]") {
  LimitedSizeBag<int> b;
  b.add(1);
  b.add(1);
  b.add(1);
  REQUIRE(b.getFrequencyOf(1) == 3);
}