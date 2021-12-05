#include <iostream>
#include <vector>

/// Індекс.
struct Index {
  size_t i;
  size_t j;
};

/// Надрукувати помилку.
void printError(const std::string &text) {
  std::cerr << "error: " << text << "\n\n";
}

/// Надрукувати повідомлення.
void printMessage(const std::string &text) {
  std::cout << "messange: " << text << "\n\n";
}

/// Отримати максимальне значення масиву.
Index getMaxIndex(const std::vector<std::vector<int>> &array) {
  Index max{0, 0};

  for (size_t i = 0; i < array.size(); ++i) {
    for (size_t j = 0; j < array[i].size(); ++j) {
      if (array[i][j] > array[max.i][max.j])
        max = {i, j};
    }
  }
  return max;
}

/// Надрукувати масив.
void printArray(const std::vector<std::vector<int>> &array) {
  std::cout << "Array:\n";

  for (const auto &i : array) {
    std::cout << ' ';

    for (const auto &j : i)
      std::cout << ' ' << j;
    std::cout << '\n';
  }
  std::cout << '\n';
}

/// Надрукувати максимальний індекс.
void printMaxIndex(const Index &maxIndex) {
  std::cout << "Max index:\n"
            << "  i: " << maxIndex.i << '\n'
            << "  j: " << maxIndex.j << '\n'
            << '\n';
}

int main() {
  std::vector<std::vector<int>> array{{0, 1, 2, 3, 4},
                                      {0, 1, 2, 3, 4},
                                      {0, 1, 9, 3, 4},
                                      {0, 1, 2, 3, 4},
                                      {0, 1, 2, 3, 4}};
  printArray(array);

  const Index maxIndex = getMaxIndex(array);
  printMaxIndex(maxIndex);

  // Видалити рядок який знаходиться до рядка з максимальним елементом.
  if (maxIndex.i > 0) {
    array.erase(array.begin() + maxIndex.i - 1);
    printMessage(
        "The row before the row with the maximum element has been deleted.");
  } else {
    printError("The row cannot be delete.");
  }

  // Додати стовпець після стовпця з максимальним елементом.
  for (size_t i = 0; i < array.size(); ++i)
    array[i].insert(array[i].begin() + maxIndex.j + 1, 0);

  printArray(array);
  return 0;
}