#include <iostream>
#include <queue>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int start;
  int search;
  std::cin >> start >> search;

  if (start >= search) {
    std::cout << start - search << std::endl;
    return 0;
  }

  std::queue<int> q;
  std::vector<int> timer(100001, -1);

  timer[start] = 0;
  q.push(start);

  while (true) {
    int current = q.front();
    q.pop();

    if (current == search) {
      std::cout << timer[current];
      return 0;
    }

    int next1 = current - 1;
    if (next1 >= 0 && timer[next1] == -1) {
      timer[next1] = timer[current] + 1;
      q.push(next1);
    }

    int next2 = current * 2;
    if (next2 <= 100000 && timer[next2] == -1) {
      timer[next2] = timer[current] + 1;
      q.push(next2);
    }

    int next3 = current + 1;
    if (next3 <= 100000 && timer[next3] == -1) {
      timer[next3] = timer[current] + 1;
      q.push(next3);
    }
  }

  return 0;
}