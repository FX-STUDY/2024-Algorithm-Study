#include <iostream>
#include <queue>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int rows;
  int cols;
  std::cin >> cols >> rows;
  std::vector<std::vector<char>> board(rows, std::vector<char>(cols));

  for (int i = 0; i < rows; i++) {
    std::string str;
    std::cin >> str;

    for (int j = 0; j < cols; j++) {
      board[i][j] = str[j];
    }
  }

  int whitePower = 0;
  int bluePower = 0;
  std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
  int dirRow[4] = {-1, 1, 0, 0};
  int dirCol[4] = {0, 0, -1, 1};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (!visited[i][j]) {
        int length = 0;
        char curTeam = board[i][j];

        std::pair<int, int> coord(i, j);
        std::queue<std::pair<int, int>> q;

        visited[i][j] = true;
        q.push(coord);

        while (!q.empty()) {
          std::pair<int, int> curCoord = q.front();
          q.pop();
          length += 1;

          for (int k = 0; k < 4; k++) {
            int nextRow = curCoord.first + dirRow[k];
            int nextCol = curCoord.second + dirCol[k];
            if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols) {
              if (!visited[nextRow][nextCol] && curTeam == board[nextRow][nextCol]) {
                visited[nextRow][nextCol] = true;
                q.push(std::pair(nextRow, nextCol));
              }
            }
          }
        }

        if (curTeam == 'W') {
          whitePower += length * length;
        } else {
          bluePower += length * length;
        }
      }
    }
  }

  std::cout << whitePower << ' ' << bluePower;
}