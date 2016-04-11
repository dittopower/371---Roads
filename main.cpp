#include <iostream>
#include "edge.h"
#include "graph.h"

using namespace std;

int main()
{
    Vertex* va = new Vertex(0);
    Vertex* vb = new Vertex(1);
    Vertex* vc = new Vertex(2);
    Vertex* vd = new Vertex(3);
    Vertex* ve = new Vertex(4);
    Vertex* vf = new Vertex(5);
    Vertex* vg = new Vertex(6);
    Vertex* vh = new Vertex(7);
    Vertex* vi = new Vertex(8);
    Vertex* vj = new Vertex(9);
    Edge* ea = new Edge(va,vd,25.32);
    Edge* eb = new Edge(vb,ve,74.73);
    Edge* ec = new Edge(vb,vf,20.62);
    Edge* ed = new Edge(vb,vh,28.32);
    Edge* ee = new Edge(vb,vi,66.48);
    Edge* ef = new Edge(vb,vj,34.41);
    Edge* eg = new Edge(vc,vd,20.02);
    Edge* eh = new Edge(vc,ve,85.33);
    Edge* ei = new Edge(vc,vi,74.20);
    Edge* ej = new Edge(vd,ve,65.97);
    Edge* ek = new Edge(ve,vg,88.87);
    Edge* el = new Edge(ve,vj,57.63);
    Edge* em = new Edge(vg,vh,33.53);
    Edge* en = new Edge(vg,vi,83.44);
    Edge* eo = new Edge(vi,vj,68.96);
    Graph graph(10);
    graph.addVertex(va);
    graph.addVertex(vb);
    graph.addVertex(vc);
    graph.addVertex(vd);
    graph.addVertex(ve);
    graph.addVertex(vf);
    graph.addVertex(vg);
    graph.addVertex(vh);
    graph.addVertex(vi);
    graph.addVertex(vj);
    graph.addEdge(ea);
    graph.addEdge(eb);
    graph.addEdge(ec);
    graph.addEdge(ed);
    graph.addEdge(ee);
    graph.addEdge(ef);
    graph.addEdge(eg);
    graph.addEdge(eh);
    graph.addEdge(ei);
    graph.addEdge(ej);
    graph.addEdge(ek);
    graph.addEdge(el);
    graph.addEdge(em);
    graph.addEdge(en);
    graph.addEdge(eo);

    cout << "\n" << graph << "\n" << endl;
    graph.dijkstra(0);
    cout << "\n" << graph.minimumSpanningTreeCost() << "\n" << endl;
    return 0;
}
