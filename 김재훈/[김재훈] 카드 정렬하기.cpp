#include <algorithm>
#include <iostream>
#include <queue>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int decks;
  std::cin >> decks;
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
  for (int i = 0; i < decks; i++) {
    int cardsOfDecks;
    std::cin >> cardsOfDecks;
    pq.push(cardsOfDecks);
  }

  if (decks == 1) {
    std::cout << pq.top() << "\n";
    return 0;
  }

  long long result = 0;
  while (!pq.size() > 1) {
    long long deck1 = pq.top();
    pq.pop();

    long long deck2 = pq.top();
    pq.pop();

    long long sum = deck1 + deck2;

    result += sum;

    pq.push(sum);
  }

  std::cout << result << "\n";
}