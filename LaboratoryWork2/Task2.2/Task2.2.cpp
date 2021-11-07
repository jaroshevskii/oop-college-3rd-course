#include <iostream>

/// Надрукувати помилку.
void printError(const std::string &text) {
  std::cout << '\n' << "error: " << text << '\n' << '\n';
}

/// Отримати ціле число.
int getInt(const int &min, const int &max) {
  int value;

  while (true) {
    std::cout << "> ";
    std::cin >> value;

    if (value >= min && value <= max)
      return value;
    if (value < min)
      printError("The value is too small.");
    if (value > max)
      printError("The value is too large.");
  }
}

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

/// Отримати індекс мінімального значення масиву за модулем.
int getIndexOfMinValueOfArrayModulo(const int *array, const int &lenght) {
  int minValue = abs(array[0]);
  int minIndex = 0;

  for (int i = 1; i < lenght; ++i) {
    if (abs(array[i]) < minValue) {
      minValue = abs(array[i]);
      minIndex = i;
    }
  }
  return minIndex;
}

/// Отримати суму модулів значень масиву.
int getSumOfModulesOfValuesOfArray(const int *array, const int &lenght) {
  int sumOfModule = 0;
  bool isSum = false;

  for (int i = 0; i < lenght; ++i) {
    if (isSum)
      sumOfModule += abs(array[i]);
    else if (array[i] < 0)
      isSum = true;
  }
  return sumOfModule;
}

int main() {
  srand(static_cast<unsigned int>(time(0)));

  std::cout << "// Enter the min and max values to create random numbers.\n";
  const int minRandom = getInt(INT16_MIN, INT16_MAX);
  const int maxRandom = getInt(minRandom, INT16_MAX);
  std::cout << '\n';

  const int lenght = 10;
  int array[lenght];

  for (int i = 0; i < lenght; ++i)
    array[i] = getRandomNumber(minRandom, maxRandom);

  printArray(array, lenght);

  // Індекс мінімального значання масиву за модулем.
  const int indexOfMinValueOfArrayModulo =
      getIndexOfMinValueOfArrayModulo(array, lenght);

  std::cout << "The index of the minimum value of the array modulo: "
            << indexOfMinValueOfArrayModulo << '\n'
            << '\n';

  // Cума модулів значень масиву.
  const int sumOfModulesOfValuesOfArray =
      getSumOfModulesOfValuesOfArray(array, lenght);

  std::cout << "The sum of the modules of the values of the array: "
            << sumOfModulesOfValuesOfArray << '\n'
            << '\n';
  return 0;
}