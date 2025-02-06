#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int houses;
  std::cin >> houses;
  std::vector<int> positions(houses);
  for (int i = 0; i < houses; i++) {
    std::cin >> positions[i];
  }

  std::sort(positions.begin(), positions.end());
  std::cout << positions[(houses - 1) / 2] << "\n";
  return 0;
}