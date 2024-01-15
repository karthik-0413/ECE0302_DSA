#ifndef _ABSTRACT_BAG_HPP_
#define _ABSTRACT_BAG_HPP_

#include <cstdlib>

template <typename T>
class AbstractBag
{
    public:
        /**
         * @details This function is an accessor function to get the size of the bag
         * @return The function returns the size of the bag
        */
        virtual std::size_t getCurrentSize() const = 0;

        /**
         * @details This function decides whether or not the bag is empty 
         * @return The function returns the validity of if the bag is empty or not
        */

        virtual bool isEmpty() const = 0;

        /**
         * @details This function adds an item to the bag
         * @return The function returns the size of the bah
         * @param add_item The function has a parameter to add things into the bag
        */

        virtual bool add(const T& entry) = 0;

        /**
         * @details This function removes an item to the bag
         * @return The function returns the size of the bah
         * @param remove_item The function has a parameter to remove things into the bag
        */

        virtual bool remove(const T& entry) = 0;

        /**
         * @details The function clears the entire bag
        */

        virtual void clear() = 0;

        /**
         * @details This function gets the frequency of an item in the bag
         * @return The function returns the frequency of a certain item in the bag
         * @param remove_item The function has a parameter know which item it is taking the frequency of
        */

        virtual std::size_t getFrequencyOf(const T& entry) const = 0;

        /**
         * @details This function sees if the item in the param is in the bag or not
         * @return The function returns the validity of if a certain item is in the bag
         * @param remove_item The function has a parameter to check if a certain item is in the bag
        */

        virtual bool contains(const T& entry) const = 0;

};


#endif