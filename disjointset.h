#ifndef DISJOINTSET_H
#define DISJOINTSET_H


/** INB371 - asgn2 DisjointSet.h - Damon Jones */

///This data structure is used for very efficient look-up (Find) to determine
/// which set an element is in. It also provides a very efficient way to join
/// (Union) two sets together. Implementation based on code from Lecture 11.
class DisjointSet
{
    public:
        ///Constructor which sets the size of this DisjointSet.
        DisjointSet(int);

        ///Destructor
        ~DisjointSet();

        ///Returns the index of the parent set of the element in the parameter.
        int find(int);

        ///Creates the union of two disjoint sets whose indexes are passed as
        /// parameters.
        void join(int, int);

        ///Returns true if the two indexes passed as parameters are in the
        /// same set.
        bool sameComponent(int, int);
    protected:
    private:
        //stores all vertex/node id's.
        int* id;
        //stores each nodes path size.
        int* size;
};

#endif // DISJOINTSET_H
