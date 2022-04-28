#include <array>
#include <cmath>
#include <iostream>
#include <limits>
#include <random>
#include <string>

/// Returns the int number from the user in the range from min to max.
int getIntFromUser(int min, int max) {
  int number{};

  while (true) {
    std::cout << "> ";
    std::cin >> number;

    if (number >= min && number <= max) {
      return number;
    }

    if (number < min) {
      std::cerr << "error: The number entered must be greater than or equal to "
                << min << ".";
    } else if (number > max) {
      std::cerr << "error: The number entered must be less than or equal to "
                << max << ".";
    }
  }
}

/// Returns a random int number in the range from min to max.
int getRandomInt(int min, int max) {
  std::mt19937 generator{std::random_device{}()};
  std::uniform_int_distribution<int> distribution{min, max};
  return distribution(generator);
}

/// Prints array.
template <typename Type, size_t Size>
void printArray(const std::array<Type, Size> &array,
                const std::string &name = "Array",
                const std::string &terminator = "\n") {
  std::cout << name << ":\n";

  for (const auto &element : array) {
    std::cout << "  " << element << '\n';
  }
  std::cout << terminator;
}

/// Returns the index of the minimum number modulo.
template <size_t Size>
int getIndexOfMinNumberModulo(const std::array<int, Size> &numbers) {
  int indexOfMinElement{0};

  for (int i{0}; i < numbers.size(); ++i) {
    if (std::abs(numbers[i]) < std::abs(numbers[indexOfMinElement])) {
      indexOfMinElement = i;
    }
  }
  return indexOfMinElement;
}

/// Returns the sum of the modules of numbers located after the first negative
/// number.
template <size_t Size>
int getSumOfModulesOfNumbers(const std::array<int, Size> &numbers) {
  bool negativeNumberFound{false};
  int sum{0};

  for (const auto &number : numbers) {
    if (negativeNumberFound) {
      sum += std::abs(number);
    } else if (number < 0) {
      negativeNumberFound = true;
    }
  }
  return sum;
}

int main() {
  std::cout << "Enter the max and min number to fill the numbers with random values in "
               "this range.\n";

  using integer = std::numeric_limits<int>;
  const auto randomMin = getIntFromUser(integer::min(), integer::max() - 1);
  const auto randomMax = getIntFromUser(integer::min() + 1, integer::max());

  std::cout << '\n';

  std::array<int, 10> numbers{};

  // Fill in the numbers with random values.
  for (auto &number : numbers) {
    number = getRandomInt(randomMin, randomMax);
  }

  printArray(numbers, "Numbers");

  // Finds and prints the minimum modulus index.
  const auto index = getIndexOfMinNumberModulo(numbers);
  std::cout << "Index of the min number modulo: " << index << '\n';

  // Finds and prints the sum of the modules of the numbers located after the
  // first negative number.
  const auto sum = getSumOfModulesOfNumbers(numbers);
  std::cout << "Sum of the modules of the numbers located after the first "
               "negative number: "
            << sum << '\n';
  return 0;
}