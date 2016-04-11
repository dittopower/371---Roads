#include "edge.h"

using namespace std;

/** INB371 - asgn2 Edge.cpp - Damon Jones */

///This class encapsulates pointers to the source and destination Vertex
/// objects and the weight of the Edge. An alternative would be to
/// encapsulate Vertex identifiers (ints) rather than pointers to Vertex.


///No argument constructor.
Edge::Edge()
{
    //ctor
}

///Destructor
Edge::~Edge()
{
    //dtor
}

///Constructor which sets the source vertex, the destination vertex
/// and the weight for this Edge.
Edge::Edge(Vertex* src, Vertex* dest, double value){
    source = src;
    destination = dest;
    weight = value;
}

///Returns a pointer to the source vertex.
Vertex* Edge::getSource(){
    return source;
}

///Returns a pointer to the destination vertex.
Vertex* Edge::getDestination(){
    return destination;
}

///Returns the weight of this Edge.
double Edge::getWeight(){
    return weight;
}

///Function operator provides an ordering for edges. Returns true
/// if the weight of the first parameter is greater than that of
/// the second paramter.
bool Edge::operator()(Edge* a, Edge* b){
    return (a->weight > b->weight);
}

///Returns a string representation of this Edge. Useful for debugging purposes.
ostream& operator<<(ostream& out, Edge& edge){
    out << "E{src:" << edge.getSource()->getId()
    << " dest:" << edge.getDestination()->getId()
    << " w:" << edge.getWeight() << "}";
    return out;
}

