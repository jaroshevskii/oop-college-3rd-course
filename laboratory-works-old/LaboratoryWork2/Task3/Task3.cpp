#include <array>
#include <iostream>

/// Надрукувати повідомлення.
void printMessage(const std::string &text) {
  std::cout << "messange: " << text << "\n\n";
}

/// Отримати рандомне число.
int getRandomNumber(const int &min, const int &max) {
  return rand() * (max - min) / RAND_MAX + min;
}

/// Надрукувати масив.
template <size_t Size> void printArray(const std::array<int, Size> &array) {
  std::cout << "Array:";

  for (const auto &i : array)
    std::cout << ' ' << i;
  std::cout << "\n\n";
}

int main() {
  srand(static_cast<unsigned int>(time(0)));

  const size_t size = 10;
  std::array<int, size> array;

  // Встановити масив.
  for (auto &i : array)
    i = getRandomNumber(INT8_MIN, INT8_MAX);

  printArray(array);

  int minIndex = 0;
  int maxIndex = 0;

  // Встановити мінімальнй та максимальний індекс.
  for (size_t i = 1; i != size; ++i) {
    if (array[i] < array[minIndex])
      minIndex = i;
    if (array[i] > array[maxIndex])
      maxIndex = i;
  }
  
  std::cout << "Min index: " << minIndex << '\n'
            << "Max index: " << maxIndex << "\n\n";

  if (array[minIndex] == array[maxIndex]) {
    printMessage("Swap min and max number not need. All numbers are the same.");
  } else {
    std::swap(array[minIndex], array[maxIndex]);

    printMessage("The min and max number are swapped.");
  }

  printArray(array);
  return 0;
}