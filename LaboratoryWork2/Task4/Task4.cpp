#include <array>
#include <iostream>

/// Отримати кількість різних чисел.
template <size_t Size>
int getNumberOfDifferentNumbers(const std::array<int, Size> &array) {
  int numberOfDifferentNumber = 1;

  for (size_t i = 1; i != Size; ++i) {
    if (array[i] != array[i - 1])
      ++numberOfDifferentNumber;
  }
  return numberOfDifferentNumber;
}

/// Надрукувати масив.
template <size_t Size> void printArray(const std::array<int, Size> &array) {
  std::cout << "Array:";

  for (const auto &i : array)
    std::cout << ' ' << i;
  std::cout << "\n\n";
}

int main() {
  const size_t size = 10;
  std::array<int, size> array{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  printArray(array);

  // Кількість різних чисел.
  const int numberOfDifferentNumbers = getNumberOfDifferentNumbers(array);

  std::cout << "The number of different numbers: " << numberOfDifferentNumbers
            << "\n\n";
  return 0;
}