// FILE: newpoint.h (revised from point.h in Figure 2.9 on page 58)
// CLASS PROVIDED: point (an ADT for a point on a two-dimensional plane)
//
// CONSTRUCTOR for the point class:
//   point(double initial_x = 0.0, double initial_y = 0.0)
//     Postcondition: The point has been set to (initial_x, initial_y).
//
// MODIFICATION MEMBER FUNCTIONS for the point class:
//   void shift(double x_amount, double y_amount)
//     Postcondition: The point has been moved by x_amount along the x axis
//     and by y_amount along the y axis.
//
//   void rotate90( )
//     Postcondition: The point has been rotated clockwise 90 degrees.
//
// CONSTANT MEMBER FUNCTIONS for the point class:
//   double get_x( ) const
//     Postcondition: The value returned is the x coordinate of the point.
//
//   double get_y( ) const
//     Postcondition: The value returned is the y coordinate of the point.
//
//	 point operator^(const point& p2) const; 
//		Postcondition: the sum of activating object (p1) and argument p2 is returned.
//		Note: for comparison ONLY; do not recommend you to overload anything!
//
// NONMEMBER FUNCTIONS for the point class:
//   point operator +(const point& p1, const point& p2)
//     Postcondition: The sum of p1 and p2 is returned.
//
//   bool operator ==(const point& p1, const point& p2)
//     Postcondition: The return value is true if p1 and p2 are identical.
//
//   bool operator !=(const point& p1, const point& p2)
//     Postcondition: The return value is true if p1 and p2 are not identical.
//
//   ostream& operator <<(ostream& outs, const point& source)
//     Postcondition: The x and y coordinates of source have been 
//     written to outs. The return value is the ostream outs.
//
//   istream& operator >>(istream& ins, point& target)
//     Postcondition: The x and y coordinates of target have been 
//     read from ins. The return value is the istream ins.
//
//   double distance(const point& p1, const point& p2)
//     Postcondition: The value returned is the distance between p1 and p2.
//
//   point middle(const point& p1, const point& p2)
//     Postcondition: The point returned is halfway between p1 and p2.
//
// VALUE SEMANTICS for the point class:
//   Assignments and the copy constructor may be used with point objects.

#ifndef MAIN_SAVITCH_NEWPOINT_H   
#define MAIN_SAVITCH_NEWPOINT_H  
#include <iostream> // Provides ostream and istream

namespace main_savitch_2B
{          
    class point
    {
    public:
        // CONSTRUCTOR
        point(double initial_x = 0.0, double initial_y = 0.0);
        // MODIFICATION MEMBER FUNCTIONS
	void set(double x_init, double y_init);
        void shift(double x_amount, double y_amount);
        void rotate90( );
        // CONSTANT MEMBER FUNCTIONS
        double get_x( ) const { return x; } 
        double get_y( ) const { return y; }

		//Using member function for operator overloading 
		//Just for test; you shall only use one of the two ways to overload the same types of operators
		//Recommendation: Using nonmember function
		point operator^(const point& p2) const; 

        // FRIEND FUNCTION
        friend std::istream& operator >>(std::istream& ins, point& target);
    private:
        double x, y; // x and y coordinates of this point
    };

    // NONMEMBER FUNCTIONS for the point class 
    double distance(const point& p1, const point& p2);
    point middle(const point& p1, const point& p2);
    point operator +(const point& p1, const point& p2);
    bool operator ==(const point& p1, const point& p2);
    bool operator !=(const point& p1, const point& p2);
    std::ostream& operator <<(std::ostream & outs, const point& source);
}

#endif 
