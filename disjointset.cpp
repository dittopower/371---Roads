#include "DisjointSet.h"

using namespace std;

/** INB371 - asgn2 DisjointSet.cpp - Damon Jones */

///This data structure is used for very efficient look-up (Find) to determine
/// which set an element is in. It also provides a very efficient way to join
/// (Union) two sets together. Implementation based on code from Lecture 11.


///Constructor which sets the size of this DisjointSet.
DisjointSet::DisjointSet(int num){
    size = new int [num];
    id = new int [num];
    for (int i = 0; i < num; i++){
        id[i] = i;
        size[i] = 1;
    }
}

///Destructor
DisjointSet::~DisjointSet()
{
    //dtor
}

///Returns the index of the parent set of the element in the parameter.
/// Compressing the path as we go.
int DisjointSet::find(int i) {
    while (i != id[i]){
        // set elements to point to their root
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

///Creates the union of two disjoint sets whose indexes are passed as parameters.
void DisjointSet::join(int p, int q) {
    int i = find(p);
    int j = find(q);
    if (size[i] < size[j]) {
        id[i] = j;
        size[j] += size[i];
    } else {
        id[j] = i;
        size[i] += size[j];
    }
}

///Returns true if the two indexes passed as parameters are in the same set.
bool DisjointSet::sameComponent(int p, int q) {
    return find(p) == find(q);
}

