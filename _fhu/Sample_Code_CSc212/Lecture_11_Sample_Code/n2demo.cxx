// FILE: n2demo.cxx
// IMPLEMENTS: The usage of the node template class and the node_iterator class
// LAST MODIFICATION: Oct. 19, 2016 (by: Feng HU)

#include <iostream>
#include "node2.h"
#include "point.h"

using namespace main_savitch_6B;
using namespace main_savitch_2A;
using namespace std;

int main(){
	node<int>* ages = NULL;
	list_head_insert(ages, 18);
        list_insert(ages, 19);
	
	node<string> name;
	name.set_data("Jorge");

	node<point>* seat;
	seat = new node<point>;
	(*seat).set_data(point(2,4));
    
    node_iterator<int> start(ages);
    node_iterator<int> finish;
    node_iterator<int> position;
    for (position = start; position != finish; ++position) {
        cout << *position << endl;
    }
    
    node_iterator<string> start2(&name);
    node_iterator<string> finish2;
    node_iterator<string> position2;
    for (position2 = start2; position2 != finish2; ++position2) {
        cout << *position2 << endl;
    }
    
    node_iterator<point> start3(seat);
    node_iterator<point> finish3;
    node_iterator<point> position3;
    for (position3 = start3; position3 != finish3; ++position3) {
        cout << "x value is: " << (*position3).get_x() << endl;
        cout << "y value is: " << (*position3).get_y() << endl;
    }
}
