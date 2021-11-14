#include <iostream>

/// Отримати рандомне число.
int getRandomNumber(const int &min, const int &max) {
  return rand() * (max - min) / RAND_MAX + min;
}

/// Отримати рандомне число.
double getRandomNumber(const double &min, const double &max) {
  return rand() * (max - min) / RAND_MAX + min;
}

/// Надрукувати помилку.
void printError(const std::string &text) {
  std::cout << '\n' << "error: " << text << '\n' << '\n';
}

/// Отримати значення масиву.
double getArrayValue(const int &index) {
  switch (index) {
  case 0:
    return getRandomNumber(-4, -2);
  case 1:
    return getRandomNumber(100, 299);
  case 2: {
    int value;

    while (true) {
      value = getRandomNumber(-35, 1);

      if (value % 2 == 0)
        return value;
    }
  }
  case 3:
    return getRandomNumber(-128, 127);
  case 4: {
    int value;

    while (true) {
      value = getRandomNumber(-7, 12);

      if (value % 2 != 0)
        return value;
    }
  }
  case 5:
    return getRandomNumber(-7.85, 28 * sqrt(3));
  case 6:
    return getRandomNumber(-100, 100);
  case 7:
    return getRandomNumber(23, 71);
  case 8:
    return getRandomNumber(0, 1);
  case 9:
    return getRandomNumber(sqrt(17), sqrt(182));
  default:
    printError("Invalid index.");
    return 0;
  }
}

/// Надрукувати масив.
void printArray(const double *array, const int &lenght) {
  std::cout << "Array:\n";

  for (int i = 0; i < lenght; ++i)
    std::cout << "  [" << i << "] = " << array[i] << '\n';
  std::cout << '\n';
}

int main() {
  srand(static_cast<unsigned int>(time(0)));

  const int lenght = 10;
  double array[lenght];
  
  for (int i = 0; i < lenght; ++i)
    array[i] = getArrayValue(i);

  printArray(array, lenght);
  return 0;
}