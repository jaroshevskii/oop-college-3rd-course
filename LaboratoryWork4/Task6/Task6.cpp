#include <array>
#include <iostream>

/// Надрукувати елемнт.
template <size_t Size>
void printElement(const std::array<int, Size> &array, size_t index) {
  std::cout << ' ' << array[index];

  if (++index < Size)
    printElement(array, index);
}

/// Надрукувати масив.
template <size_t Size>
void printArray(const std::array<int, Size> &array) {
  std::cout << "Array:";

  printElement(array, 0);
  std::cout << "\n\n";
}

int main() {
  const size_t size = 10;
  std::array<int, size> array{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  printArray(array);
  return 0;
}