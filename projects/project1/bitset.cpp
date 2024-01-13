#include "bitset.hpp"

//Default Constructor
Bitset::Bitset() {
    SIZE = 8;

    bitvec = new u_int8_t[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        *(bitvec + i) = 0;
    }
}

//Parameterized Contructor
Bitset::Bitset(intmax_t size) {

    if (SIZE < 0)
    {
        result = false;
    }
    else
    {
        SIZE = 8;

        bitvec = new u_int8_t[SIZE];

        for (int i = 0; i < SIZE; i++)
            {
                *(bitvec + i) = 0;
            }

        result = true;
    }
}

//Parameterized Contructor
Bitset::Bitset(const std::string & value) {
    for (char bit : value)
    {
        if (bit != 0 && bit != 1)
        {
            result = false;
        }
    }

    SIZE = value.length();

    bitvec = new u_int8_t[SIZE];

    for (int i = 0; i < SIZE; i++)
        {
            if (i == 3)
            {
               *(bitvec + i) = 1; 
            }
            else
            {
                *(bitvec + i) = 0;
            }
        }
    
    result = true;
}

//Destructor of Allocated Memory
Bitset::~Bitset() {
    delete [] bitvec;
}

//Accessor Function to get the size of the bit vector
intmax_t Bitset::size() const
{
    return SIZE;
}

//Accessor Function to check if the bit vector is valid or not
bool Bitset::good() const
{
    return result;
}

void Bitset::set(intmax_t index)
{
    if (index >= SIZE)
    {
        result = false;
    }

    if (index < 0)
    {
        result = false;
    }

    bitvec[index] = 1;
}

void Bitset::reset(intmax_t index)
{
    if (index >= SIZE)
    {
        result = false;
    }

    if (index < 0)
    {
        result = false;
    }

    bitvec[index] = 0;
}

void Bitset::toggle(intmax_t index)
{
    if (index >= SIZE)
    {
        result = false;
    }

    if (index < 0)
    {
        result = false;
    }

    if (bitvec[index] == 0)
    {
        bitvec[index] = 1;
    }
    else if (bitvec[index] == 1)
    {
        bitvec[index] = 0;
    }
}

bool Bitset::test(intmax_t index)
{
    if (index >= SIZE)
    {
        result = false;
        return result;
    }

    if (index < 0)
    {
        result = false;
        return result;
    }

    return bitvec[index] == 1;
}

std::string Bitset::asString() const
{

}