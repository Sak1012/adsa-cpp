#include <iostream>
#include <vector>
#include <limits>
#include <stack>

using namespace std;

const int INF = numeric_limits<int>::max();

class Graph {
public:
    int V; // Number of vertices
    vector<vector<pair<int, int>> > adj; // Adjacency list: {vertex, weight}

    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    void addEdge(int src, int dest, int weight) {
        adj[src].push_back({dest, weight});
    }

    void dijkstra(int source) {
        vector<int> distance(V, INF);
        vector<bool> visited(V, false);
        vector<int> previous(V, -1);

        distance[source] = 0;

        for (int count = 0; count < V - 1; count++) {
            int u = -1;

            for (int v = 0; v < V; v++) {
                if (!visited[v] && (u == -1 || distance[v] < distance[u])) {
                    u = v;
                }
            }

            visited[u] = true;

            for (const pair<int, int>& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (!visited[v] && distance[u] != INF && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    previous[v] = u;
                }
            }
        }

        printShortestPaths(previous, source, distance);
    }

    void printShortestPaths(vector<int>& previous, int source, vector<int>& distance) {
        cout << "Shortest paths from source " << source << " to other vertices:" << endl;
        for (int v = 0; v < V; v++) {
            if (v != source) {
                stack<int> path;
                int current = v;
                while (current != -1) {
                    path.push(current);
                    current = previous[current];
                }
                cout << "Vertex " << v << ": " << source;
                while (!path.empty()) {
                    cout << " -> " << path.top();
                    path.pop();
                }
                cout << " (Distance: " << distance[v] << ")" << endl;
            }
        }
    }
};

int main() {
    int V = 6;
    Graph graph(V);

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 1);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 5);
    graph.addEdge(2, 3, 1);
    graph.addEdge(2, 4, 3);
    graph.addEdge(3, 4, 2);
    graph.addEdge(3, 5, 1);
    graph.addEdge(4, 5, 3);

    int source = 1;

    graph.dijkstra(source);

    return 0;
}
