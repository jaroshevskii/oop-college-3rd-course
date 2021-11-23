#include <array>
#include <iostream>

/// Встановити буфер.
template <size_t Size>
void setBuffer(std::array<int, Size> &buffer, const int &numeralSystem,
               int value, const int &index) {
  buffer[index] = value % numeralSystem;
  value /= numeralSystem;

  if (value == 0)
    return;

  setBuffer(buffer, numeralSystem, value, index - 1);
}

/// Надрукувати масив.
template <size_t Size>
void printBuffer(const std::array<int, Size> &buffer) {
  std::cout << "Buffer:";

  for (const auto &i : buffer)
    std::cout << ' ' << i;
  std::cout << '\n' << '\n';
}

int main() {
  const size_t size = 16;
  std::array<int, size> buffer = {};

  const int value = 128;
  const int numeralSystem = 8;

  setBuffer(buffer, numeralSystem, value, size - 1);

  printBuffer(buffer);
  return 0;
}