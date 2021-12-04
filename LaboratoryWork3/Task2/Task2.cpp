#include <array>
#include <iostream>

/// Надрукувати помилку.
void printError(const std::string &text) {
  std::cerr << "error: " << text << '\n' << '\n';
}

/// Надрукувати повідомлення.
void printMessage(const std::string &text) {
  std::cout << "messange: " << text << '\n' << '\n';
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

/// Надрукувати совбець.
template <size_t Size> void printColumn(const std::array<int, Size> &column) {
  std::cout << "Column:";

  for (const auto &i : column)
    std::cout << ' ' << i;
  std::cout << '\n' << '\n';
}

/// Отримати рядок.
size_t getRow(const size_t &min, const size_t &max) {
  std::cout << "// Enter the row.\n";
  size_t row;

  while (true) {
    std::cout << "> ";
    std::cin >> row;
    std::cout << '\n';

    if (row >= min && row <= max)
      return row;

    printError("The row is incorrect.");
  }
}

/// Змінити стовбець.
template <size_t Size>
void changeColumn(std::array<std::array<int, Size>, Size> &array,
                  const std::array<int, Size> &column, const size_t &row) {
  for (size_t i = 0; i != Size; ++i)
    array[i][row] = column[i];
}

int main() {
  const size_t size = 5;
  std::array<std::array<int, size>, size> array{{{0, 1, 2, 3, 4},
                                                 {0, 1, 2, 3, 4},
                                                 {0, 1, 2, 3, 4},
                                                 {0, 1, 2, 3, 4},
                                                 {0, 1, 2, 3, 4}}};
  printArray(array);

  const std::array<int, size> column{6, 6, 6, 6, 6};
  printColumn(column);

  const size_t row = getRow(0, size - 1);

  changeColumn(array, column, row);
  printMessage("Column changed.");

  printArray(array);
  return 0;
}