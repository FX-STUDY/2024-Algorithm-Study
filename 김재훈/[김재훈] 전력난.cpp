#include <iostream>
#include <queue>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  while (true) {
    int vertex;
    int edge;
    std::cin >> vertex >> edge;

    if (vertex == 0 && edge == 0) {
      break;
    }

    int initWeightSum = 0;
    int mstWeightSum = 0;

    std::vector<std::vector<std::pair<int, int>>> graph(vertex);

    while (edge--) {
      int from;
      int to;
      int weight;

      std::cin >> from >> to >> weight;

      graph[from].push_back(std::pair(weight, to));
      graph[to].push_back(std::pair(weight, from));
      initWeightSum += weight;
    }

    std::vector<bool> visited(vertex, false);

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>>
      minHeap;

    visited[0] = true;
    for (std::pair<int, int> adj : graph[0]) {
      minHeap.push(adj);
    }

    int includedEdge = 0;

    while (includedEdge != vertex - 1) {
      std::pair<int, int> minEdge = minHeap.top();
      minHeap.pop();

      if (visited[minEdge.second] == true) {
        continue;
      }

      visited[minEdge.second] = true;
      mstWeightSum += minEdge.first;

      includedEdge += 1;

      for (std::pair<int, int> adj : graph[minEdge.second]) {
        if (visited[adj.second] != true) {
          minHeap.push(adj);
        }
      }
    }

    std::cout << initWeightSum - mstWeightSum << "\n";
  }
}