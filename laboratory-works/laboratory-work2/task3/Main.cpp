#include <array>
#include <iostream>
#include <random>

/// Returns a random int number in the range from min to max.
int getRandomInt(int min, int max) {
  std::mt19937 generator{std::random_device{}()};
  std::uniform_int_distribution<int> distribution{min, max};
  return distribution(generator);
}

/// Print array.
template <typename Type, size_t Size>
void printArray(const std::array<Type, Size> &array) {
  std::cout << "Array:";

  for (const auto &element : array)
    std::cout << ' ' << element;
  std::cout << "\n\n";
}

int main() {
  const int randomMin = -10;
  const int randomMax = 10;

  std::array<int, 12> array;

  // Fill in the array.
  for (auto &element : array)
    element = getRandomInt(randomMin, randomMax);

  printArray(array);

  int indexMin = 0;
  int indexMax = 0;

  // Find the index of the min and max element of the array.
  for (size_t i = 1; i < array.size(); ++i) {
    if (array[i] < array[indexMin])
      indexMin = i;
    if (array[i] > array[indexMax])
      indexMax = i;
  }

  std::cout << "Index min:  " << indexMin << '\n'
            << "Index max:  " << indexMax << "\n\n";

  if (array[indexMin] == array[indexMax]) {
    std::cout << "No need to swap the min and max elements. All elements are "
                 "the same.\n\n";
  } else {
    std::swap(array[indexMin], array[indexMax]);

    std::cout << "Min and max element are swapped.\n\n";

    printArray(array);
  }
  return 0;
}