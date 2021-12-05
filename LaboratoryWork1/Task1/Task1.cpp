#include <iostream>

/// Отимати перевернене число.
int getReverseNumber(int number) {
  int reverseNumber = 0;

  while (number) {
    reverseNumber = reverseNumber * 10 + number % 10;
    number /= 10;
  }
  return reverseNumber;
}

/// Є паліндромом.
bool isPalindrome(const int &number) {
  return number == getReverseNumber(number);
}

int main() {
  for (int i = 10; i < 100; ++i) {
    if (isPalindrome(i * i)) {
      std::cout << std::string(32, '-') << '\n'
                << "Number: " << i << '\n'
                << "Palindrom: " << i * i << '\n';
    }
  }

  std::cout << std::string(32, '-') << "\n\n";
  return 0;
}