#include <iostream>
using namespace std;

int main() {
  int rows, cols;
  cin >> rows >> cols;
  char current_cloud_position[rows][cols];

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> current_cloud_position[i][j];
    }
  }

  int minutes = -1;
  int cloud_position_after_minutes[rows][cols];

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (minutes == -1 && current_cloud_position[i][j] == '.') {
        cloud_position_after_minutes[i][j] = minutes;
        continue;
      }
      if (current_cloud_position[i][j] == 'c') {
        minutes = 0;
      }
      cloud_position_after_minutes[i][j] = minutes++;
    }
    minutes = -1;
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << cloud_position_after_minutes[i][j] << ' ';
    }
    cout << endl;
  }
}
// 런타임 4ms