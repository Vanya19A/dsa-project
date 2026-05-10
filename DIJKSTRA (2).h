#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

class Dijkstra {
private:
    int V;  // number of vertices
    vector<vector<pair<int, int>>> adj;  // adjacency list (node, weight)

public:
    // Constructor
    Dijkstra(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    // Add an undirected edge (u <-> v) with weight w
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Find shortest path between source and destination
    pair<int, vector<int>> shortestPath(int src, int dest) {
        vector<int> dist(V, INT_MAX);
        vector<int> parent(V, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (u == dest) break;  // early stop when destination reached
            if (d > dist[u]) continue;  // skip outdated entries

            for (auto &edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        // Reconstruct the path
        vector<int> path;
        if (dist[dest] == INT_MAX)
            return {INT_MAX, path}; // No path found

        for (int v = dest; v != -1; v = parent[v])
            path.push_back(v);
        reverse(path.begin(), path.end());

        return {dist[dest], path};
    }

    // Print the result (distance + path)
    void printShortestPath(int src, int dest) {
        auto result = shortestPath(src, dest);
        int distance = result.first;
        vector<int> path = result.second;

        if (distance == INT_MAX) {
            cout << "No path exists between " << src << " and " << dest << endl;
            return;
        }

        cout << "Shortest distance from " << src << " to " << dest << " = " << distance << endl;
        cout << "Path: ";
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i != path.size() - 1) cout << " -> ";
        }
        cout << endl;
    }
};

#endif // DIJKSTRA_H
