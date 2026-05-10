#include "DIJKSTRA.h"

int main() {
    Dijkstra g(6);

    // Add undirected edges (u, v, weight)
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 1);
    g.addEdge(4, 5, 2);

    int source = 0, destination = 5;
    g.printShortestPath(source, destination);

    return 0;
}


