#include <array>
#include <iostream>

int main() {
  const size_t size = 5;
  std::array<std::array<int, size>, size> array{{{0, 1, 2, 3, 4},
                                                 {0, 1, 2, 3, 4},
                                                 {0, 1, 2, 3, 4},
                                                 {0, 1, 2, 3, 4},
                                                 {0, 1, 2, 3, 4}}};

  std::cout << "Array:\n";

  for (size_t i = 0; i < size; ++i) {
    std::cout << ' ';

    for (size_t j = 0; j < size; ++j) {
      if (i > j)
        std::cout << ' ' << &array[i][j];
    }
    std::cout << '\n';
  }
  std::cout << '\n';
  return 0;
}