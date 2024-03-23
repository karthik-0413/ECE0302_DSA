#include "queue.hpp"

template <typename T, typename L>
void Queue<T,L>::enqueue(const T& item)
{
  // Inserting the item in the parameter in the end of the queue
  internal_list.insert(0,item);
}

template <typename T, typename L>
void Queue<T,L>::dequeue()
{
  // If the queue is empty, then throw exception
  if (isEmpty())
  {
    throw std::range_error("CANNOT");
  }
  // Removing the item the first item in the queue
  internal_list.remove(internal_list.getLength()-1);
}

template <typename T, typename L>
T Queue<T,L>::peekFront()
{
  // If the queue is empty, then throw exception
  if (isEmpty())
  {
    throw std::range_error("CANNOT");
  }
  // Getting the last item in the list without removing it
  return internal_list.getEntry(internal_list.getLength()-1);
}

template <typename T, typename L>
bool Queue<T,L>::isEmpty() const
{
  // Seeing if the queue is empty and returning the bool value corresponding to that
  return internal_list.isEmpty();
}

