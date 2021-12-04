#include <array>
#include <iomanip>
#include <iostream>

/// Елемент.
struct Element {
  size_t i;
  size_t j;
  double value;
};

/// Надрукувати масив.
template <size_t Size>
void printArray(const std::array<std::array<double, Size>, Size> &array) {
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
void setMinAndMaxElement(
    Element &minElement, Element &maxElement,
    const std::array<std::array<double, Size>, Size> &array) {
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

/// Встановити середє арифметичне рядків.
template <size_t Size>
void setArithmeticMeanOfRows(
    std::array<double, Size> &arithmeticMeanOfRows,
    const std::array<std::array<double, Size>, Size> &array) {
  int sumOfRows;

  for (size_t i = 0; i < Size; ++i) {
    sumOfRows = 0;

    for (size_t j = 0; j < Size; ++j)
      sumOfRows += array[i][j];

    arithmeticMeanOfRows[i] = sumOfRows / Size;
  }
}

/// Надрукувати середнє арифметичне рядків.
template <size_t Size>
void printArithmeticMeanOfRows(
    const std::array<double, Size> &arithmeticMeanOfRows) {
  std::cout << "Arithmetic mean of rows:";

  for (const auto &i : arithmeticMeanOfRows)
    std::cout << ' ' << i;
  std::cout << '\n' << '\n';
}

/// Отримати добуток елементів головної діагоналі.
template <size_t Size>
double getProductOfElementsOfMainDiagonal(
    const std::array<std::array<double, Size>, Size> &array) {
  double productOfElements = 1.0;

  for (size_t i = 0; i != Size; ++i)
    productOfElements *= array[i][i];
  return productOfElements;
}

/// Отримати суму елементів головної діагоналі.
template <size_t Size>
double getSumOfElementsOfMainDiagonal(
    const std::array<std::array<double, Size>, Size> &array) {
  double sumOfElements = 0.0;

  for (size_t i = 0; i != Size; ++i)
    sumOfElements += array[i][i];
  return sumOfElements;
}

/// Отримати суму елементів під головною діагоналлю.
template <size_t Size>
double getSumOfElementsUnderMainDiagonal(
    const std::array<std::array<double, Size>, Size> &array) {
  double sumOfElements = 0.0;

  for (size_t i = 0; i != Size; ++i) {
    for (size_t j = 0; j != Size; ++j) {
      if (i > j)
        sumOfElements += array[i][j];
    }
  }
  return sumOfElements;
}

int main() {
  // Встановити точність виведення чисел.
  std::cout << std::fixed << std::setprecision(2);

  const size_t size = 5;
  std::array<std::array<double, size>, size> array{{{0.0, 1.0, 2.0, 3.0, 4.0},
                                                    {0.0, 1.0, 2.0, 3.0, 4.0},
                                                    {0.0, 1.0, 2.0, 3.0, 4.0},
                                                    {0.0, 1.0, 2.0, 3.0, 4.0},
                                                    {0.0, 1.0, 2.0, 3.0, 4.0}}};
  printArray(array);

  Element minElement{0, 0, array[0][0]};
  Element maxElement{0, 0, array[0][0]};

  setMinAndMaxElement(minElement, maxElement, array);
  printMinAndMaxElement(minElement, maxElement);

  // Середнє арифметичне рядків.
  std::array<double, size> arithmeticMeanOfRows{};
  setArithmeticMeanOfRows(arithmeticMeanOfRows, array);

  printArithmeticMeanOfRows(arithmeticMeanOfRows);

  // Добуток елементів головної діагоналі.
  const double productOfElementsOfMainDiagonal =
      getProductOfElementsOfMainDiagonal(array);

  std::cout << "The product of the elements of the main diagonal: "
            << productOfElementsOfMainDiagonal << '\n'
            << '\n';

  // Сума елементів головної діагоналі.
  const double sumOfElementsOfMainDiagonal =
      getSumOfElementsOfMainDiagonal(array);

  std::cout << "The sum of the elements of the main diagonal: "
            << sumOfElementsOfMainDiagonal << '\n'
            << '\n';

  // Сума елеметнтів під головною діагоналлю.
  const double sumOfElementsUnderMainDiagonal =
      getSumOfElementsUnderMainDiagonal(array);

  std::cout << "The sum of the elements under the main diagonal: "
            << sumOfElementsUnderMainDiagonal << '\n'
            << '\n';
  return 0;
}