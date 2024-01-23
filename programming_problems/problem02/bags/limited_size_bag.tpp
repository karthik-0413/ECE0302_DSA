#include "limited_size_bag.hpp"

// default constructor
template<typename T>
LimitedSizeBag<T>::LimitedSizeBag() : size(0) {}
  
// add an item to the bag
template<typename T>
bool LimitedSizeBag<T>::add(const T& item)
{
  if(size >= maxsize){
    return false;
  }

  data[size] = item;
  ++size;
  
  return true;
}

// remove an item
template<typename T>
bool LimitedSizeBag<T>::remove(const T& item)
{
  if(size == 0) return false;

  std::size_t idx = 0;
  for(std::size_t i = 0; i < size; ++i){
    if(data[i] == item) break;
    ++idx;
  }

  if(idx == size) return false;

  --size;
  for(std::size_t i = idx; i < size; ++i){
    data[i] = data[i+1];
  }

  return true;
}

// check is the bag is empty
template<typename T>
bool LimitedSizeBag<T>::isEmpty() const
{ return (size == 0); }

// get number of items in the bag
template<typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const
{
  return size;
}

// check if item is in the bag
template<typename T>
bool LimitedSizeBag<T>::contains(const T& item) const
{  
  return (getFrequencyOf(item) != 0);
}

// clear the bag contents
template<typename T>
void LimitedSizeBag<T>::clear(){size = 0;}

// count how many time item occurs in bag
template<typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T & item) const
{
  std::size_t freq = 0;

  for(std::size_t i = 0; i < size; ++i){
    if(data[i] == item) ++freq;
  }
  
  return freq;
};
