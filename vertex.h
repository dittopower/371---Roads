#ifndef VERTEX_H
#define VERTEX_H
#include <set>
#include <iostream>

/** INB371 - asgn2 Vertex.h - Damon Jones */

///This class encapsulates the identifier of a Vertex object and a collection
/// of Vertex objects in the minimum spanning tree of the graph which are
/// adjacent to this Vertex.

class Vertex
{
    public:
        ///No argument constructor.
        Vertex();

        ///Constructor which sets the vertex identifier.
        Vertex(unsigned int);

        ///Destructor
        virtual ~Vertex();

        ///Accessor for this vertex’identifier.
        unsigned int getId();

        ///Adds a Vertex’ identifier to this Vertex’ adjacency list. Used
        /// by the Graph::Minimum Spanning Tree method.
        void addAdjacency(unsigned int);

        ///Returns a pointer to a collection of int, being the vertices
        /// adjacent to this Vertex. Used by the Graph::Breadth First Search
        /// method.
        std::set<unsigned int>* getAdjacencies();

        ///Mutator for the discovered field.
        void setDiscovered(bool);

        ///Accessor for the discovered field.
        bool isDiscovered();

        ///Mutator for the predecessorId field.
        void setPredecessorId(unsigned int);

        ///Accessor for the predecessorId field.
        unsigned int getPredecessorId();

        ///Mutator for the minDistance field.
        void setMinDistance(double);

        ///Accessor for the minDistance field.
        double getMinDistance();

        ///Function operator implementation to provide an ordering for two
        /// Vertex instances. Returns true if the minDistance of the first
        /// parameter is greater than that of the second parameter.
        bool operator()(Vertex*, Vertex*);

        ///Provides a string representation of this object. Useful for
        /// debugging.
        friend std::ostream& operator<<(std::ostream&, Vertex&);

    protected:
    private:
        ///Instance field to store the identifier for this Vertex.
        unsigned int identifier;

        ///Stores vertex identifiers for vertices adjacent to this vertex
        /// as discovered during the Graph::Minimum Spanning Tree method.
        std::set<unsigned int> adjacencies;

        ///Keeps track of whether or not this vertex has been visited during
        /// Dijkstra’s algorithm or discovered during the Breadth First
        /// Search method.
        bool discovered;

        ///Stores the predecessor vertex identifier for path discovery
        unsigned int predecessorId;

        ///Store the minimum distance from the source to this vertex. Used
        /// by Dijkstra’s algorithm.
        double minDistance;
};

#endif // VERTEX_H
