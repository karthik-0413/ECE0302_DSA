#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "list.hpp"
#include "sorted_list.hpp"
#include "priority_queue.hpp"

// *****************************
//  PRIORITY QUEUE TEST CASES  *
// *****************************

// Test case to check if add, peek, and isEmpty functions are working properly
TEST_CASE("Testing Priority Queue1", "[priority queue]") {
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;
  pq.add(15);

  REQUIRE(pq.isEmpty() == false);
  REQUIRE(pq.peek() == 15);
}

// Test case to check if remove and isEmpty functions are working properly
TEST_CASE("Testing Priority Queue2", "[priority queue]") {
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;
  pq.add(15);
  pq.remove();

  REQUIRE(pq.isEmpty() == true);
}

// Test case to check if add, remove, and peek functions are working properly
TEST_CASE("Testing Priority Queue3", "[priority queue]") {
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;
  pq.add(15);
  pq.add(13);
  pq.add(17);
  pq.remove();

  REQUIRE(pq.peek() == 15);
}

// Test case to check if add, remove, and peek functions are working properly
TEST_CASE("Testing Priority Queue4", "[priority queue]") {
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;
  pq.add(100);
  pq.add(800);
  pq.add(120);
  pq.remove();
  pq.remove();

  REQUIRE(pq.peek() == 100);
}

// Test case to check if add, peek, and isEmpty functions are working properly
TEST_CASE("Testing Priority Queue5", "[priority queue]") {
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;
  pq.add(15);
  pq.add(13);
  pq.add(17);

  REQUIRE(pq.isEmpty() == false);
  REQUIRE(pq.peek() == 17);
}

// **************************
//  SORTED LIST TEST CASES  *
// **************************

// Testing to see if the insert and remove functions work with characters
TEST_CASE("Testing Sorted List1", "[priority queue]") {
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  SortedListType lst;

  lst.insert('a');
  REQUIRE(!lst.isEmpty());

  lst.remove('a');
  REQUIRE(lst.isEmpty());
}

// Testing to see if the insert and removeAt functions work with integers
TEST_CASE("Testing Sorted List2", "[priority queue]") {
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  SortedListType lst;

  lst.insert(1);
  REQUIRE(!lst.isEmpty());

  lst.removeAt(0);
  REQUIRE(lst.isEmpty());
}

// Testing to see if the insert and getPosition functions work with characters
TEST_CASE("Testing Sorted List3", "[priority queue]") {
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  SortedListType lst;

  lst.insert('d');
  lst.insert('r');
  lst.insert('q');
  lst.insert('t');
  lst.insert('b');
  REQUIRE(lst.getPosition('d') == 1);
}

// Testing to see if the insert, remove, and removeAt functions work
// Testing to see if the list is empty after and an exception is thrown when trying to remove an item when it is empty
TEST_CASE("Testing Sorted List4", "[priority queue]") {
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  SortedListType lst;

  lst.insert('a');
  lst.insert('b');
  lst.insert('c');
  lst.remove('a');
  lst.remove('b');
  lst.remove('c');
  REQUIRE(lst.isEmpty() == 1);
  CHECK_THROWS_AS(lst.removeAt(0), std::range_error);
}

// Testing to see if the insert, clear, and removeAt functions work
// Testing to see if the list is empty after and an exception is thrown when trying to remove an item when it is empty
TEST_CASE("Testing Sorted List5", "[priority queue]") {
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  SortedListType lst;

  lst.insert('a');
  lst.insert('b');
  lst.insert('c');
  lst.clear();
  REQUIRE(lst.isEmpty() == 1);
  CHECK_THROWS_AS(lst.removeAt(0), std::range_error);
}

// Testing to see if the insert and the getPosition when the number is not in the list
TEST_CASE("Testing Sorted List6", "[priority queue]") {
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  SortedListType lst;

  lst.insert('a');
  lst.insert('b');
  lst.insert('c');
  REQUIRE(lst.getPosition('d') == -1);
  REQUIRE(lst.getPosition('a') == 0);
  REQUIRE(lst.getPosition('c') == 2);
  REQUIRE(lst.getPosition('b') == 1);
  REQUIRE(lst.getPosition('e') == -1);
}

// Testing to see if the insert and the getEntry functions work preperly
TEST_CASE("Testing Sorted List7", "[priority queue]") {
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  SortedListType lst;

  lst.insert('a');
  lst.insert('b');
  lst.insert('c');
  REQUIRE(lst.getEntry(0) == 'a');
}

// Testing to see if the insert and the getEntry functions work preperly
// SAME AS ABOVE BUT CHECKING TO SEE WHEN THE SORTEDLINKEDLIST CAN HANDLE DIFFERENT DATA TYPES
TEST_CASE("Testing Sorted List8", "[priority queue]") {
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  SortedListType lst;

  lst.insert(1);
  lst.insert(2);
  lst.insert(3);
  REQUIRE(lst.getEntry(0) == 1);
}