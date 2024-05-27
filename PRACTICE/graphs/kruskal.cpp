#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int source;
    int destination;
    int weight;
    Edge(int s, int d, int w) : source(s), destination(d), weight(w) {}
};

class KruskalsSoln
{
public:
    int findParent(int source, vector<int> parent)
    {
        if (parent[source] == source)
            return source;
        return findParent(parent[source], parent);
    }

    void unionSets(int v1, int v2, vector<int> &parent, vector<int> &rank)
    {
        v1 = findParent(v1, parent);
        v2 = findParent(v2, parent);
        if (rank[v1] < rank[v2])
        {
            parent[v1] = v2;
        }
        else if (rank[v1] > rank[v2])
        {
            parent[v2] = v1;
        }
        else
        {
            parent[v2] = v1;
            rank[v1]++;
        }
    }
    bool weightSorting(Edge e1, Edge e2){
        return e1.weight < e2.weight;
    }
    vector<Edge> input(int vertex, int edges)
    {
        vector<int> parent(vertex);
        vector<int> rank(vertex, 0);
        for (int i = 0; i < vertex; i++)
        {
            parent[i] = i;
        }

        vector<Edge> edgeList;

        for (int i = 0; i < edges; i++)
        {
            int s, d, w;
            cin >> s >> d >> w;
            edgeList.emplace_back(s, d, w);
        }

        sort(edgeList.begin(), edgeList.end(), [](Edge e1, Edge e2){
            return e1.weight < e2.weight;
        });

        vector<Edge> mst;  // Store the edges of the minimum spanning tree
        int mstWeight = 0; // Total weight of the minimum spanning tree

        for (Edge e : edgeList)
        {
            int root1 = findParent(e.source, parent);
            int root2 = findParent(e.destination, parent);
            if (root1 != root2)
            {
                mst.push_back(e);
                mstWeight += e.weight;
                // unionSets(root1, root2, parent, rank);
                parent[e.destination]=e.source;
            }
            cout<<endl;
        }

        return mst;
    }
};

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    KruskalsSoln solution;
    vector<Edge> mst = solution.input(vertices, edges);

    for (auto e : mst)
    {
        cout << e.source << " -- " << e.destination << " == " << e.weight << endl;
    }
}
