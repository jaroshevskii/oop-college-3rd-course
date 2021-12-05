#include <array>
#include <iostream>

/// Надрукувати помилку.
void printError(const std::string &text) {
  std::cerr << "error: " << text << "\n\n";
}

/// Отримати ціле число.
int getNumber(const int &min, const int &max) {
  int number;

  while (true) {
    std::cout << "> ";
    std::cin >> number;

    if (number >= min && number <= max)
      return number;
    if (number < min)
      printError("The number is too small.");
    if (number > max)
      printError("The number is too large.");
  }
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

/// Отримати індекс мінімального числа за модулем.
template <size_t Size>
size_t getIndexOfMinNumberPerModule(const std::array<int, Size> &array) {
  size_t minIndex = 0;

  for (size_t i = 1; i != Size; ++i) {
    if (abs(array[i]) < abs(array[minIndex]))
      minIndex = i;
  }
  return minIndex;
}

/// Отримати суму модулів чисел, розташованих після першого від'ємного числа.
template <size_t Size>
int getSumOfModulesOfNumberLocatedAfterFirstNegativeNumber(
    const std::array<int, Size> &array) {
  bool isFirstNegativeNumber = false;
  int sum = 0;

  for (const auto &number : array) {
    if (isFirstNegativeNumber)
      sum += abs(number);
    else if (number < 0)
      isFirstNegativeNumber = true;
  }
  return sum;
}

int main() {
  srand(static_cast<unsigned int>(time(0)));

  std::cout << "// Enter the min and max numbers to create random numbers.\n";
  const int minRandom = getNumber(INT_MIN, INT_MAX);
  const int maxRandom = getNumber(minRandom, INT_MAX);
  std::cout << '\n';

  const size_t size = 10;
  std::array<int, size> array;

  // Встановити масив.
  for (auto &i : array)
    i = getRandomNumber(minRandom, maxRandom);

  printArray(array);

  // Індекс мінімального значення за модулем.
  const size_t indexOfMinNumberPerModule = getIndexOfMinNumberPerModule(array);

  std::cout << "Index of minimum value per module: "
            << indexOfMinNumberPerModule << "\n\n";

  // Сума модулів чисел, розташованих після першого від'ємного числа.
  const int sumOfModulesOfNumberLocatedAfterFirstNegativeNumber =
      getSumOfModulesOfNumberLocatedAfterFirstNegativeNumber(array);

  std::cout << "The sum of the modules of the numbers after the first negative "
               "number: "
            << sumOfModulesOfNumberLocatedAfterFirstNegativeNumber << "\n\n";
  return 0;
}