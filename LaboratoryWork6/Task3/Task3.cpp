#include <iostream>
#include <sstream>
#include <string>

/// Отримати кількість букв.
int getNumberOfLetters(const std::string &text) {
  int numberOfLetters = 0;

  for (const auto &letter : text) {
    if ((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z'))
      ++numberOfLetters;
  }
  return numberOfLetters;
}

/// Видалити слова, які складаються з парної кількості букв.
void deleteWordsThatContainAnEvenNumberOfLetters(std::string &text) {
  std::stringstream textStream{text};

  std::string newText;
  std::string word;

  while (textStream >> word) {
    if (getNumberOfLetters(word) % 2 != 0)
      newText += word + ' ';
  }

  text = newText;
}

/// Надрукувати текст.
void printText(const std::string &text) {
  std::cout << "Text: " << text << "\n\n";
}

int main() {
  std::cout << "Enter text.\n"
            << "> ";
  std::string text;
  std::getline(std::cin, text);
  std::cout << '\n';

  // Видалити слова, які складаються з парної кількості букв.
  deleteWordsThatContainAnEvenNumberOfLetters(text);
  printText(text);
  return 0;
}