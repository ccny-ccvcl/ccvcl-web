// FILE: pointmain3.cxx
// This small demonstration shows how the point class is used.

#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "newpoint.h"   // Provides the throttle class
using namespace std;    // Allows all Standard Library items to be used
using main_savitch_2B::point;


int main( )
{
	cout << "********************* Dynamic Object Test****************" <<endl<<endl;

        point *p1, *p2, *p3;
        std::size_t i;

        p1 = new point(1.0, 2.0);
        cout<< "(*p1).get_x() = "<< (*p1).get_x()<<endl<<endl;
        cout<< " p1->get_x() = "<<p1->get_x()<<endl<<endl;
        cout << "*p1 = " << (*p1)<< endl<<endl;

        //p2 = new point[10](1.0, 2.0);
        //p2 = new point(1.0, 2.0)[10];

        p3 = new point[10];
        for (i=0; i<10; i++)  {
                p3[i].set(i, 0);
                cout <<"p3["<< i << "] = " << p3[i] <<endl;
        }

        cin >> i;  // just want to pause the display in windows environment
	return EXIT_SUCCESS;
}
