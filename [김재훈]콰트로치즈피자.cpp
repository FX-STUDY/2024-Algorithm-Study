#include <iostream>
#include <unordered_set>
using namespace std;

bool isCheese(const string& str) { return str == "Cheese"; }

int main() {
  int numberOfToppings;
  cin >> numberOfToppings;

  string topping;
  unordered_set<string> toppingSet;

  for (int i = 0; i < numberOfToppings; i++) {
    cin >> topping;
    if (topping.length() >= 6 &&
        isCheese(topping.substr(topping.length() - 6, 6))) {
      toppingSet.insert(topping);
    } else {
      continue;
    }
    if (toppingSet.size() == 4) {
      cout << "yummy";
      return 0;
    }
  }
  cout << "sad";
}
