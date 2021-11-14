#include <iostream>

/// Отримати рандомне число.
int getRandomNumber(const int &min, const int &max) {
  return rand() * (max - min) / RAND_MAX + min;
}

/// Надрукувати масив.
void printArray(const int *array, const int &lenght) {
  std::cout << "Array:\n";

  for (int i = 0; i < lenght; ++i)
    std::cout << "  [" << i << "] = " << array[i] << '\n';
  std::cout << '\n';
}

/// Надрукувати сповіщення.
void printNotification(const std::string &text) {
  std::cout << "notification: " << text << '\n' << '\n';
}

/// Отримати мінімальний індекс.
int getMinIndex(const int *array, const int &lenght) {
  int minValue = array[0];
  int minIndex = 0;

  for (int i = 1; i < lenght; ++i) {
    if (array[i] < minValue) {
      minValue = array[i];
      minIndex = i;
    }
  }
  return minIndex;
}

/// Отримати максимальний індекс.
int getMaxIndex(const int *array, const int &lenght) {
  int maxValue = array[0];
  int maxIndex = 0;

  for (int i = 1; i < lenght; ++i) {
    if (array[i] > maxValue) {
      maxValue = array[i];
      maxIndex = i;
    }
  }
  return maxIndex;
}

int main() {
  srand(static_cast<unsigned int>(time(0)));

  const int lenght = 12;
  int array[lenght];

  for (int i = 0; i < lenght; ++i)
    array[i] = getRandomNumber(INT8_MIN, INT8_MAX);

  printArray(array, lenght);

  const int minIndex = getMinIndex(array, lenght);
  const int maxIndex = getMaxIndex(array, lenght);

  std::cout << "Min index: " << minIndex << '\n'
            << "Max index: " << maxIndex << '\n'
            << '\n';

  if (array[minIndex] != array[maxIndex]) {
    printNotification("Swap the min and max values of the array.");

    std::swap(array[minIndex], array[maxIndex]);
  } else {
    printNotification(
        "Swap is not needed. The values of the array are the same.");
  }

  printArray(array, lenght);
  return 0;
}