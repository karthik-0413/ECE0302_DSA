#include "bitset.hpp"
#include <iostream>

//Default Constructor
Bitset::Bitset() {
    SIZE = 8;
    
    //Allocating memory for bit vector
    bitvec = new u_int8_t[SIZE];

    //Initializing all bits to 0
    for (int i = 0; i < SIZE; i++)
    {
        *(bitvec + i) = 0;
    }

    result = true;
}

//Parameterized Contructor
Bitset::Bitset(intmax_t size) {

    //Checking validty of bit vector
    if (size <= 0)
    {
        result = false;
    }
    else
    {
        //Allocating memory for bit vector
        SIZE = size;
        bitvec = new u_int8_t[SIZE];

        //Initializing all bits to 0
        for (int i = 0; i < SIZE; i++)
            {
                *(bitvec + i) = 0;
            }

        result = true;
    }
}

//Parameterized Contructor
Bitset::Bitset(const std::string & value) {

    result = true;

    //Getting the size of the bit vector in the parameter
    SIZE = value.length();

    //Allocating memory for bit vector
    bitvec = new u_int8_t[SIZE];

    //Checking if all of the characters in the string are 0's or 1's
    for (int i = 0; i < SIZE; i++)
    {
        //if (bit != '0' && bit != '1')
        if (value[i] != '0' && value[i] != '1')
        {
            result = false;
        }
        else
        {
            if (value[i] == '1')
            {
                *(bitvec + i) = 1;
            }
            else
            {
                *(bitvec + i) = 0;
            }
        }
    }
    
}

//Destructor of Allocated Memory
Bitset::~Bitset() {
    delete[] bitvec;
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

//Member Function that sets the nth bit to 1 (if the bitset is valid)
void Bitset::set(intmax_t index)
{
    //n shuold be between [0, N-1]
    if (index >= SIZE)
    {
        result = false;
    }

    //n shuold be between [0, N-1]
    else if (index < 0)
    {
        result = false;
    }

    else
    {
        //nth bit is 1
        bitvec[index] = 1;
        result = true;
    }

}

//Member Function that sets the nth bit to 0 (if the bitset is valid)
void Bitset::reset(intmax_t index)
{
    //n shuold be between [0, N-1]
    if (index >= SIZE)
    {
        result = false;
    }

    //n shuold be between [0, N-1]
    else if (index < 0)
    {
        result = false;
    }

    else
    {
        //nth bit is 1
        *(bitvec + index) = 0;
        result = true;
    }
}

//Member Function that changes the nth bit from 1 to 0 OR from 0 to 1
void Bitset::toggle(intmax_t index)
{
    //n shuold be between [0, N-1]
    if (index >= SIZE)
    {
        result = false;
    }

    //n shuold be between [0, N-1]
    else if (index < 0)
    {
        result = false;
    }

    else
    {
        //Figuring out which bit to toggle to (from 1 to 0 OR 0 to 1)
        if (bitvec[index] == 0)
        {
            bitvec[index] = 1;
            result = true;
        }
        else if (bitvec[index] == 1)
        {
            bitvec[index] = 0;
            result = true;
        }
    }
}

//Member Function that returns true is the nth bit has been set and false if not
bool Bitset::test(intmax_t index)
{
    //n shuold be between [0, N-1]
    if (index >= SIZE)
    {
        result = false;
        return result;
    }

    //n shuold be between [0, N-1]
    else if (index < 0)
    {
        result = false;
        return result;
    }

    else
    {
        result = true;

        //Returning the valdity of the nth bit of the bit vector
        return bitvec[index] == 1;
    }


}

//Member Function that returns the bitset as characters of a string
std::string Bitset::asString() const
{   
    std::string final = "";

    for (int i = 0; i < SIZE; i++)
    {
        final += std::to_string((*(bitvec + i)));
    }

    return final;

}
