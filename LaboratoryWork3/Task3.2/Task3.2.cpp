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

/// Надрукувати совбець.
template <size_t Size>
void printColumn(const std::array<int, Size> &column) {
  std::cout << "Column:";

  for (const auto &value : column)
    std::cout << ' ' << value;
  std::cout << '\n' << '\n';
}

/// Надрукувати помилку.
void printError(const std::string &text) {
  std::cout << '\n' << "error: " << text << '\n' << '\n';
}

/// Отримати індекс.
size_t getIndex(const size_t &min, const size_t &max) {
  size_t index;

  while (true) {
    std::cout << "> ";
    std::cin >> index;

    if (index >= min && index <= max)
      return index;
    if (index < min)
      printError("The index is too small.");
    if (index > max)
      printError("The index is too large.");
  }
}

/// Змінити стовбець.
template <size_t Size>
void changeColumn(std::array<std::array<int, Size>, Size> &array,
                  const std::array<int, Size> &column, const size_t &index) {
  for (size_t i = 0; i != Size; ++i)
    array[i][index] = column[i];
}

int main() {
  const size_t size = 5;
  std::array<std::array<int, size>, size> array = {{{0, 1, 2, 3, 4},
                                                    {0, 1, 2, 3, 4},
                                                    {0, 1, 2, 3, 4},
                                                    {0, 1, 2, 3, 4},
                                                    {0, 1, 2, 3, 4}}};

  printArray(array);

  const std::array<int, size> column = {6, 6, 6, 6, 6};

  printColumn(column);

  std::cout << "// Enter the index.\n";
  const size_t index = getIndex(0, size - 1);
  std::cout << '\n';

  changeColumn(array, column, index);

  printArray(array);
  return 0;
}