#include <array>
#include <iostream>
#include <random>

/// Returns the int number from the user in the range from min to max.
int getIntFromUser(int min, int max) {
  auto number = 0;

  while (true) {
    std::cout << "> ";
    std::cin >> number;

    if (number >= min && number <= max) {
      return number;
    }

    if (number < min) {
      std::cerr << "error: The number entered must be greater than or equal to "
                << min << ".";
    } else if (number > max) {
      std::cerr << "error: The number entered must be less than or equal to "
                << max << ".";
    }
  }
}

/// Returns a random int number in the range from min to max.
int getRandomInt(int min, int max) {
  auto generator = std::mt19937{std::random_device{}()};
  auto distribution = std::uniform_int_distribution<int>{min, max};
  return distribution(generator);
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

int main() {
  std::cout << "Enter the max and min number to fill the numbers with random "
               "values in "
               "this range.\n";

  using integer = std::numeric_limits<int>;
  const auto randomMin = getIntFromUser(integer::min(), integer::max() - 1);
  const auto randomMax = getIntFromUser(integer::min() + 1, integer::max());

  std::cout << '\n';

  auto numbers = std::array<int, 12>{};

  // Fill in the numbers with random values.
  for (auto &number : numbers) {
    number = getRandomInt(randomMin, randomMax);
  }

  printArray(numbers, "Numbers");

  auto indexMin = 0;
  auto indexMax = 0;

  // Finds the index of the min and max number in numbers.
  for (auto i = 1; i < numbers.size(); ++i) {
    if (numbers[i] < numbers[indexMin]) {
      indexMin = i;
    } else if (numbers[i] > numbers[indexMax])
      indexMax = i;
  }

  std::cout << "Index min: " << indexMin << '\n'
            << "Index max: " << indexMax << "\n\n";

  if (numbers[indexMin] == numbers[indexMax]) {
    std::cout << "No need to swap the min and max elements. Elements are "
                 "the same.\n\n";
  } else {
    std::swap(numbers[indexMin], numbers[indexMax]);
    std::cout << "Min and max element are swapped.\n\n";

    printArray(numbers, "Numbers", "");
  }
  return 0;
}