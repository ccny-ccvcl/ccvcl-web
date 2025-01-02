// FILE: queue1.h (part of the namespace main_savitch_8B)
// TEMPLATE CLASS PROVIDED: queue<Item> (a queue of items)
//
// TEMPLATE PARAMETER, TYPEDEFS and MEMBER CONSTANTS for the stack<Item> class:
//   The template parameter, Item, is the data type of the items in the queue,
//   also defined as queue<Item>::value_type. It may be any of the C++ built-in
//   types (int, char, etc.), or a class with a default constructor, a copy
//   constructor, and an assignment operator. The definition
//   queue<Item>::size_type is the data type of any variable that keeps track of
//   how many items are in a queue. The static const CAPACITY is the
//   maximum capacity of a queue for this first queue implementation.
// NOTE:
//   Many compilers require the use of the new keyword typename before using
//   the expressions queue<Item>::value_type and queue<Item>::size_type.
//   Otherwise the compiler doesn't have enough information to realize that it
//   is the name of a data type.
//
// CONSTRUCTOR for the queue<Item> template class:
//   queue( )
//     Postcondition: The queue has been initialized as an empty queue.
//
// MODIFICATION MEMBER FUNCTIONS for the queue<Item> template class:
//   void pop( )
//     Precondition: size( ) > 0.
//     Postcondition: The front item of the queue has been removed.
//
//   void push(const Item& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been inserted at the rear of the
//     queue.
//
// CONSTANT MEMBER FUNCTIONS for the queue<Item> template class:
//   bool empty( ) const
//     Postcondition: The return value is true if the queue is empty.
//
//   Item front( ) const
//     Precondition: size( ) > 0.
//     Postcondition: The return value is the front item of the queue (but the queue is
//     unchanged). 
//
//   size_type size( ) const
//     Postcondition: The return value is the total number of items in the queue.
//
// VALUE SEMANTICS for the queue<Item> template class:
//   Assignments and the copy constructor may be used with queue<Item> objects.

#ifndef MAIN_SAVITCH_QUEUE1_H
#define MAIN_SAVITCH_QUEUE1_H
#include <cstdlib> // Provides size_t

namespace main_savitch_8B
{
    template <class Item>
    class queue
    {
    public:
        // TYPEDEFS and MEMBER CONSTANTS -- See Appendix E if this fails to compile.
        typedef std::size_t size_type;
        typedef Item value_type;
        static const size_type CAPACITY = 30;
        // CONSTRUCTOR
        queue( );
        // MODIFICATION MEMBER FUNCTIONS
        void pop( );
        void push(const Item& entry);
        // CONSTANT MEMBER FUNCTIONS
        bool empty( ) const { return (count == 0); }
        	Item front( ) const;
        	size_type size( ) const { return count; }
    private:
        Item data[CAPACITY];     // Circular array
        size_type first;         // Index of item at front of the queue
        size_type last;          // Index of item at rear of the queue
        size_type count;         // Total number of items in the queue
        // HELPER MEMBER FUNCTION
        size_type next_index(size_type i) const { return (i+1) % CAPACITY; }
    };
}

#include "queue1.template" // Include the implementation.
#endif
