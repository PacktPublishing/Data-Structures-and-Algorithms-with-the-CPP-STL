#include <climits>
#include <iostream>
#include <list>
#include <queue>
#include <vector>

class WeightedGraph {
public:
  WeightedGraph(int vertices) : numVertices(vertices) {
    adjList.resize(vertices);
  }

  void addEdge(int u, int v, int weight) {
    adjList[u].push_back({v, weight});
    adjList[v].push_back({u, weight});
  }

  void dijkstra(int startVertex) {
    std::priority_queue<std::pair<int, int>,
                        std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        pq;
    std::vector<int> distances(numVertices, INT_MAX);

    pq.push({0, startVertex});
    distances[startVertex] = 0;

    while (!pq.empty()) {
      int currentVertex = pq.top().second;
      pq.pop();

      for (auto &neighbor : adjList[currentVertex]) {
        int vertex = neighbor.first;
        int weight = neighbor.second;

        if (distances[vertex] >
            distances[currentVertex] + weight) {
          distances[vertex] =
              distances[currentVertex] + weight;
          pq.push({distances[vertex], vertex});
        }
      }
    }

    std::cout << "Distances from vertex " << startVertex
              << ":\n";
    for (int i = 0; i < numVertices; ++i) {
      std::cout << i << " -> " << distances[i] << '\n';
    }
  }

private:
  int numVertices{0};
  std::vector<std::list<std::pair<int, int>>> adjList;
};

int main() {
  WeightedGraph g(5);

  g.addEdge(0, 1, 9);
  g.addEdge(0, 2, 6);
  g.addEdge(0, 3, 5);
  g.addEdge(1, 3, 2);
  g.addEdge(2, 4, 1);
  g.addEdge(3, 4, 2);

  g.dijkstra(0);

  return 0;
}