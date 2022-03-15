#include <array>
#include <cmath>
#include <iostream>
#include <random>

/// Returns a random int number in the range from min to max.
int getRandomInt(int min, int max) {
  std::mt19937 generator{std::random_device{}()};
  std::uniform_int_distribution<int> distribution{min, max};
  return distribution(generator);
}

/// Returns a random double number in the range from min to max.
double getRandomDouble(double min, double max) {
  std::mt19937 generator{std::random_device{}()};
  std::uniform_real_distribution<double> distribution{min, max};
  return distribution(generator);
}

/// Returns an array element.
double getArrayElement(size_t index) { 
  switch (index) {
  case 0:
    return getRandomInt(-4, 0);
  case 1:
    return getRandomInt(100, 299);
  case 2:
    while (true) {
      if (const auto element = getRandomInt(-35, 1); element % 2 == 0)
        return element;
    }
  case 3:
    return getRandomInt(-128, 127);
  case 4:
    while (true) {
      if (const auto element = getRandomInt(-7, 12); element % 2 != 0)
        return element;
    }
  case 5:
    return getRandomDouble(-7.85, 28.0 * sqrt(3.0));
  case 6:
    return getRandomInt(-100, 100);
  case 7:
    return getRandomInt(23, 71);
  case 8:
    return getRandomInt(0, 1);
  case 9:
    return getRandomDouble(sqrt(17.0), sqrt(182.0));
  default:
    std::cerr << "error: Unknown " << index
              << " array index. The element will be set to 0.\n";
    return 0.0;
  }
}

/// Print array.
template <typename Type, size_t Size>
void printArray(const std::array<Type, Size> &array) {
  std::cout << "Array:\n";

  for (const auto &element : array)
    std::cout << "  " << element << '\n';
  std::cout << '\n';
}

int main() {
  std::array<double, 10> array;

  // Fill in the array.
  for (size_t i = 0; i < array.size(); ++i)
    array[i] = getArrayElement(i);

  printArray(array);
  return 0;
}