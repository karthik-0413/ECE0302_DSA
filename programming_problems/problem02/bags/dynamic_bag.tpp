#include "dynamic_bag.hpp"

// default constructor
template<typename T>
DynamicBag<T>::DynamicBag() {
  size = 0;
  things = nullptr;
}
  
// copy constructor
template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag<T>& x){
  size = x.size;
  things = new T[size];

  for(int i = 0; i < size; i++)
  {
    *(things + i) = x.things[i];
  }
}
    
// destructor
template<typename T>
DynamicBag<T>::~DynamicBag(){delete[] things;}
  
// copy assignment
template<typename T>
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T> x)
{ 
  if(this != &x)
  {
    T* temp = new T[x.size];
    for (int i = 0; i < size; i++)
    {
      *(temp + i) = x.things[i];
    }
    things = nullptr;
    things = temp;

    size = x.size;
  }
  return *this;
}

// swap for copy swap idiom
template<typename T>
void DynamicBag<T>::swap(DynamicBag<T>& x){
  T* temp = things;
  things = x.things;
  x.things = temp;

  std::size_t temp2 = size;
  size = x.size;
  x.size = temp2;
}

// add an item to the bag
template<typename T>
bool DynamicBag<T>::add(const T& item)
{
  T* new2 = new T[size + 1];
  for (int i = 0; i < size; i++)
    {
      *(new2 + i) = things[i];
    }
  *(new2 + size) = item;
  delete[] things;
  things = new2;
  ++size;
  return true;
}

// remove an item
template<typename T>
bool DynamicBag<T>::remove(const T& item)
{
  if (size == 0)
    return false;

  std::size_t idx = 0;
  for(std::size_t i = 0; i < size; ++i){
    if(things[i] == item) break;
    ++idx;
  }

  if(idx == size) return false;

  --size;
  for(std::size_t i = idx; i < size; ++i){
    things[i] = things[i+1];
  }

  return true;
}

// check is the bag is empty
template<typename T>
bool DynamicBag<T>::isEmpty() const
{
  return (size == 0);
}

// get number of items in the bag
template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{
  return size;
}

// check if item is in the bag
template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{  
  return (getFrequencyOf(item) != 0);
}

// clear the bag contents
template<typename T>
void DynamicBag<T>::clear(){size = 0;}

// count how many time item occurs in bag
template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{
  std::size_t freq = 0;

  for(std::size_t i = 0; i < size; ++i){
    if(things[i] == item) ++freq;
  }
  
  return freq;
};
