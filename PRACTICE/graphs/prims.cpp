#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Define a structure for an edge
struct Edge {
    int weight;
    int vertex;
};

// Comparator to order edges by their weight in the priority queue (min-heap)
struct Compare {
    bool operator()(Edge const& e1, Edge const& e2) {
        return e1.weight > e2.weight;
    }
};

// Function to perform Prim's algorithm
void primsAlgorithm(vector<vector<pair<int, int>>>& graph, int start) {
    int n = graph.size();
    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);
    vector<int> parent(n, -1);
    
    priority_queue<Edge, vector<Edge>, Compare> pq;
    
    // Start with the starting vertex
    pq.push({0, start});
    key[start] = 0;
    
    while (!pq.empty()) {
        int u = pq.top().vertex;
        pq.pop();
        
        if (inMST[u]) continue; // If the vertex is already in MST, skip it
        
        inMST[u] = true;
        
        // Update keys and parents for the adjacent vertices
        for (size_t i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i].first;
            int weight = graph[u][i].second;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({weight, v});
                parent[v] = u;
            }
        }
    }
    
    // Print the edges of the MST
    for (int i = 1; i < n; ++i) {
        if (parent[i] != -1) {
            cout << "Edge: " << parent[i] << " - " << i << " with weight " << key[i] << endl;
        }
    }
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<pair<int, int>>> graph(V);
    
    // Example graph (undirected)
    graph[0].push_back({1, 2});
    graph[0].push_back({3, 6});
    graph[1].push_back({0, 2});
    graph[1].push_back({2, 3});
    graph[1].push_back({3, 8});
    graph[1].push_back({4, 5});
    graph[2].push_back({1, 3});
    graph[2].push_back({4, 7});
    graph[3].push_back({0, 6});
    graph[3].push_back({1, 8});
    graph[4].push_back({1, 5});
    graph[4].push_back({2, 7});
    
    primsAlgorithm(graph, 0);
    
    return 0;
}
