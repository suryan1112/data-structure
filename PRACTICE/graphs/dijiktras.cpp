#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Define a structure for an edge
struct Edge {
    int vertex;
    int weight;
};

// Comparator to order the priority queue (min-heap) by distance
struct Compare {
    bool operator()(pair<int, int> const& p1, pair<int, int> const& p2) {
        return p1.second > p2.second;
    }
};

// Function to perform Dijkstra's algorithm
void dijkstraAlgorithm(vector<vector<Edge>>& graph, int start) {
    int n = graph.size();
    vector<int> distance(n, INT_MAX);
    vector<int> parent(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    
    // Start with the starting vertex
    distance[start] = 0;
    pq.push({start, 0});
    
    while (!pq.empty()) {
        int u = pq.top().first;
        pq.pop();
        
        // Update distances for adjacent vertices
        for (size_t i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i].vertex;
            int weight = graph[u][i].weight;
            
            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({v, distance[v]});
                parent[v] = u;
            }
        }
    }
    
    // Print the shortest distances from the start vertex to all other vertices
    for (int i = 0; i < n; ++i) {
        cout << "Distance from vertex " << start << " to vertex " << i << " is " << distance[i] << endl;
    }
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<Edge>> graph(V);
    
    // Example graph (directed with positive weights)
    graph[0].push_back({1, 10});
    graph[0].push_back({4, 5});
    graph[1].push_back({2, 1});
    graph[1].push_back({4, 2});
    graph[2].push_back({3, 4});
    graph[3].push_back({2, 6});
    graph[3].push_back({0, 7});
    graph[4].push_back({1, 3});
    graph[4].push_back({2, 9});
    graph[4].push_back({3, 2});
    
    dijkstraAlgorithm(graph, 0);
    
    return 0;
}
