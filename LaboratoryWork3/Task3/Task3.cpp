#include <algorithm>
#include <array>
#include <iostream>

/// Надрукувати повідомлення.
void printMessage(const std::string &text) {
  std::cout << "messange: " << text << "\n\n";
}

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

/// Відсортувати антидіагональ.
template <size_t Size>
void sortAntidiagonal(std::array<std::array<int, Size>, Size> &array) {
  std::array<int, Size> antidiagonal;

  for (size_t i = 0; i < Size; ++i)
    antidiagonal[i] = array[i][Size - 1 - i];

  std::sort(antidiagonal.begin(), antidiagonal.end());

  for (size_t i = 0; i < Size; ++i)
    array[i][Size - 1 - i] = antidiagonal[i];
}

int main() {
  const size_t size = 5;
  std::array<std::array<int, size>, size> array{{{0, 1, 2, 3, 4},
                                                 {0, 1, 2, 3, 4},
                                                 {0, 1, 2, 3, 4},
                                                 {0, 1, 2, 3, 4},
                                                 {0, 1, 2, 3, 4}}};
  printArray(array);

  sortAntidiagonal(array);
  printMessage("Antidiagonal sorted.");

  printArray(array);
  return 0;
}