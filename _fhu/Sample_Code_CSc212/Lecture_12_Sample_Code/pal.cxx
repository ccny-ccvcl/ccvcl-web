// FILE: pal.cxx
// Program to test whether an input line is a palindrome. Spaces,
// punctuation, and the difference between upper- and lowercase are ignored.

#include <cassert>    // Provides assert
#include <cctype>     // Provides isalpha, toupper
#include <cstdlib>    // Provides EXIT_SUCCESS
#include <iostream>   // Provides cout, cin, peek
#include <queue>      // Provides the queue template class
#include <stack>      // Provides the stack template class
using namespace std;

int main( )
{
    queue<char> q;
    stack<char> s;
    char letter;            
    queue<char>::size_type mismatches = 0;  // Mismatches between queue and stack
    cout << "Enter a line and I will see if it's a palindrome:" << endl;

    while (cin.peek( ) != '\n')
    {
        cin >> letter;
        if (isalpha(letter))
        {
            q.push(toupper(letter));
            s.push(toupper(letter));
        }
    }

    while ((!q.empty( )) && (!s.empty( )))
    {
        if (q.front( ) != s.top( ))
            ++mismatches;
        q.pop( );
        s.pop( );
    }

    if (mismatches == 0)
        cout << "That is a palindrome." << endl;
    else
        cout << "That is not a palindrome." << endl;    
    return EXIT_SUCCESS;    
}
