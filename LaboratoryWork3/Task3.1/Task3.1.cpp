#include <array>
#include <iostream>

struct Element {
  size_t i;
  size_t j;
  int value;
};

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

/// Отримати мінімальний та максимальний елемент.
template <size_t Size>
void setMinAndMaxElement(Element &minElement, Element &maxElement,
                         const std::array<std::array<int, Size>, Size> &array) {
  for (size_t i = 1; i != Size; ++i) {
    for (size_t j = 1; j != Size; ++j) {
      if (array[i][j] < minElement.value)
        minElement = {i, j, array[i][j]};
      if (array[i][j] > maxElement.value)
        maxElement = {i, j, array[i][j]};
    }
  }
}

/// Надрукувати мінімальний та максимальний елемент.
void printMinAndMaxElement(Element &minElement, Element &maxElement) {
  std::cout << "Min element[" << minElement.i << "][" << minElement.j
            << "]: " << minElement.value << '\n'
            << "Max element[" << maxElement.i << "][" << maxElement.j
            << "]: " << maxElement.value << '\n'
            << '\n';
}

/// Отримати середє арифметичне рядків.
template <size_t Size>
std::array<double, Size>
getArithmeticMeanOfRows(const std::array<std::array<int, Size>, Size> &array) {
  std::array<double, Size> arithmeticMeanOfRows;
  int sumOfRows;

  for (size_t i = 0; i < Size; ++i) {
    sumOfRows = 0;

    for (size_t j = 0; j < Size; ++j)
      sumOfRows += array[i][j];

    arithmeticMeanOfRows[i] = static_cast<double>(sumOfRows) / Size;
  }
  return arithmeticMeanOfRows;
}

/// Надрукувати середнє арифметичне рядків.
template <size_t Size>
void printArithmeticMeanOfRows(
    const std::array<double, Size> &arithmeticMeanOfRows) {
  std::cout << "Arithmetic mean of rows:";

  for (const auto &value : arithmeticMeanOfRows)
    std::cout << ' ' << value;
  std::cout << '\n' << '\n';
}

/// Отримати добуток елементів головної діагоналі.
template <size_t Size>
int getProductOfElementsOfMainDiagonal(
    const std::array<std::array<int, Size>, Size> &array) {
  int productOfElements = 1;

  for (size_t i = 0; i != Size; ++i)
    productOfElements *= array[i][i];
  return productOfElements;
}

/// Отримати суму елементів головної діагоналі.
template <size_t Size>
int getSumOfElementsOfMainDiagonal(
    const std::array<std::array<int, Size>, Size> &array) {
  int sumOfElements = 0;

  for (size_t i = 0; i != Size; ++i)
    sumOfElements += array[i][i];
  return sumOfElements;
}

/// Отримати суму елементів під головною діагоналлю.
template <size_t Size>
int getSumOfElementsUnderMainDiagonal(
    const std::array<std::array<int, Size>, Size> &array) {
  int sumOfElements = 0;

  for (size_t i = 0; i != Size; ++i) {
    for (size_t j = 0; j != Size; ++j) {
      if (i > j)
        sumOfElements += array[i][j];
    }
  }
  return sumOfElements;
}

int main() {
  const size_t size = 5;
  std::array<std::array<int, size>, size> array = {{{0, 1, 2, 3, 4},
                                                    {0, 1, 2, 3, 4},
                                                    {0, 1, 2, 3, 4},
                                                    {0, 1, 2, 3, 4},
                                                    {0, 1, 2, 3, 4}}};

  printArray(array);

  Element minElement = {0, 0, array[0][0]};
  Element maxElement = {0, 0, array[0][0]};

  setMinAndMaxElement(minElement, maxElement, array);

  printMinAndMaxElement(minElement, maxElement);

  // Середнє арифметичне рядків.
  const std::array<double, size> arithmeticMeanOfRows =
      getArithmeticMeanOfRows(array);

  printArithmeticMeanOfRows(arithmeticMeanOfRows);

  // Добуток елементів головної діагоналі.
  const int productOfElementsOfMainDiagonal =
      getProductOfElementsOfMainDiagonal(array);

  std::cout << "The Product of the elements of the main diagonal: "
            << productOfElementsOfMainDiagonal << '\n'
            << '\n';

  // Сума елементів головної діагоналі.
  const int sumOfElementsOfMainDiagonal = getSumOfElementsOfMainDiagonal(array);

  std::cout << "The Sum of the elements of the main diagonal: "
            << sumOfElementsOfMainDiagonal << '\n'
            << '\n';

  // Сума елеметнтів під головною діагоналлю.
  const int sumOfElementsUnderMainDiagonal =
      getSumOfElementsUnderMainDiagonal(array);

  std::cout << "The sum of the elements under the main diagonal: "
            << sumOfElementsUnderMainDiagonal << '\n'
            << '\n';
  return 0;
}