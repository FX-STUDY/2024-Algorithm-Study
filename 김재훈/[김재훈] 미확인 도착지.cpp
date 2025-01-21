#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

struct Edge {
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int testCases;
  std::cin >> testCases;

  while (testCases--) {
    int nodes, edges, candidates;
    std::cin >> nodes >> edges >> candidates;

    int startNode, gNode, hNode;
    std::cin >> startNode >> gNode >> hNode;

    int ghEdgeWeight = 0;
    std::vector<std::vector<Edge>> graph(nodes + 1);

    for (int i = 0; i < edges; ++i) {
      int a, b, weight;
      std::cin >> a >> b >> weight;
      graph[a].emplace_back(Edge(b, weight));
      graph[b].emplace_back(Edge(a, weight));

      if ((a == gNode && b == hNode) || (a == hNode && b == gNode)) {
        ghEdgeWeight = weight;
      }
    }

    std::vector<int> startDist(nodes + 1, INT_MAX);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> startPq;
    startDist[startNode] = 0;
    startPq.emplace(0, startNode);

    while (!startPq.empty()) {
      auto [currentDist, u] = startPq.top();
      startPq.pop();

      if (currentDist > startDist[u]) {
        continue;
      }

      for (const Edge &edge : graph[u]) {
        if (startDist[edge.to] > currentDist + edge.weight) {
          startDist[edge.to] = currentDist + edge.weight;
          startPq.emplace(startDist[edge.to], edge.to);
        }
      }
    }

    std::vector<int> gDist(nodes + 1, INT_MAX);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> gPq;
    gDist[gNode] = 0;
    gPq.emplace(0, gNode);

    while (!gPq.empty()) {
      auto [currentDist, u] = gPq.top();
      gPq.pop();

      if (currentDist > startDist[u]) {
        continue;
      }

      for (const Edge &edge : graph[u]) {
        if (gDist[edge.to] > currentDist + edge.weight) {
          gDist[edge.to] = currentDist + edge.weight;
          gPq.emplace(gDist[edge.to], edge.to);
        }
      }
    }

    std::vector<int> hDist(nodes + 1, INT_MAX);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> hPq;
    hDist[hNode] = 0;
    hPq.emplace(0, hNode);

    while (!hPq.empty()) {
      auto [currentDist, u] = hPq.top();
      hPq.pop();

      if (currentDist > startDist[u]) {
        continue;
      }

      for (const Edge &edge : graph[u]) {
        if (hDist[edge.to] > currentDist + edge.weight) {
          hDist[edge.to] = currentDist + edge.weight;
          hPq.emplace(hDist[edge.to], edge.to);
        }
      }
    }

    std::vector<int> validCandidates;
    for (int i = 0; i < candidates; ++i) {
      int candidate;
      std::cin >> candidate;

      bool viaGh = (startDist[gNode] + ghEdgeWeight + hDist[candidate] == startDist[candidate]);
      bool viaHg = (startDist[hNode] + ghEdgeWeight + gDist[candidate] == startDist[candidate]);

      if (viaGh || viaHg) {
        validCandidates.push_back(candidate);
      }
    }

    std::sort(validCandidates.begin(), validCandidates.end());

    for (int candidate : validCandidates) {
      std::cout << candidate << ' ';
    }
    std::cout << '\n';
  }
}