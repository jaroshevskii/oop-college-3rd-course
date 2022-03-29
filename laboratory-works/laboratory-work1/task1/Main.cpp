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
  const int finiteNumber{1000};

  static_assert(initialNumber < finiteNumber,
                "The initial number cannot be greater than the final one.");

  for (int number = initialNumber; number < finiteNumber; ++number) {
    if (isPalindrome(pow(number, 2))) {
      std::cout << "Number:     " << number << "\n"
                << "Palindrom:  " << pow(number, 2) << "\n\n";
    }
  }
  return 0;
}