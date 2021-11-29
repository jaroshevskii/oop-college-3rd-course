#include <iostream>
#include <vector>

/// Надрукувати помилку.
void printError(const std::string &text) {
  std::cerr << "error: " << text << '\n' << '\n';
}

/// Надрукувати повідомлення.
void printMessage(const std::string &text) {
  std::cout << "messange: " << text << '\n' << '\n';
}

/// Надрукувати масив.
void printArray(const std::vector<int> &array) {
  std::cout << "Array:";

  for (const auto &i : array)
    std::cout << ' ' << i;
  std::cout << '\n' << '\n';
}

int main() {
  std::vector<int> array{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  printArray(array);

  if (array.size() < 5) {
    printError("The array must consist of at least 5 elements.");

    // Змінитии розмір масиву до 5 елементів.
    array.resize(5);
    printMessage("Array resized to 5 elements.");
  }

  // Видалити останні 5 елементів масиву.
  array.resize(array.size() - 5);
  
  // Додати на початок масиву 3 елементи.
  for (int i = 0; i < 3; ++i)
    array.insert(array.begin(), array.front() + 2);

  printArray(array);
  return 0;
}