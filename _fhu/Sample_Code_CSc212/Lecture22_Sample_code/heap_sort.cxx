// FILE: heap_sort.cxx
// An interactive test program for the heapsort function
// using the heap class

#include <cstdlib>     // Provides EXIT_SUCCESS, size_t
#include <iostream>    // Provides cout and cin
#include "heap.h"

using namespace std;
using namespace heap_nspace;

int main( )
{
    int user_input;                // Number typed by the user
    heap<int> h;
    size_t i;
    const char BLANK = ' ';

    // Provide some instructions
    cout << "Please type up to " << h.CAPACITY << " positive integers.";
    cout << "Indicate the list's end with a zero." << endl;

    // Read the input numbers

    cin >> user_input;
    while ((user_input != 0) && (h.heap_size() < h.CAPACITY))
    {
        h.push(user_input);
        cin >> user_input;
    }

    // Sort the numbers and print the result with two blanks after each number
    h.heap_sort();

    // Print the sorted numbers
    cout << "In sorted order, your numbers are: " << endl;
    for (i = 0; i < h.sorted_size(); ++i)
        cout << h[i] << BLANK << BLANK; // we overloaded [] for the heap
    cout << endl;

    return EXIT_SUCCESS;
}

