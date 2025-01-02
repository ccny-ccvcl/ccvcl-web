// FILE: set.h (part of the namespace main_savitch_11)
// TEMPLATE CLASS PROVIDED: set<Item>
//   (a container template class for a set of items)
//
// TYPEDEFS for the set<Item> class:
//   set<Item>::value_type
//     set<Item>::value_type is the data type of the items in the set. It may be
//     any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, a copy constructor, an assignment operator, and a
//     less-than operator forming a strict weak ordering.
//
// CONSTRUCTOR for the set<Item> class:
//   set( )
//     Postcondition: The set is empty.
//
// MODIFICATION MEMBER FUNCTIONS for the set<Item> class:
//   void clear( )
//     Postcondition: The set is empty.
//
//   bool insert(const Item& entry)
//     Postcondition: If an equal entry was already in the set, the set is
//     unchanged and the return value is false. Otherwise, entry was added
//     to the set and the return value is true. This is slightly different than
//     the C++ Standard Library set (see Appendix H).
//
//   size_t erase(const Item& target)
//     Postcondition: If target was in the set, then it has been removed from
//     the set and the return value is 1. Otherwise the set is unchanged and the
//     return value is zero.
//
// CONSTANT MEMBER FUNCTIONS for the Set<Item> class:
//   size_t count(const Item& target) const
//     Postcondition: Returns the number of items equal to the target
//     (either 0 or 1 for a set).
//
//  bool empty( ) const 
//     Postcondition: Returns true if the set is empty; otherwise returns false.
//
// VALUE SEMANTICS for the set<Item> class:
//   Assignments and the copy constructor may be used with set<Item> objects.
//
// DYNAMIC MEMORY USAGE by the set<Item> class:
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc: 
//   The constructors, insert, and the assignment operator.

#ifndef MAIN_SAVITCH_SET_H
#define MAIN_SAVITCH_SET_H
#include <cstdlib>   // Provides size_t

namespace main_savitch_11
{
    template <class Item>
    class set
    {
    public:
        // TYPEDEFS
        typedef Item value_type;
        // CONSTRUCTORS and DESTRUCTOR
        set( );
        set(const set& source);
        ~set( ) { clear( ); }
        // MODIFICATION MEMBER FUNCTIONS
        void operator =(const set& source);
        void clear( );
        bool insert(const Item& entry);
        std::size_t erase(const Item& target);
        // CONSTANT MEMBER FUNCTIONS
        std::size_t count(const Item& target) const;
        bool empty( ) const { return (data_count == 0); }
        // SUGGESTED FUNCTION FOR DEBUGGING
        void print(int indent) const;
    private:
        // MEMBER CONSTANTS
        static const std::size_t MINIMUM = 200;
        static const std::size_t MAXIMUM = 2 * MINIMUM;
        // MEMBER VARIABLES
        std::size_t data_count;
        Item data[MAXIMUM+1];
        std::size_t child_count;
        set *subset[MAXIMUM+2];
        // HELPER MEMBER FUNCTIONS
        bool is_leaf( ) const { return (child_count == 0); }
        bool loose_insert(const Item& entry);
        bool loose_erase(const Item& target);
        void remove_biggest(Item& removed_entry);
        void fix_excess(std::size_t i);
        void fix_shortage(std::size_t i);
        // NOTE: The implementor may want to have additional helper functions
      };
}
#include "set.template" // Include the implementation.

#endif
