//  Adapated from Frank M. Carrano and Timothy M. Henry.

/** ADT Stack implementation.
    @file Stack.cpp */

#include <iostream>
#include <cstddef>
#include "Stack.hpp"
#include "Node.hpp"

// TODO: Implement the constructor here
template<class ItemType>
Stack<ItemType>::Stack() : currentSize(0), headPtr(nullptr)
{
}  // end default constructor

// TODO: Implement the destructor here
template<class ItemType>
Stack<ItemType>::~Stack()
{
	// Destructor to clear all of the values in the variables declared
	clear();
}  // end destructor

// TODO: Implement the isEmpty method here
template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{
	// Returning the bool value correspsonding to if the stack is empty or not
	return currentSize == 0;
}  // end isEmpty

// TODO: Implement the size method here
template<class ItemType>
int Stack<ItemType>::size() const
{
	// Returning the value of the size of the stack
	return currentSize;
}  // end size

// TODO: Implement the push method here
template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newItem)
{
	// Making a new node pointer and putting the needed variables in the parameters
	Node<ItemType>* ptr = new Node<ItemType>(newItem, headPtr);

	// Setting the headPtr to the new pointer declared to make it the top element
	headPtr = ptr;

	// Incrementing the current size
	currentSize++;
	
	// Returning the bool value of true
	return true;
}  // end push

// TODO: Implement the peek method here
template<class ItemType>
ItemType Stack<ItemType>::peek() const
{
	// Throwing an exception to see if there are elements left in the stack to peek (GOT IDEA FROM EXAM 1 QUESTION REGARDING THIS)
	if(currentSize == 0)
	{
		throw std::logic_error("No more elements left in the stack");
	}
	// Returning the top element of the stack without removing that element
	return (headPtr->getItem());
}  // end peek

// TODO: Implement the pop method here
template<class ItemType>
bool Stack<ItemType>::pop() 
{
	if (currentSize <= 0 || headPtr == nullptr)
	{
		return false;
	}

	// Making a new node pointer and putting the needed variables in the parameters
	Node<ItemType>* ptr = headPtr;

	// Setting the headPtr to the new pointer declared to make it the top element
	headPtr = headPtr->getNext();

	// Deleting the top element of the stack
	delete ptr;

	// Incrementing the current size
	currentSize--;


	// Returning the bool value of true
	return true;
}  // end pop

// TODO: Implement the clear method here
template<class ItemType>
void Stack<ItemType>::clear()
{
	// Resetting (clearing) all of the variable values
	Node<ItemType>* ptr = headPtr;

	while (ptr != nullptr)
	{
		ptr = headPtr;

		ptr = ptr->getNext();

		delete headPtr;

		headPtr = ptr;
	}

	currentSize = 0;
	headPtr = nullptr;
}  // end clear
