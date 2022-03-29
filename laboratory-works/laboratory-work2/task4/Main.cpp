#include <algorithm>
#include <array>
#include <iostream>
#include <random>

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

/// Returns the count different elements in an ordered array.
template <size_t Size>
int getCountDifferentElements(const std::array<int, Size> &array) {
  int numDifferentElements{1};

  for (int i{1}; i < array.size(); ++i) {
    if (array[i] != array[i - 1]) {
      ++numDifferentElements;
    }
  }
  return numDifferentElements;
}

int main() {
  const int randomMin{-10};
  const int randomMax{10};
  
  std::cout << "Random min: " << randomMin << '\n'
            << "Random max: " << randomMax << "\n\n";

  std::array<int, 10> array{};

  // Fill in the array.
  for (auto &element : array) {
    element = getRandomInt(randomMin, randomMax);
  }

  // Sort the array in ascending order.
  std::sort(array.begin(), array.end());

  printArray(array);

  const auto countDifferentElements = getCountDifferentElements(array);

  std::cout << "Count of different elements: " << countDifferentElements << "\n\n";
  return 0;
}