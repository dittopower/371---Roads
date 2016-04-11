#ifndef POINT_H
#define POINT_H
#include <iostream>

/** INB371 - asgn2 point.h - Damon Jones */

///This class encapsulates the x and y co-ordinates of a point in a Cartesian
/// plane and has functionality to determine the distance between two instances
/// of Point objects.
class Point
{
    public:
        ///Constructor that sets the x and y coordinates for the Point object.
        Point(double X, double Y);

        ///Destructor.
        ~Point();

        ///Returns the Euclidean distance between this Point and the Point*
        /// parameter to the function.
        double distanceTo(Point*);

        ///Produces a string representation of this Point. e.g."2 13"
        friend std::ostream& operator<<(std::ostream&, Point&);
    protected:
    private:
        //Position
        double x;
        double y;
};

#endif // POINT_H
