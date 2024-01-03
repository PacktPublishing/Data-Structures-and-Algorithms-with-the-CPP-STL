#include <iostream>
#include <queue>
#include <vector>

class Graph {
public:
  Graph(int vertices) : numVertices(vertices) {
    adjList.resize(vertices);
  }

  void addEdge(int v, int w) {
    adjList[v].push_back(w);
    adjList[w].push_back(v);
  }

  void BFS(int startVertex) {
    std::vector<bool> visited(numVertices, false);
    std::queue<int> q;

    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
      int currentVertex = q.front();
      std::cout << currentVertex << " ";
      q.pop();

      for (int neighbor : adjList[currentVertex]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          q.push(neighbor);
        }
      }
    }
  }

private:
  int numVertices{0};
  std::vector<std::vector<int>> adjList;
};

int main() {
  Graph g(6);

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(1, 4);
  g.addEdge(2, 4);
  g.addEdge(3, 4);
  g.addEdge(3, 5);

  std::cout << "BFS starting from vertex 0: ";
  g.BFS(0); // Output: 0 1 2 3 4 5

  return 0;
}