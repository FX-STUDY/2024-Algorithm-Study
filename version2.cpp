#include <iostream>
using namespace std;

int main() {
  int rows, cols;
  cin >> rows >> cols;

  char cloud_flag;
  int minutes = -1;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> cloud_flag;
      if (cloud_flag == 'c') {
        minutes = 0;
      }
      if (minutes != -1) {
        cout << minutes++ << ' ';
        continue;
      }
      cout << minutes << ' ';
    }
    minutes = -1;
    cout << endl;
  }
}
// 런타임 264ms