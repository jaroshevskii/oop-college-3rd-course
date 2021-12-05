#include <array>
#include <iostream>

/// Надрукувати масив.
template <size_t Size>
void printArray(const std::array<std::array<int, Size>, Size> &array) {
  std::cout << "Array:\n";

  for (const auto &i : array) {
    std::cout << ' ';

    for (const auto &j : i)
      std::cout << ' ' << j;
    std::cout << '\n';
  }
  std::cout << '\n';
}

int main() {
  const size_t size = 5;
  std::array<std::array<int, size>, size> array{{{0, 1, 2, 3, 4},
                                                 {0, 1, 2, 3, 4},
                                                 {0, 1, 2, 3, 4},
                                                 {0, 1, 2, 3, 4},
                                                 {0, 1, 2, 3, 4}}};
  printArray(array);

  std::cout << "Values:";

  for (size_t i = 0; i < size; ++i) {
    if (array[i][i] == i) {
      std::cout << ' ' << array[i][i];
    }
  }
  std::cout << "\n\n";
  return 0;
}