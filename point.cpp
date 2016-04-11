#include "point.h"
#include <cmath>
#include <iomanip>

using namespace std;

/** INB371 - asgn2 point.cpp - Damon Jones */

///This class encapsulates the x and y co-ordinates of a point in a Cartesian
/// plane and has functionality to determine the distance between two instances
/// of Point objects.


///Constructor that sets the x and y coordinates for the Point object.
Point::Point(double X, double Y){
    x = X;
    y = Y;
}

///Destructor.
Point::~Point(){
    //dtor
}

///Returns the Euclidean distance between this Point and the Point*
/// parameter to the function.
double Point::distanceTo (Point* other){
    double a = x - other->x;
    double b = y - other->y;

    double c = a*a + b*b;

    return sqrt(c);
}

///Produces a string representation of this Point. e.g."2 13"
ostream& operator<< (ostream& out, Point& point){
    //out << "P{";
    out << setw(3) << point.x << " " << setw(3) << point.y;
    //out << "}";

    return out;
}
