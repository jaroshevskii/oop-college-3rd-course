#include <cmath>
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
  const int initialNumber{10};
  const int finiteNumber{100};

  static_assert(initialNumber < finiteNumber,
                "The initial number cannot be greater than the final one.");

  for (int number = initialNumber; number < finiteNumber; ++number) {
    const int numberInDegree = number * number;

    if (isPalindrome(numberInDegree)) {
      std::cout << "Number:    " << number << "\n"
                << "Palindrom: " << numberInDegree << "\n\n";
    }
  }
  return 0;
}