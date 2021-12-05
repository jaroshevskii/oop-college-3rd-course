#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

/// Надрукувати числа.
void printNumbers(const std::vector<int> &numbers) {
  std::cout << "Numbers:";

  for (const auto &i : numbers)
    std::cout << ' ' << i;
  std::cout << "\n\n";
}

int main() {
  std::string str{"3 -43 234 63 26"};
  std::vector<int> numbers;

  std::stringstream strStream{str};
  std::string number;

  while (strStream >> number)
    numbers.push_back(stoi(number));

  // Відсортувати числа.
  std::sort(numbers.begin(), numbers.end());

  printNumbers(numbers);
  return 0;
}