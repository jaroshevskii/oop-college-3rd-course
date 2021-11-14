#include <iostream>

/// Отримати кылькість різних значень масиву.
int getNumberOfDifferentValueArray(const int *array, const int &lenght) {
  int numberOfDifferentValue = 1;
 
  for (int i = 1; i < lenght; ++i) {
      if (array[i] != array[i - 1])
        ++numberOfDifferentValue;    
    }
  return numberOfDifferentValue;
}

/// Надрукувати масив.
void printArray(const int *array, const int &lenght) {
  std::cout << "Array:\n";

  for (int i = 0; i < lenght; ++i)
    std::cout << "  [" << i << "] = " << array[i] << '\n';
  std::cout << '\n';
}

int main() {
  const int lenght = 10;
  int array[lenght] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  
  printArray(array, lenght);

  // Кількість різних значень масиву.
  const int numberOfDifferentValueOfArray =
      getNumberOfDifferentValueArray(array, lenght);

  std::cout << "The number of different value of array: "
            << numberOfDifferentValueOfArray << '\n'
            << '\n';
  return 0;
}