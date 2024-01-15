#ifndef BITSET_HPP
#define BITSET_HPP
#include <stdint.h>
#include <stdlib.h>
#include <string>

class Bitset{
public:

  // Default Constructor of Class
  Bitset();

  // Parameterized Contructor of Class
  Bitset(intmax_t size);

  // Parameterized Contructor of Class
  Bitset(const std::string & value);

  // Destructor
  ~Bitset();

  //Deleted Member Functions
  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  // Returns the size of the bit vector
  intmax_t size() const;

  // Returns the bool value on if the bit vector is valid or not
  bool good() const;

  // If the bit vector is valid, then this function will set the nth bit to 1
  void set(intmax_t index);

  // If the bit vector is valid, then this function will set the nth bit to 0
  void reset(intmax_t index);

  // Function that toggles the nth bit from 1 to 0 or 0 to 1
  void toggle(intmax_t index);

  // Function that checks the validity of the nth bit being set to 1
  bool test(intmax_t index);

  // Function that returns the bitset as a string of characters
  std::string asString() const;

private:

  //Declaring needed variables for the program
  intmax_t SIZE;
  u_int8_t *bitvec;
  bool result;

};

#endif
