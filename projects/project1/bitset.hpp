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

  // TODO COMMENT
  ~Bitset();

  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  // Returns the size of the bit vector
  intmax_t size() const;

  // TODO COMMENT
  bool good() const;

  // TODO COMMENT
  void set(intmax_t index);

  // TODO COMMENT
  void reset(intmax_t index);

  // TODO COMMENT
  void toggle(intmax_t index);

  // TODO COMMENT
  bool test(intmax_t index);

  // TODO COMMENT
  std::string asString() const;

private:

  intmax_t SIZE;
  u_int8_t *bitvec;
  bool result;

};

#endif
