#include "vertex.h"

using namespace std;

/** INB371 - asgn2 Vertex.cpp - Damon Jones */

///This class encapsulates the identifier of a Vertex object and a collection
/// of Vertex objects in the minimum spanning tree of the graph which are
/// adjacent to this Vertex.


///No argument constructor.
Vertex::Vertex()
{
    //ctor
}

///Destructor
Vertex::~Vertex()
{
    //dtor
}

///Constructor which sets the vertex identifier.
Vertex::Vertex(unsigned int id){
    identifier = id;
    discovered = false;
    minDistance = NULL;
    predecessorId = NULL;
}

///Accessor for this vertex’identifier.
unsigned int Vertex::getId(){
    return identifier;
}

///Adds a Vertex’ identifier to this Vertex’ adjacency list. Used
/// by the Graph::Minimum Spanning Tree method.
void Vertex::addAdjacency(unsigned int id){
    adjacencies.insert(id);
}

///Returns a pointer to a collection of int, being the vertices
/// adjacent to this Vertex. Used by the Graph::Breadth First Search method.
set<unsigned int>* Vertex::getAdjacencies(){
    return &adjacencies;
}

///Mutator for the discovered field.
void Vertex::setDiscovered(bool status){
    discovered = status;
}

///Accessor for the discovered field.
bool Vertex::isDiscovered(){
    return discovered;
}

///Mutator for the predecessorId field.
void Vertex::setPredecessorId(unsigned int id){
    predecessorId = id;
}

///Accessor for the predecessorId field.
unsigned int Vertex::getPredecessorId(){
    return predecessorId;
}

///Mutator for the minDistance field.
void Vertex::setMinDistance(double dst){
    minDistance = dst;
}

///Accessor for the minDistance field.
double Vertex::getMinDistance(){
    return minDistance;
}

///Function operator implementation to provide an ordering for two
/// Vertex instances. Returns true if the minDistance of the first
/// parameter is greater than that of the second parameter.
bool Vertex::operator()(Vertex* a, Vertex* b){
    return (a->getMinDistance() >= b->getMinDistance());
}

///Provides a string representation of this object. Useful for debugging.
ostream& operator<<(ostream& out, Vertex& vertex){

    out << "V{" << vertex.getId()
    << " Dis:" << vertex.isDiscovered()
    << " Pred:" << vertex.getPredecessorId()
    << " Min:" << vertex.getMinDistance()
    << " Adj:";
    set<unsigned int>::iterator it;
    for (it = vertex.adjacencies.begin(); it != vertex.adjacencies.end(); ++it){
        out << *it << ",";
    }
    out << "}";

    return out;
}

