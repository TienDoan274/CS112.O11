#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <numeric>
#include <algorithm>

using namespace std;

void AStar(int start, int goal, int numVertices, vector<string> vertexList, vector<int> heuristic, vector<vector<int>> adjacencyMatrix) {
    vector<bool> closed(numVertices, 0);
    vector<int> g(numVertices, 9999999);
    vector<int> f(numVertices, -1);
    map<string, string> parent;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> open;

    g[start] = 0;
    f[start] = heuristic[start];
    open.push(make_pair(f[start], start));

    bool found = false;

    while (!open.empty()) {
        int current = open.top().second;
        open.pop();

        if (current == goal) {
            found = true;
            break;
        }

        closed[current] = 1;

        for (int neighbor = 0; neighbor < numVertices; ++neighbor) {
            if (adjacencyMatrix[current][neighbor] != 0) {
                if (closed[neighbor] == 0) {
                    int gNew = g[current] + adjacencyMatrix[current][neighbor];

                    if (g[neighbor] > gNew) {
                        g[neighbor] = gNew;
                        parent[vertexList[neighbor]] = vertexList[current];
                        f[neighbor] = g[neighbor] + heuristic[neighbor];
                        open.push(make_pair(f[neighbor], neighbor));
                    }
                }

                if (closed[neighbor] != 0) {
                    if (g[neighbor] > g[current] + adjacencyMatrix[current][neighbor]) {
                        closed[neighbor] = 0;
                        g[neighbor] = g[current] + adjacencyMatrix[current][neighbor];
                        parent[vertexList[neighbor]] = vertexList[current];
                        f[neighbor] = g[neighbor] + heuristic[neighbor];
                        open.push(make_pair(f[neighbor], neighbor));
                    }
                }
            }
        }
    }

    if (!found) {
        cout << "-unreachable-\n";
        cout << accumulate(closed.begin(), closed.end(), 0) << " " << 0;
    } else {
        vector<string> path;
        string current = vertexList[goal];

        while (current != vertexList[start]) {
            path.push_back(current);
            current = parent[current];
        }

        path.push_back(vertexList[start]);
        reverse(path.begin(), path.end());

        for (string vertex : path) {
            cout << vertex << " ";
        }

        cout << "\n" << accumulate(closed.begin(), closed.end(), 0) + 1 << " " << f[goal];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numVertices, numEdges;
    string startVertex, goalVertex;
    cin >> numVertices >> numEdges >> startVertex >> goalVertex;

    vector<string> vertexList(numVertices);
    map<string, int> vertexIndex;

    for (int i = 0; i < numVertices; i++) {
        string vertex;
        cin >> vertex;
        vertexList[i] = vertex;
        vertexIndex[vertex] = i;
    }

    vector<int> heuristic(numVertices);

    for (int i = 0; i < numVertices; i++) {
        int value;
        cin >> value;
        heuristic[i] = value;
    }

    vector<vector<int>> adjacencyMatrix(numVertices, vector<int>(numVertices, 0));

    for (int i = 0; i < numEdges; i++) {
        string vertex1, vertex2;
        int cost;
        cin >> vertex1 >> vertex2 >> cost;
        adjacencyMatrix[vertexIndex[vertex1]][vertexIndex[vertex2]] = cost;
    }

    AStar(vertexIndex[startVertex], vertexIndex[goalVertex], numVertices, vertexList, heuristic, adjacencyMatrix);

    return 0;
}