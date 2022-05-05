#include <iostream>

/// Returns the sum of the digits of a number.
int getSumOfDigits(int number) {
  auto sumOfDigits = 0;

  while (number) {
    sumOfDigits += number % 10;
    number /= 10;
  }
  return sumOfDigits;
}

/// Returns the largest number by the sum of digits.
int getLargestNumberBySumOfDigits() {
  std::cout << "Enter numbers (use 0 to end the entry).\n";

  auto largestNumber = 0;
  auto sumOfLargestNumber = 0;

  auto currentNumber = 0;
  auto sumOfСurrentNumber = 0;

  while (true) {
    std::cout << "> ";
    std::cin >> currentNumber;

    if (currentNumber == 0) {
      std::cout << '\n';
      return largestNumber;
    }

    sumOfСurrentNumber = getSumOfDigits(currentNumber);

    if (sumOfСurrentNumber > sumOfLargestNumber) {
      sumOfLargestNumber = sumOfСurrentNumber;
      largestNumber = currentNumber;
    }
  }
}

int main() {
  // Finds and prints the largest number by the sum of digits.
  const auto largestNumber = getLargestNumberBySumOfDigits();
  std::cout << "Largest number by the sum of digits: " << largestNumber << '\n';
  return 0;
}