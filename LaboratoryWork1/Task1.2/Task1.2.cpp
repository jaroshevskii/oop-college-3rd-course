#include <iostream>

/// Отримати ціле число.
int getInt(const int &minValue) {
  int value;

  while (true) {
    std::cout << "> ";
    std::cin >> value;
    
    if (value >= minValue)
      return value;

    std::cout << '\n';
    std::cout << "error: The value is incorrect.\n";
    std::cout << '\n';
  }
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
  std::cout << '\n';

  int largestNumber;
  int sumOfDigitsOfLargestNumber = 0;

  int number;
  int sumOfDigits = 0;

  while (true) {
    number = getInt(0);

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
  int largestNumberBySumOfDigits = getLargestNumberBySumOfDigits();

  std::cout << "Largest number by sum of digits: "
            << largestNumberBySumOfDigits << '\n';
  std::cout << '\n';
  return 0;
}