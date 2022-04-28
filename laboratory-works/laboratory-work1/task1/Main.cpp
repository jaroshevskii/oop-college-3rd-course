#include <iostream>

/// Returns the inverse number.
int getInverseNumber(int number) {
  int reverseNumber{0};

  while (number) {
    reverseNumber = reverseNumber * 10 + number % 10;
    number /= 10;
  }
  return reverseNumber;
}

/// Returns true if the number is a palindrome.
bool isPalindrome(int number) { return number == getInverseNumber(number); }

int main() {
  const int beginNumber{10};
  const int endNumber{100};

  static_assert(beginNumber < endNumber,
                "The initial number cannot be greater than the final one.");

  for (int number = beginNumber; number < endNumber; ++number) {
    const int numberInDegree{number * number};

    if (isPalindrome(numberInDegree)) {
      std::cout << number << " (" << numberInDegree << ")\n";
    }
  }
  return 0;
}