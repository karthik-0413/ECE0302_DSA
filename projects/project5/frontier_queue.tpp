#include "frontier_queue.hpp"

// TODO implement the member functions here

template <typename T>
State<T> frontier_queue<T>::pop() {

  //TODO
  
  //implement this the same way we implemented pop in the heap lecture. Compare using getFCost

  // needs return statement

  // 1. Replace root with last node
  std::swap(queue[0], queue[queue.size() - 1]);

  // 2. Remove root
  queue.pop_back();

  State<T> return2;

  // For-Loop that iterates through the queue
  for (int i = 0; i < queue.size(); i++)
  {
    // Declaring left and right ints as defined in the lecture notes
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If-Else statement that checks what value the index of queue should be
    // If the left cost is smaller than the index cost
    if (queue[left] < queue[i])
    {
      std::swap(queue[left], queue[i]);
    }
    // Else if the right cost is greater than the index cost
    else if (queue[right] > queue[i])
    {
      std::swap(queue[right], queue[i]);
    }
  }

  // Returning the state
  return return2;
}

template <typename T>
void frontier_queue<T>::push(const T &p, std::size_t cost, std::size_t heur) {

  //TODO
  
  //implement this the same way we implemented push in the heap lecture.


}

template <typename T>
bool frontier_queue<T>::empty() {

  return queue.size() == 0;

}

template <typename T> 
bool frontier_queue<T>::contains(const T &p) {

  for (State<T> thing : queue)
  {
    if (thing.getValue() == p)
    {
      return true;
    }
  }

  return false;

}

template <typename T>
void frontier_queue<T>::replaceif(const T &p, std::size_t cost) {

  //TODO

}


