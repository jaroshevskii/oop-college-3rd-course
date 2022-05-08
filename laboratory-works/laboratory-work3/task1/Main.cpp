#include <array>
#include <cstddef>
#include <iomanip>
#include <iostream>

/// Number.
struct Number {
  double value{};
  int indexRow{};
  int indexCol{};
};

/// Returns a 2D array.
template <typename Type, size_t NumRows, size_t NumCols>
constexpr auto makeArray2D() {
  return std::array<std::array<Type, NumCols>, NumRows>{};
}

/// Returns a 2D array of numbers.
constexpr auto makeNumbers() {
  auto numbers = makeArray2D<double, 5, 5>();
  numbers = {{{0.0, 1.0, 2.0, 3.0, 4.0},
              {0.0, 1.0, 2.0, 3.0, 4.0},
              {0.0, 1.0, 2.0, 3.0, 4.0},
              {0.0, 1.0, 2.0, 3.0, 4.0},
              {0.0, 1.0, 2.0, 3.0, 4.0}}};
  return numbers;
}

/// Prints an 2D array.
template <typename Type, size_t NumRows, size_t NumCols>
void printArray2D(const std::array<std::array<Type, NumCols>, NumRows> &array2D,
                  const std::string &name = "Array 2D",
                  const std::string &terminator = "\n") {
  std::cout << name << ":\n";

  for (const auto &i : array2D) {
    std::cout << ' ';

    for (const auto &j : i)
      std::cout << ' ' << j;
    std::cout << '\n';
  }
  std::cout << terminator;
}

/// Prints numbers.
template <typename Type, size_t NumRows, size_t NumCols>
void printNumbers(const std::array<std::array<Type, NumCols>, NumRows> &numbers,
                  const std::string &name = "Numbers",
                  const std::string &terminator = "\n") {
  printArray2D(numbers, name, terminator);
}

/// Set the min and max number.
template <size_t NumRows, size_t NumCols>
void setNumberMinAndMax(
    Number &numberMin, Number &numberMax,
    const std::array<std::array<double, NumCols>, NumRows> &numbers) {
  // Assign to the min and max number the first number of numbers.
  numberMin.value = numbers[0][0];
  numberMax.value = numbers[0][0];

  // Finds the minimum and maximum number.
  for (auto i = 0; i < numbers.size(); ++i) {
    for (auto j = 0; j < numbers.front().size(); ++j) {
      if (numbers[i][j] < numberMin.value) {
        numberMin =
            Number{.value = numbers[i][j], .indexRow = i, .indexCol = j};
      }
      if (numbers[i][j] > numberMax.value) {
        numberMax =
            Number{.value = numbers[i][j], .indexRow = i, .indexCol = j};
      }
    }
  }
}

/// Returns the arithmetic mean of the rows.
template <size_t NumRows, size_t NumCols>
auto getArithmeticMeanOfRows(
    const std::array<std::array<double, NumCols>, NumRows> &numbers) {
  auto arithmeticMeanOfRows = std::array<double, NumRows>{};
  auto sumOfRow = 0.0;

  for (auto i = 0; i < numbers.size(); ++i) {
    sumOfRow = 0.0;

    for (const auto &number : numbers[i]) {
      sumOfRow += number;
    }

    arithmeticMeanOfRows[i] = sumOfRow / numbers.size();
  }
  return arithmeticMeanOfRows;
}

/// Prints array.
template <typename Type, size_t Size>
void printArray(const std::array<Type, Size> &array,
                const std::string &name = "Array",
                const std::string &terminator = "\n") {
  std::cout << name << ":\n";

  for (const auto &element : array) {
    std::cout << "  " << element << '\n';
  }
  std::cout << terminator;
}

/// Returns the product of the numbers of the main diagonal.
template <size_t NumRows, size_t NumCols>
double getProductOfNumbersOfMainDiagonal(
    const std::array<std::array<double, NumCols>, NumRows> &numbers) {
  auto productOfNumbers = 1.0;

  for (auto i = 0; i < numbers.size(); ++i) {
    productOfNumbers *= numbers[i][i];
  }
  return productOfNumbers;
}

/// Returns the sum of the numbers of the main diagonal.
template <size_t NumRows, size_t NumCols>
double getSumOfNumbersOfMainDiagonal(
    const std::array<std::array<double, NumCols>, NumRows> &numbers) {
  auto sumOfNumbers = 0.0;

  for (auto i = 0; i < numbers.size(); ++i) {
    sumOfNumbers += numbers[i][i];
  }
  return sumOfNumbers;
}

/// Returns the sum of numbers under the main diagonal.
template <size_t NumRows, size_t NumCols>
double getSumOfNumbersUnderMainDiagonal(
    const std::array<std::array<double, NumCols>, NumRows> &numbers) {
  auto sumOfNumbers = 0.0;

  for (auto i = 0; i < numbers.size(); ++i) {
    for (auto j = 0; j < numbers.front().size(); ++j) {
      if (i > j) {
        sumOfNumbers += numbers[i][j];
      }
    }
  }
  return sumOfNumbers;
}

int main() {
  // Set the accuracy of number output.
  std::cout << std::fixed << std::setprecision(2);

  const auto numbers = makeNumbers();
  printNumbers(numbers);

  auto numberMin = Number{};
  auto numberMax = Number{};

  // Finds and prints the min and max number.
  setNumberMinAndMax(numberMin, numberMax, numbers);
  std::cout << "Number min[" << numberMin.indexRow << "][" << numberMax.indexCol
            << "]: " << numberMin.value << '\n'
            << "Number max[" << numberMax.indexRow << "][" << numberMax.indexCol
            << "]: " << numberMax.value << "\n\n";

  // Finds and prints the arithmetic mean of rows.
  const auto arithmeticMeanOfRows = getArithmeticMeanOfRows(numbers);
  printArray(arithmeticMeanOfRows, "Arithmetic mean of rows");

  // Finds the product of the numbers of the main diagonal.
  const auto productOfNumbers = getProductOfNumbersOfMainDiagonal(numbers);
  // Finds the sum of the numbers of the main diagonal.
  const auto sumOfNumbersOfMainDiagonal =
      getSumOfNumbersOfMainDiagonal(numbers);
  // Finds the sum of numbers under the main diagonal.
  const auto sumOfNumbersUnderMainDiagonal =
      getSumOfNumbersUnderMainDiagonal(numbers);

  std::cout << "Product of the numbers of the main diagonal: "
            << productOfNumbers << '\n'
            << "Sum of the numbers of the main diagonal:     "
            << sumOfNumbersOfMainDiagonal << '\n'
            << "Sum of the Numbers under the main diagonal:  "
            << sumOfNumbersUnderMainDiagonal << '\n';
  return 0;
}
