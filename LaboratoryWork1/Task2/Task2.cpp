#include <iostream>

/// Отримати ціле число.
int getNumber() {
  std::cout << "> ";
  int number;
  std::cin >> number;
  return number;
}

/// Отримати суму цифр.
int getSumOfDigits(int number) {
  int sumOfDigits = 0;

  while (number) {
    sumOfDigits += number % 10;
    number /= 10;
  }
  return sumOfDigits;
}

/// Отримати найбільше число за сумою цифр.
int getLargestNumberBySumOfDigits() {
  std::cout << "// Enter integers (use 0 to end the entry).\n";

  int largestNumber;
  int sumOfDigitsOfLargestNumber;

  int number;
  int sumOfDigits;

  while (true) {
    number = getNumber();

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
  // Найбільше число за сумою ціфр.
  const int largestNumberBySumOfDigits = getLargestNumberBySumOfDigits();

  std::cout << "Largest number by sum of digits: " << largestNumberBySumOfDigits
            << "\n\n";
  return 0;
}