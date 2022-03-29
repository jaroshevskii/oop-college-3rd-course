#include <iostream>
#include <sstream>
#include <string>

/// Замінити великі літери в тексті на малі.
void replaceUppercaseLettersWithLowercase(std::string &text) {
  for (auto &letter : text) {
    if (letter >= 'A' && letter <= 'Z')
      letter += 32;
  }
}

/// Надрукувати текст.
void printText(const std::string &text) {
  std::cout << "Text: " << text << "\n\n";
}

/// Отримати найдовше слово.
std::string getLongestWord(const std::string &text) {
  std::stringstream textStream{text};

  std::string longestWord;
  textStream >> longestWord;

  std::string word;

  while (textStream >> word) {
    if (word.length() > longestWord.length())
      longestWord = word;
  }
  return longestWord;
}

/// Надрукувати найдовше слово.
void printLongestWord(const std::string &longestWord) {
  std::cout << "Longest word: " << longestWord << "\n\n";
}

/// Є приголосною.
bool isConsonant(const char &letter) {
  switch (letter) {
  case 'b':
  case 'c':
  case 'd':
  case 'f':
  case 'g':
  case 'h':
  case 'j':
  case 'k':
  case 'l':
  case 'm':
  case 'n':
  case 'p':
  case 'q':
  case 'r':
  case 's':
  case 't':
  case 'v':
  case 'w':
  case 'x':
  case 'z':
    return true;
  default:
    return false;
  }
}

/// Отримати кількість приголосних.
int getNumberOfConsonants(const std::string &text) {
  int numberOfConsonants = 0;

  for (const auto &letter : text) {
    if (isConsonant(letter))
      ++numberOfConsonants;
  }
  return numberOfConsonants;
}

/// Видалити слова, які містять непарну кількість приголосних.
void deleteWordsThatContainAnOddNumberOfConsonants(std::string &text) {
  std::stringstream textStream{text};

  std::string newText;
  std::string word;

  while (textStream >> word) {
    if (getNumberOfConsonants(word) % 2 == 0)
      newText += word + ' ';
  }

  text = newText;
}

int main() {
  std::cout << "Enter text.\n"
            << "> ";
  std::string text;
  std::getline(std::cin, text);
  std::cout << '\n';

  // Замінити великі літери в тексті на малі.
  replaceUppercaseLettersWithLowercase(text);
  printText(text);

  // Отримати найдовше слово.
  const std::string longestWord = getLongestWord(text);
  printLongestWord(longestWord);

  // Видалити слова, які містять непарну кількість приголосних.
  deleteWordsThatContainAnOddNumberOfConsonants(text);
  printText(text);
  return 0;
}