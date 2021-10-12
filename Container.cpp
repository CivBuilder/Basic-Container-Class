/// @file Container.cpp
/// @author Chris Catechis
/// @date 6/11/21
/// @brief This program hosts out of line functions for the Container
/// class. 


#include "Container.h"
#include <iostream>
#include <cassert>

/// Inserts an item into the container.
/// Internally, the items are not maintained in any particular order.
/// @pre size() < CAPACITY
/// @param value Element value to insert.
void Container::insert(const value_type& value) {

    assert(size() < CAPACITY);

    data[used] = value;
    used++;
}

/// Removes all items from the container equal to the target value.
/// Internally, the items are not maintained in any particular order.
/// @param target Key value of the items to remove.
void Container::erase(const value_type& target) {
    size_type index;  // location of target in the array

    for (size_type i = 0; i < used; i++) {
        if (data[i] == target) {
            index = i;

            data[index] = data[used - 1];

            used--;
        }
    }
}

/// Returns the number of items equal to the target.
/// @param target Key value of the item(s) to count.
/// @returns Number of items with value equal to the target.
Container::size_type Container::count(const value_type& target) const {
    size_type num = 0;  // holds the count

    for (size_type i = 0; i < used; i++) {
        if (data[i] == target) {
            num++;
        }
    }

    return num;
}

/// Writes all items to an output stream in the format: {42,73,0,-59,7}
/// @param output The output stream (defaults to std::cout).
void Container::write(std::ostream& output) {
    output << '{';

    for (size_type i = 0; i < used; i++) {
        output << data[i];

        if (i < used - 1) {
            output << ',';
        }
    }

    output << '}';
}
