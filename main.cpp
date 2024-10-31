#include <iostream>
#include <set>
using namespace std;

bool isCheese(string str) { return str == "Cheese"; }

int main() {
  int numberOfToppings;
  cin >> numberOfToppings;

  string topping;
  set<string> toppingSet;

  for (int i = 0; i < numberOfToppings; i++) {
    cin >> topping;
    if (topping.length() >= 6 && isCheese(topping.substr(topping.length() - 6, 6))) {
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