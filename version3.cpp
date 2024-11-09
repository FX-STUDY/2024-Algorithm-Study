#include <iostream>
using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int rows;
  int cols;
  cin >> rows >> cols;

  for (int i = 0; i < rows; i++) {
    int minutes = -1;
    for (int j = 0; j < cols; j++) {
      char cloud_flag;
      cin >> cloud_flag;
      if (cloud_flag == 'c') {
        minutes = 0;
      }
      cout << minutes << ' ';
      if (minutes != -1) {
        minutes++;
      }
    }
    cout << '\n';
  }
}