#include <iostream>

/// Returns the inverse number.
int getInverseNumber(int number) {
  auto inverseNumber = 0;

  while (number) {
    inverseNumber = inverseNumber * 10 + number % 10;
    number /= 10;
  }
  return inverseNumber;
}

/// Returns true if the number is a palindrome.
bool isPalindrome(int number) { return number == getInverseNumber(number); }

int main() {
  const auto beginNumber = 10;
  const auto endNumber = 100;

  static_assert(beginNumber < endNumber,
                "The initial number cannot be greater than the final one.");

  for (auto number = beginNumber; number < endNumber; ++number) {
    const auto numberInDegree = number * number;

    if (isPalindrome(numberInDegree)) {
      std::cout << number << " (" << numberInDegree << ")\n";
    }
  }
  return 0;
}