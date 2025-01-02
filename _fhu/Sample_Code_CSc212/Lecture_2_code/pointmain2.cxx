// FILE: pointmain2.cxx
// This small demonstration shows how the NEW point class is used.
// by Zhigang Zhu Fall 2002

#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "newpoint.h"   // Provides the throttle class
using namespace std;    // Allows all Standard Library items to be used


using namespace main_savitch_2B; // all the items can be used in the namespace


int shifts_needed(point p)
{
    int answer = 0;
    while ((p.get_x() <0) || (p.get_y()<0))
    {
        p.shift(1,1);
        answer++;
    }
    return answer;
}


int shift_to_1st_quad(point& p)
{
	int shifts =0;
    while ((p.get_x() <0) || (p.get_y()<0)) 
	{
         p.shift(1,1);
		 shifts++;
	}
	return shifts;
}



int main( )
{

	point a(-1.1, -2.1);  // uses the usual constructor with 
                           // two arguments
	point b(-1.1); // uses 1.1 for the first,
                    // but use default for the second

	point c; // uses default arguments for both;
              // default constructor: 
              // no argument, no parentheses!

	
	cout << " ************ Default Parameter Test ************" <<endl;

	cout << "\n Point a is intialized as (" << a.get_x() << ", " << a.get_y() << ")" << "\n	by the constructor with 2 arguments" << endl; 
	cout << "\n Point b is intialized as (" << b.get_x() << ", " << b.get_y() << ")" << "\n	by the constructor with 1 argument, one default" << endl; 
	cout << "\n Point c is intialized as (" << c.get_x() << ", " << c.get_y() << ")" << "\n	by the constructor with two default arguments\n" << endl; 

	cout << "\n ************ Value Parameter Test ************" <<endl;
	// point a(-1.1,-2.1);
	cout << "\n Shifts needed to bring point (" << a.get_x() << " ," <<a.get_y() <<")"<< endl;
	cout << "to the first quadrant is " << shifts_needed(a) << endl;
	cout << "\n However, the coordinates of point a remains to be (" << a.get_x() << ", " << a.get_y() <<") \n when using a value parameter "<< endl;

	cout << "\n ************ Reference Parameter Test ************" <<endl;
	// point a(-1.1,-2.1);
	cout << "\n If you really want to shift point (" << a.get_x() << " ," <<a.get_y() <<")"<< endl;
	cout << " to the first quadrant, use reference parameter " << endl << endl;
	cout << " After making "<< shift_to_1st_quad(a) << " shifts,";
	cout << "the coordinates of point a becomes (" << a.get_x() << ", " << a.get_y() <<") !"<< endl <<endl;

	cout << "\n ************ Operator Overloading Test ************" <<endl;

	point c1, c2;

	c1 = a+b;
	
	c2 = a^b;

	cout << " In this demo, point addition is overloaded using " << endl;
	cout << " both member function in c1 = a+b " << endl;
	cout << " and nonmember function in c2 = a^b" << endl << endl;

	if (c1 == c2) 
	{
		cout << "By testing c1 == c2, we know that they are the same : "<< "(" << c1.get_x() << ", " << c1.get_y() << ")" << endl << endl;
		cout << "In fact with ostream overloaded, we can use a simpler way to output a point: " << endl; 
		cout << "	cout << c1 " <<endl;
		cout << "instead of using " << endl;
		cout << "	cout << \"(\" << c1.get_x() << \", \" << c1.get_y() << \")\" " << endl << endl; 
		cout << "By testing c1 == c2, we know that they are the same: " << c1 << endl << endl;

	}

	/////////////////// INPUT OUTPU TEST /////////////
	point p1,p2;
	
	int chain_test = 0;

	cout<<"Input two points and an integer:";

	//cin >> p >> chain_test;

	//p >> cin; 
	//p.operator>>(cin) >> chain_test;
	
	p2 >> (p1 >> cin) >> chain_test;
	
	cout << p1 << p2 << "...chain_test=" << chain_test << endl;
    
	return EXIT_SUCCESS;
}
