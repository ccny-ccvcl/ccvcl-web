// FILE: queue2.h (part of the namespace
// TEMPLATE CLASS PROVIDED: queue<Item> (a queue of items)
//
// TEMPLATE PARAMETER, TYPEDEFS and MEMBER CONSTANTS for the stack<Item> class:
//   The template parameter, Item, is the data type of the items in the queue,
//   also defined as queue<Item>::value_type. It may be any of the C++ built-in
//   types (int, char, etc.), or a class with a default constructor, a copy
//   constructor, and an assignment operator. The definition
//   queue<Item>::size_type is the data type of any variable that keeps track of
//   how many items are in a queue.
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
//     Postcondition: A new copy of entry has been inserted at the rear of the
//     queue.
//
// CONSTANT MEMBER FUNCTIONS for the queue<Item> template class:
//   bool empty( ) const
//     Postcondition: The return value is true if the queue is empty.
//
//   Item front( ) const
//
//   size_type size( ) const
//     Postcondition: The return value is the total number of items in the queue.
//
// VALUE SEMANTICS for the queue<Item> template class:
//   Assignments and the copy constructor may be used with queue<Item> objects.

#ifndef MAIN_SAVITCH_QUEUE2_H     // Prevent duplicate definition
#define MAIN_SAVITCH_QUEUE2_H
#include <cstdlib>   // Provides std::size_t
#include "node2.h"   // Node template class

namespace main_savitch_8C
{
    template <class Item>
    class queue
    {
    public:
        // TYPEDEFS 
        typedef std::size_t size_type;
        typedef Item value_type;
        // CONSTRUCTORS and DESTRUCTOR
        queue( );
	queue(const queue<Item>& source);
	~queue( );
        // MODIFICATION MEMBER FUNCTIONS
        void pop( );
        void push(const Item& entry);
	void operator =(const queue<Item>& source);
        // CONSTANT MEMBER FUNCTIONS
        bool empty( ) const { return (count == 0); }
	Item front( ) const;
	size_type size( ) const { return count; }
    private:
        main_savitch_6B::node<Item> *front_ptr;
        main_savitch_6B::node<Item> *rear_ptr; 
        size_type count;       // Total number of items in the queue
    };
}
#include "queue2.template" // Include the implementation
     
#endif
