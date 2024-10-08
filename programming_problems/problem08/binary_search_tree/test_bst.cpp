#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "binary_search_tree.hpp"

typedef BinarySearchTree<int, int> TreeType;

TEST_CASE("Test Construction", "[construction]") {
    TreeType bst1;

    REQUIRE(bst1.isEmpty());
}

TEST_CASE("Test Insert", "[insert]") {
    TreeType bst1;

    bst1.insert(10, 10);
    REQUIRE(!bst1.isEmpty());
}

TEST_CASE("Test Duplicate Insert", "[duplicate insert]") {
    TreeType bst1;
    
    bst1.insert(12, 12);
    REQUIRE(!bst1.insert(12, 12));
}

TEST_CASE("Test Retrieve", "[retrieve]") {
    TreeType bst1;

    bst1.insert(10, 10);
    bst1.insert(5, 5);
    bst1.insert(15, 15);
    bst1.insert(12, 12);
    bst1.insert(18, 18);

    int item;
    REQUIRE(bst1.retrieve(18, item));
    REQUIRE(bst1.retrieve(12, item));
    REQUIRE(bst1.retrieve(15, item));
    REQUIRE(bst1.retrieve(5, item));
    REQUIRE(bst1.retrieve(10, item));
}

TEST_CASE("Test Remove", "[remove]") {
    TreeType bst1;

    bst1.insert(10, 10);
    bst1.insert(5, 5);
    bst1.insert(15, 15);
    bst1.insert(12, 12);
    bst1.insert(18, 18);

    int item;

    bst1.remove(12);
    REQUIRE(!bst1.retrieve(12, item));

    bst1.remove(18);
    REQUIRE(!bst1.retrieve(18, item));

    bst1.remove(5);
    REQUIRE(!bst1.retrieve(5, item));

    bst1.remove(10);
    REQUIRE(!bst1.retrieve(10, item));

    bst1.remove(15);
    REQUIRE(!bst1.retrieve(15, item));

    REQUIRE(bst1.isEmpty());
}

TEST_CASE("Test Copy Assign", "[copy assign]") {
    TreeType bst1;

    bst1.insert(50, 50);
    bst1.insert(0, 0);
    bst1.insert(100, 100);
    bst1.insert(25, 25);
    bst1.insert(75, 75);

    TreeType bst2;

    bst2 = bst1;

    REQUIRE(!bst2.isEmpty());

    int item;
    REQUIRE(bst2.retrieve(100, item));
    REQUIRE(bst2.retrieve(75, item));
    REQUIRE(bst2.retrieve(50, item));
    REQUIRE(bst2.retrieve(25, item));
    REQUIRE(!bst2.retrieve(51, item));
    
}

// **********************************
// PERSONAL TEST CASES FOR TREESORT *
// **********************************

// Test case to make sure that sorting is in ascending order
TEST_CASE("Test Tree Sort1", "[treeSort]")
{
    int arr[] = {6, 5, 4, 3, 2, 1};
    int size = 6;

    TreeType bst1;

    bst1.treeSort(arr, size);

    REQUIRE(arr[0] == 1);
    REQUIRE(arr[1] == 2);
    REQUIRE(arr[2] == 3);
    REQUIRE(arr[3] == 4);
    REQUIRE(arr[4] == 5);
    REQUIRE(arr[5] == 6);
}

// Test Case to make sure no duplicates
TEST_CASE("Test Tree Sort2", "[treeSort]")
{
    int arr[] = {6, 6, 5, 5, 1};
    int size = 5;

    TreeType bst1;

    bst1.treeSort(arr, size);

    REQUIRE(arr[0] == 1);
    REQUIRE(arr[1] == 5);
    REQUIRE(arr[2] == 6);
}
