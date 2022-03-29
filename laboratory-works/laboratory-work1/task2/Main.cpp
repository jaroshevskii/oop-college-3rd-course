#include <iostream>

/// Returns the sum of the digits of a number.
int getSumOfDigits(int number) {
  int sumOfDigits{0};

  while (number) {
    sumOfDigits += number % 10;
    number /= 10;
  }
  return sumOfDigits;
}

/// Returns the largest number by the sum of digits.
int getLargestNumberBySumOfDigits() {
  std::cout << "Enter numbers (use 0 to end the entry).\n";

  int largestNumber{};
  int sumOfLargestNumber{};

  int currentNumber{};
  int sumOfСurrentNumber{};

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
  const int largestNumberBySumOfDigits = getLargestNumberBySumOfDigits();
  std::cout << "Largest number by the sum of digits: "
            << largestNumberBySumOfDigits << "\n\n";
  return 0;
}