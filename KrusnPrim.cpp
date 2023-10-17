#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;

    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class Graph {
public:
    int V;
    vector<Edge> edges;

    Graph(int vertices) : V(vertices) {}

    void addEdge(int src, int dest, int weight) {
        edges.push_back(Edge(src, dest, weight));
    }
};

class UnionFind {
public:
    vector<int> parent, rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x,int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int kruskalMST(Graph& graph) {
    vector<Edge> result;
    sort(graph.edges.begin(), graph.edges.end());

    UnionFind uf(graph.V);

    int totalWeight = 0;

    for (const Edge& edge : graph.edges) {
        int rootSrc = uf.find(edge.src);
        int rootDest = uf.find(edge.dest);

        if (rootSrc != rootDest) {
            result.push_back(edge);
            uf.unionSets(rootSrc, rootDest);
            totalWeight += edge.weight;
        }
    }

    cout << "Kruskal's MST Edges: " << endl;
    for (const Edge& edge : result) {
        cout << edge.src << " - " << edge.dest << " (" << edge.weight << ")" << endl;
    }

    return totalWeight;
}

int primMST(Graph& graph) {
    vector<int> parent(graph.V, -1);
    vector<int> key(graph.V, INT_MAX);
    vector<bool> inMST(graph.V, false);

    key[0] = 0;
    int totalWeight = 0;

    for (int count = 0; count < graph.V - 1; count++) {
        int u = -1;

        for (int v = 0; v < graph.V; v++) {
            if (!inMST[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        inMST[u] = true;

        for (const Edge& edge : graph.edges) {
            if (edge.src == u && !inMST[edge.dest] && edge.weight < key[edge.dest]) {
                parent[edge.dest] = u;
                key[edge.dest] = edge.weight;
            }
        }

        if (parent[u] != -1) {
            totalWeight += key[u];
        }
    }

    cout << "Prim's MST Edges: " << endl;
    for (int i = 1; i < graph.V; i++) {
        cout << parent[i] << " - " << i << " (" << key[i] << ")" << endl;
    }

    return totalWeight;
}

int main() {
    int V = 6;
    Graph graph(V);

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 0, 4);
    graph.addEdge(2, 0, 4);
    graph.addEdge(2, 1, 2);
    graph.addEdge(2, 3, 3);
    graph.addEdge(2, 5, 2);
    graph.addEdge(2, 4, 4);
    graph.addEdge(3, 2, 3);
    graph.addEdge(3, 5, 5);
    graph.addEdge(4, 2, 4);
    graph.addEdge(4, 5, 1);
    graph.addEdge(5, 2, 2);
    graph.addEdge(5, 3, 5);
    graph.addEdge(5, 4, 1);

    int kruskalWeight = kruskalMST(graph);
    cout << "Total Weight of Kruskal's MST: " << kruskalWeight << endl;
    
    int primWeight = primMST(graph);
    cout << "Total Weight of Prim's MST: " << primWeight << endl;

    return 0;
}

