#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <queue>
#include <limits>
#include "edge.h"

/** INB371 - asgn2 Graph.h - Damon Jones */

///This class encapsulates a weighted undirected graph. Edge weights stored
/// in an adjacency matrix and pointers to Vertexs in a vector.
/// The class also uses a priority queue to sort vertices for Dijkstra’s
/// algorithm.
/// The edges required for Kruskal’s Minimum Spanning Tree are sorted and
/// stored in a priority queue and Kruskal’s algorithm will store relivant
/// adjacent vertex identifiers in the adjacency list in each vertex.
class Graph
{
    public:
        ///Constructor sets the number of vertices in this Graph.
        /// Initialises the two dimensional array of weights by setting all
        /// values to INFINITY except the diagonal of the array where the
        /// weight is set to 0.
        Graph(unsigned int);

        ///Destructor
        ~Graph();

        ///Adds pointer to Vertex to the collection of vertices for this
        /// Graph.
        void addVertex(Vertex*);

        ///Accessor returns a pointer to the Vertex with the identifier/index
        /// in the parameter
        Vertex* getVertex(int);

        ///Adds pointer to Edge to the edge list for this Graph. Using the
        /// source and destination identifiers from the edge, sets the weight
        /// of the undirected edge in the adjacency matrix.
        void addEdge(Edge*);

        ///Uses Kruskal’s algorithm to find the Minimum Spanning Tree (MST)
        /// for this Graph. Stores the edges of the MST in the adjacency list
        /// of each Vertex. Returns the cost of the minimum spanning tree.
        double minimumSpanningTreeCost();

        ///Determines the shortest path from the source vertex to all other
        /// vertices. Prints the length of the path and the vertex
        /// identifiers in the path.
        void dijkstra(unsigned int);

        ///Determines the shortest path from the source vertex to all other
        /// vertices using only the adjacencies in the minimum spanning tree.
        ///Prints the length of the path and the vertex identifiers in the
        /// path.
        void bfs(unsigned int);

        ///Outputs the adjacency matrix for the graph. If an edge weight is
        /// INFINITY, - should be printed instead of the number.
        friend std::ostream& operator<<(std::ostream&, Graph&);

    protected:
    private:
        ///Instance field for the number of vertices in the graph.
        unsigned int numVertices;

        ///The adjacency matrix for this graph. Two dimensional array of
        /// weights.
        double** weights;

        ///Storage for edges to be used by Kruskal’s algorithm for calculating
        /// the minimum cost spanning tree.
        std::priority_queue<Edge*,std::vector<Edge*>, Edge> edges;

        ///Storage for graph vertices.
        std::vector<Vertex*> vertices;

        //Infinity Value 3/4 of the max of double this value should not ever be reached normally.
        const double Infinity = std::numeric_limits<double>::max() / 4 * 3;

};

#endif // GRAPH_H
