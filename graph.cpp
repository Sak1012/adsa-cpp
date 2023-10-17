#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Define a structure for graph nodes
struct GraphNode {
    int data;
    vector<GraphNode*> neighbors;

    GraphNode(int val) : data(val) {}
};

class Graph {
public:
    Graph() {}

    // Function to add an edge between two nodes
    void add_edge(GraphNode* from, GraphNode* to) {
        from->neighbors.push_back(to);
        to->neighbors.push_back(from); // For an undirected graph
    }

    // Depth-First Search (DFS) traversal
    void dfs(GraphNode* start) {
        stack<GraphNode*> nodeStack;
        vector<bool> visited(nodes.size(), false);

        nodeStack.push(start);
        visited[start->data] = true;

        while (!nodeStack.empty()) {
            GraphNode* currentNode = nodeStack.top();
            nodeStack.pop();
            cout << currentNode->data << " ";

            for (GraphNode* neighbor : currentNode->neighbors) {
                if (!visited[neighbor->data]) {
                    nodeStack.push(neighbor);
                    visited[neighbor->data] = true;
                }
            }
        }
    }

    // Breadth-First Search (BFS) traversal
    void bfs(GraphNode* start) {
        queue<GraphNode*> nodeQueue;
        vector<bool> visited(nodes.size(), false);

        nodeQueue.push(start);
        visited[start->data] = true;

        while (!nodeQueue.empty()) {
            GraphNode* currentNode = nodeQueue.front();
            nodeQueue.pop();
            cout << currentNode->data << " ";

            for (GraphNode* neighbor : currentNode->neighbors) {
                if (!visited[neighbor->data]) {
                    nodeQueue.push(neighbor);
                    visited[neighbor->data] = true;
                }
            }
        }
    }

    // Function to add a node to the graph
    void add_node(GraphNode* node) {
        nodes.push_back(node);
    }

private:
    vector<GraphNode*> nodes;
};

int main() {
    // Create graph nodes
    GraphNode* nodeA = new GraphNode(0);
    GraphNode* nodeB = new GraphNode(1);
    GraphNode* nodeC = new GraphNode(2);
    GraphNode* nodeD = new GraphNode(3);
    GraphNode* nodeE = new GraphNode(4);

    // Create a graph
    Graph graph;

    // Add nodes to the graph
    graph.add_node(nodeA);
    graph.add_node(nodeB);
    graph.add_node(nodeC);
    graph.add_node(nodeD);
    graph.add_node(nodeE);

    // Add edges to the graph
    graph.add_edge(nodeA, nodeB);
    graph.add_edge(nodeA, nodeC);
    graph.add_edge(nodeB, nodeD);
    graph.add_edge(nodeC, nodeE);

    cout << "DFS traversal starting from node A: ";
    graph.dfs(nodeA);
    cout << endl;

    cout << "BFS traversal starting from node A: ";
    graph.bfs(nodeA);
    cout << endl;

    return 0;
}

