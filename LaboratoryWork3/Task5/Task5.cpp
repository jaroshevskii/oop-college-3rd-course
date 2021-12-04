#include <array>
#include <iostream>

/// Індекс.
struct Index {
  size_t i;
  size_t j;
};

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

/// Отримати мінімальний та максимальний індекс.
template <size_t Size>
void setMinAndMaxIndex(Index &minIndex, Index &maxIndex,
                       const std::array<std::array<int, Size>, Size> &array) {
  for (size_t i = 0; i < Size / 2; ++i) {
    for (size_t j = 0; j < Size; ++j) {
      if (j <= i || i + j >= Size - 1) {
        if (array[i][j] < array[minIndex.i][minIndex.j]) {
          minIndex.i = i;
          minIndex.j = j;
        }
        if (array[i][j] > array[maxIndex.i][maxIndex.j]) {
          maxIndex.i = i;
          maxIndex.j = j;
        }
      }
    }
  }
}

/// Надрукувати мінімальний та максимальний індекс.
void printMinAndMaxIndex(Index &minIndex, Index &maxIndex) {
  std::cout << "Min index[" << minIndex.i << "][" << minIndex.j << "]\n"
            << "Max index[" << maxIndex.i << "][" << maxIndex.j << "]\n"
            << '\n';
}

int main() {
  const size_t size = 6;
  std::array<std::array<int, size>, size> array{{{0, 1, 2, 3, 4, 5},
                                                 {0, 1, 2, 3, 4, 5},
                                                 {0, 1, 2, 3, 4, 5},
                                                 {0, 1, 2, 3, 4, 5},
                                                 {0, 1, 2, 3, 4, 5},
                                                 {0, 1, 2, 3, 4, 5}}};
  printArray(array);

  Index minIndex{0, 0};
  Index maxIndex{0, 0};

  setMinAndMaxIndex(minIndex, maxIndex, array);
  printMinAndMaxIndex(minIndex, maxIndex);
  return 0;
}