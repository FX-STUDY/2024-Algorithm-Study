#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

struct Point {
  double x, y;
};

int parent[1001];

int findParent(int x) {
  if (parent[x] == x) {
    return x;
  }
  return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
  a = findParent(a);
  b = findParent(b);
  if (a < b) {
    parent[b] = a;
  } else {
    parent[a] = b;
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int godNumber, connected;
  std::cin >> godNumber >> connected;

  for (int i = 0; i < godNumber; i++) {
    parent[i] = i;
  }

  std::vector<Point> points(godNumber);
  for (int i = 0; i < godNumber; i++) {
    std::cin >> points[i].x >> points[i].y;
  }

  for (int i = 0; i < connected; i++) {
    int a, b;
    std::cin >> a >> b;
    unionParent(a - 1, b - 1);
  }

  std::vector<std::tuple<double, int, int>> edges;
  edges.reserve(godNumber * (godNumber - 1) / 2);

  for (int i = 0; i < godNumber; i++) {
    for (int j = i + 1; j < godNumber; j++) {
      double dx = points[i].x - points[j].x;
      double dy = points[i].y - points[j].y;
      double dist = sqrt(dx * dx + dy * dy);
      edges.push_back({dist, i, j});
    }
  }

  sort(edges.begin(), edges.end(), [](auto &a, auto &b) { return std::get<0>(a) < std::get<0>(b); });

  double result = 0.0;
  for (auto &e : edges) {
    double dist;
    int u, v;
    std::tie(dist, u, v) = e;

    if (findParent(u) != findParent(v)) {
      unionParent(u, v);
      result += dist;
    }
  }

  std::cout << std::fixed << std::setprecision(2) << result << "\n";
  return 0;
}