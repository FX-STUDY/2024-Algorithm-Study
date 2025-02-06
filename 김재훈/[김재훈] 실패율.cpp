#include <algorithm>
#include <iostream>
#include <vector>

struct Stage {
  int stageNumber;
  double failRate;

  Stage();
  Stage(int stageNumber, double failRate) : stageNumber(stageNumber), failRate(failRate) {};
};

std::vector<int> solution(int N, std::vector<int> stages) {
  int stagesSize = stages.size();

  std::vector<Stage> failRates;
  failRates.reserve(N);

  int currentPeopleNum = stagesSize;
  std::vector<double> failNum(N, 0);
  for (int i = 0; i < stagesSize; i++) {
    if (stages[i] == N + 1) {
      continue;
    }

    failNum[stages[i] - 1] += 1;
  }

  for (int i = 0; i < N; i++) {
    if (currentPeopleNum == 0) {
      failRates.emplace_back(i + 1, 0)
    } else {
      failRates.emplace_back(i + 1, failNum[i] / currentPeopleNum);
    }
    currentPeopleNum -= failNum[i];
  }

  std::sort(failRates.begin(), failRates.end(), [](Stage &a, Stage &b) {
    if (a.failRate == b.failRate) {
      return a.stageNumber < b.stageNumber;
    }
    return a.failRate > b.failRate;
  });

  std::vector<int> result;
  result.reserve(N);
  for (int i = 0; i < N; i++) {
    result.push_back(failRates[i].stageNumber);
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int N;
  std::cin >> N;

  std::vector<int> stages = {2, 1, 2, 6, 2, 4, 3, 3};

  std::vector<int> failRates = solution(N, stages);

  for (int i = 0; i < N; i++) {
    std::cout << failRates[i] << " ";
  }
}