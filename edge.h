#ifndef EDGE_H
#define EDGE_H
//#include <iostream>
#include "vertex.h"

/** INB371 - asgn2 Edge.h - Damon Jones */

///This class encapsulates pointers to the source and destination Vertex
/// objects and the weight of the Edge. An alternative would be to
/// encapsulate Vertex identifiers (ints) rather than pointers to Vertex.
class Edge
{
    public:
        ///No argument constructor.
        Edge();

        ///Destructor
        ~Edge();

        ///Constructor which sets the source vertex, the destination vertex
        /// and the weight for this Edge.
        Edge(Vertex*, Vertex*, double);

        ///Returns a pointer to the source vertex.
        Vertex* getSource();

        ///Returns a pointer to the destination vertex.
        Vertex* getDestination();

        ///Returns the weight of this Edge.
        double getWeight();

        ///Function operator provides an ordering for edges. Returns true
        /// if the weight of the first parameter is greater than that of
        /// the second paramter.
        bool operator()(Edge*, Edge*);

        ///Returns a string representation of this Edge. Useful for debugging
        /// purposes.
        friend std::ostream& operator<<(std::ostream&, Edge&);

    protected:
    private:
        ///Instance field for the source vertex.
        Vertex* source;

        ///Instance field for the destination vertex.
        Vertex* destination;

        ///Instance field for the edge weight.
        double weight;
};

#endif // EDGE_H
