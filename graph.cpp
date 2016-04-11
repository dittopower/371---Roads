#include "graph.h"
#include "disjointset.h"
#include <iomanip>
#include <cmath>

using namespace std;

/** INB371 - asgn2 Graph.cpp - Damon Jones */

///This class encapsulates a weighted undirected graph. Edge weights stored
/// in an adjacency matrix and pointers to Vertexs in a vector.
/// The class also uses a priority queue to sort vertices for Dijkstra’s
/// algorithm.
/// The edges required for Kruskal’s Minimum Spanning Tree are sorted and
/// stored in a priority queue and Kruskal’s algorithm will store relivant
/// adjacent vertex identifiers in the adjacency list in each vertex.


///Constructor sets the number of vertices in this Graph. Initialises the
/// two dimensional array of weights by setting all values to INFINITY
/// except the diagonal of the array where the weight is set to 0.
Graph::Graph(unsigned int num){
    numVertices = num;

    //First level array
    weights = new double* [num];
    //Second level arrays
    for (int i = 0; i < num; i++){
        weights[i] = new double [num];

        //Default all values to infinity.
        //Except where 'i' equals 'a' which is 0.
        for (int a = 0; a < num; a++){
            if (i == a){
                weights[i][a] = 0;
            }else{
                weights[i][a] = Infinity;
            }
        }
    }
}

///Destructor.
Graph::~Graph()
{
    vertices.clear();
    while (!edges.empty()){
        edges.pop();
    }
    delete weights;
}

///Adds pointer to Vertex to the collection of vertices for this Graph.
void Graph::addVertex(Vertex* vertex){
    vertices.push_back(vertex);
}

///Accessor returns a pointer to the Vertex with the identifier/index
/// in the parameter
Vertex* Graph::getVertex(int index){
    return vertices[index];
}

///Adds pointer to Edge to the edge list for this Graph. Using the
/// source and destination identifiers from the edge, sets the weight
/// of the undirected edge in the adjacency matrix.
void Graph::addEdge(Edge* e){
    edges.push(e);
    int a = e->getSource()->getId();
    int b = e->getDestination()->getId();
    double w = e->getWeight();
    weights[a][b] = w;
    weights[b][a] = w;
}

///Uses Kruskal’s algorithm to find the Minimum Spanning Tree (MST)
/// for this Graph. Stores the edges of the MST in the adjacency list
/// of each Vertex. Returns the cost of the minimum spanning tree.
double Graph::minimumSpanningTreeCost(){
    double minCost = 0;
    int edgeCount = 0;
    DisjointSet myset (numVertices);
    //for each edge in the queue
    while ((!edges.empty()) && (edgeCount < (numVertices - 1))){
        //poll the queue
        Edge* edge = edges.top();
        edges.pop();
        unsigned int src = edge->getSource()->getId();
        unsigned int dest = edge->getDestination()->getId();
        //So long as the edge doesn't make a cycle
        if (!myset.sameComponent(src,dest)){
            //add it to the tree
            edgeCount++;
            myset.join(src,dest);
            edge->getDestination()->addAdjacency(src);
            edge->getSource()->addAdjacency(dest);
            minCost += edge->getWeight();
        }
    }
    return minCost;
}

///Determines the shortest path from the source vertex to all other vertices.
/// Prints the length of the path and the vertex identifiers in the path.
void Graph::dijkstra(unsigned int src){
    //Setup
    priority_queue<Vertex, vector<Vertex*>,Vertex> myqueue;
    //For each Vertex
    for (int i = 0; i < numVertices; i++){
        //set found as false.
        vertices[i]->setDiscovered(false);
        //default the predecessor id.
        vertices[i]->setPredecessorId(src);
        //Set the distance as the relivate edges weight.
        vertices[i]->setMinDistance(weights[src][i]);
        //Add to queue
        myqueue.push(vertices[i]);
    }
    //Run
    while (!myqueue.empty()){
        //poll queue
        Vertex* u = myqueue.top();
        myqueue.pop();
        //mark visited
        u->setDiscovered(true);
        unsigned int id = u->getId();
        //for each unvisited vertex
        for (int v = 0; v < numVertices; v++){
            if (!(vertices[v]->isDiscovered())){

                //if the new distance is less than the old distance, set the new path
                double nw = u->getMinDistance() + weights[id][v];
                if (nw < vertices[v]->getMinDistance()){
                    vertices[v]->setMinDistance(nw);
                    vertices[v]->setPredecessorId(id);
                    myqueue.push(vertices[v]);
                }
            }
        }
    }
    //Output
    //for each vertex other than the source
    for (int i = 0; i < numVertices; i++){
        if (i != src){
            //Get the minimum distance
            double dist = vertices[i]->getMinDistance();
            //If the distance is still Inifinity there is no path
            if (dist == Infinity){
                cout << "NO PATH ";
            }else{
                cout << "Distance";
            }
            cout << " from " << setw(2) << src << " to " << setw(2) << i;
            //if there is a path
            if (dist != Infinity){
                //print distance
                cout << " = " << setw(6) << setprecision(2) << fixed << dist << " traveling via ";
                //Trace back path.
                vector<int> path;
                path.push_back(i);
                int temp = i;
                while (src != temp){
                    temp = vertices[temp]->getPredecessorId();
                    path.push_back(temp);
                }
                //Print out path.
                for (int a = path.size()-1; a >= 0; a--){
                    cout << path[a] << " ";
                }
            }
            cout << endl;
        }
    }
}

///Determines the shortest path from the source vertex to all other vertices
/// using only the adjacencies in the minimum spanning tree. Prints the
/// length of the path and the vertex identifiers in the path.
void Graph::bfs(unsigned int src){
    //Setup
    //For each Vertex
    for (int i = 0; i < numVertices; i++){
        //set found as false.
        vertices[i]->setDiscovered(false);
    }
    //create queue
    priority_queue<Vertex, vector<Vertex*>,Vertex> myqueue;
    //set source vertex as discoverd
    vertices[src]->setDiscovered(true);
    //add to queue
    myqueue.push(vertices[src]);

    //Run
    while(!myqueue.empty()){
        //poll queue
        Vertex* current = myqueue.top();
        myqueue.pop();
        //for each vertex ajacent to the current vertex
        set<unsigned int>::iterator iter;
        for (iter = current->getAdjacencies()->begin();iter != current->getAdjacencies()->end();iter++){
            //if the ajacent vertex is not discovered
            if (!(vertices[*iter]->isDiscovered())){
                //set the current vertex as the parent of the ajacent vertex
                vertices[*iter]->setPredecessorId(current->getId());
                //Set the ajacent vertex as discoverd.
                vertices[*iter]->setDiscovered(true);
                //Add to queue to be processed next.
                myqueue.push(vertices[*iter]);
            }
        }
    }
    //Output
    //For each vertex other than the source
    for (int i = 0; i < numVertices; i++){
        if (i != src){
            //Trace back path calculating the distance.
            vector<int> path;
            double dist = 0;
            int current = i;
            int prev = i;
            //Until the source is reached
            while (src != prev){
                //add this vertexs distance from the previous
                dist = dist + weights[prev][current];
                //move to the next vertex up the path
                prev = current;
                path.push_back(current);
                current = vertices[current]->getPredecessorId();
            }
            //If the distance is still Inifinity there is no path
            if (dist == Infinity){
                cout << "NO PATH ";
            }else{
                cout << "Distance";
            }
            //print vertex labels
            cout << " from " << setw(2) << src << " to " << setw(2) << i;
            //if there is a path
            if (dist != Infinity){
                //print distance
                cout << " = " << setw(6) << setprecision(2) << fixed << dist << " traveling via ";
                //Print path.
                for (int a = path.size()-1; a >= 0; a--){
                    cout << path[a] << " ";
                }
            }
            cout << endl;
        }
    }
}

///Outputs the adjacency matrix for the graph. If an edge weight is
/// INFINITY, - should be printed instead of the number.
ostream& operator<<(ostream& out, Graph& graph){
/*    out << "G{v:" << graph.numVertices;

    for (int i = 0; i < graph.vertices.size(); i++){
        out << " " << *graph.vertices[i];
    }

    out << endl << "e:" << graph.edges.size() << endl;
*/
    for (int i = 0; i < graph.numVertices; i++){
        for (int a = 0; a < graph.numVertices; a++){
            out << " ";
            //if the weight is infinity show '-' instead.
            if (graph.weights[i][a] == graph.Infinity){
                out << setw(6) << "-";
            }else{
                out << setw(6) << setprecision(2) << fixed << graph.weights[i][a];
            }
        }
        out << endl;
    }
//    out << "}";
    return out;
}
