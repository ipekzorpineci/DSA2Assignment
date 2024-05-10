#include <iostream>
#include <vector>
using namespace std;

/*
* Name: ipek
* Surname: Zorpineci
* Date: 10.05.2024
* Student ID: 211504024
*/

// Helper function to check if the current color assignment is valid
bool isSafe(int node, vector<vector<int>>& graph, vector<int>& colors, int col) {
    for (int adj = 0; adj < graph.size(); adj++) {
        if (graph[node][adj] && colors[adj] == col) {
            return false;
        }
    }
    return true;
}

// Recursive function to solve the graph coloring problem
bool graphColoringUtil(vector<vector<int>>& graph, int m, vector<int>& colors, int v) {
    if (v == graph.size()) {
        return true; // All vertices are assigned a color
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, colors, c)) {
            colors[v] = c; // Assign color c to vertex v

            // Recursively assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, colors, v + 1)) {
                return true;
            }

            // If no color can be assigned, backtrack
            colors[v] = 0;
        }
    }
    return false; // If no color can be assigned to this vertex then return false
}

// Function to set up the graph from edges and attempt to color it
bool graphColoring(int N, int M, int E, vector<pair<int, int>>& edges) {
    // Construct the adjacency matrix
    vector<vector<int>> graph(N, vector<int>(N, 0));
    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        graph[u][v] = 1;
        graph[v][u] = 1; // Since the graph is undirected
    }

    vector<int> colors(N, 0); // Color initialization
    return graphColoringUtil(graph, M, colors, 0);
}

int main() {
    // Example 1
    int N1 = 4, M1 = 3, E1 = 5;
    vector<pair<int, int>> edges1 = { {0, 1}, {1, 2}, {2, 3}, {3, 0}, {0, 2} };

    // Example 2
    int N2 = 3, M2 = 2, E2 = 3;
    vector<pair<int, int>> edges2 = { {0, 1}, {1, 2}, {0, 2} };

    cout << "Example 1\nInput:\nN = 4\nM = 3\nE = 5\nEdges[] = { (0, 1), (1, 2), (2, 3), (3, 0), (0, 2) }" << endl;
    cout << "Output: " << (graphColoring(N1, M1, E1, edges1) ? 1 : 0) << endl;
    cout << "\nExample 1\nInput:\nN = 3\nM = 2\nE = 3\nEdges[] = { (0, 1), (1, 2), (0, 2) }" << endl;
    cout << "Output: " << (graphColoring(N2, M2, E2, edges2) ? 1 : 0) << endl;

    return 0;
}

