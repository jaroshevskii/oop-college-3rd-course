#include <array>
#include <iostream>
#include <limits>
#include <random>

/// Returns an int number in the range from min to max.
int getInt(int min, int max) {
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

/// Print array.
template <typename Type, size_t Size>
void printArray(const std::array<Type, Size> &array) {
  std::cout << "Array:";

  for (const auto &element : array) {
    std::cout << ' ' << element;
  }
  std::cout << "\n\n";
}

/// Returns the index of the min array element by modulus.
template <size_t Size>
int getIndexOfMinElementByModulus(const std::array<int, Size> &array) {
  int indexOfMinElement{0};

  for (int i{0}; i < array.size(); ++i) {
    if (abs(array[i]) < abs(array[indexOfMinElement]))
      indexOfMinElement = i;
  }
  return indexOfMinElement;
}

/// Returns the sum of the modules of the array elements located after the first
/// negative element.
template <size_t Size>
int getSumOfModulesOfElements(const std::array<int, Size> &array) {
  bool negativeElementFound{false};
  int sum{0};

  for (const auto &element : array) {
    if (negativeElementFound) {
      sum += abs(element);
    } else if (element < 0) {
      negativeElementFound = true;
    }
  }
  return sum;
}

int main() {
  const auto intMin{std::numeric_limits<int>::min()};
  const auto intMax{std::numeric_limits<int>::max()};

  std::cout << "Enter the max and min to fill the array with random numbers in "
               "this range.\n";
  const auto randomMin{getInt(intMin, intMax - 1)};
  const auto randomMax{getInt(randomMin + 1, intMax)};
  std::cout << '\n';

  std::array<int, 10> array{};

  // Fill in the array.
  for (auto &element : array) {
    element = getRandomInt(randomMin, randomMax);
  }

  printArray(array);

  const auto indexOfMinElementByModulus = getIndexOfMinElementByModulus(array);

  std::cout << "Index of the min element by modulus: "
            << indexOfMinElementByModulus << "\n\n";

  const auto sumOfModulesOfElements = getSumOfModulesOfElements(array);

  std::cout << "Sum of the modules of the elements located after the first "
               "negative element: "
            << sumOfModulesOfElements << "\n\n";
  return 0;
}