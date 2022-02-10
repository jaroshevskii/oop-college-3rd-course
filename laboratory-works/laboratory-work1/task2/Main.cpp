#include <iostream>

<<<<<<< HEAD
/// Returns the number entered by the user.
int getNumber() {
  std::cout << "> ";
  int number;
  std::cin >> number;
  return number;
}

/// Returns the sum of the digits of a number.
=======
>>>>>>> 5069c341d73013642f5cede42a65c65262d07446
int getSumOfDigits(int number) {
  int sumOfDigits = 0;

  while (number) {
    sumOfDigits += number % 10;
    number /= 10;
  }
  return sumOfDigits;
}

/// Returns the largest number by the sum of digits.
int getLargestNumberBySumOfDigits() {
  std::cout << "Enter integers (use 0 to end the entry).\n";

  int largestNumber;
  int sumOfDigitsOfLargestNumber;

  int number;
  int sumOfDigits;

  while (true) {
    std::cout << "> ";
    int number;
    std::cin >> number;

    if (number == 0) {
      std::cout << '\n';
      return largestNumber;
    }

    sumOfDigits = getSumOfDigits(number);

    if (sumOfDigits > sumOfDigitsOfLargestNumber) {
      sumOfDigitsOfLargestNumber = sumOfDigits;
      largestNumber = number;
    }
  }
}

int main() {
  const int largestNumberBySumOfDigits = getLargestNumberBySumOfDigits();
  std::cout << "The largest number by the sum of digits is "
            << largestNumberBySumOfDigits << "\n\n";
  return 0;
}
