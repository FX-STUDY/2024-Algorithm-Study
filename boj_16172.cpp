#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> build_partial_match_table(const string &pattern) {
  int pat_len = pattern.size();
  vector<int> table(pat_len, 0);
  int j = 0;

  for (int i = 1; i < pat_len; i++) {
    while (j > 0 && pattern[i] != pattern[j]) {
      j = table[j - 1];
    }
    if (pattern[i] == pattern[j]) {
      table[i] = ++j;
    }
  }
  return table;
}

int main() {
  string input;
  string search;

  cin >> input >> search;

  int input_len = input.size();
  int search_len = search.size();

  vector<int> partial_match_table = build_partial_match_table(search);
  int partial_match_len = 0;

  for (int i = 0; i < input_len; i++) {
    if (input_len - i < search_len && partial_match_len == 0) {
      break;
    }
    if (input[i] <= '9' && input[i] >= '0') {
      continue;
    }
    while (partial_match_len > 0 && input[i] != search[partial_match_len]) {
      partial_match_len = partial_match_table[partial_match_len - 1];
    }
    if (input[i] == search[partial_match_len]) {
      partial_match_len++;
      if (partial_match_len == search_len) {
        cout << 1;
        return 0;
      }
    }
  }
  cout << 0;
}