#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/// Фільм.
struct Movie {
  std::string name;        // Назва
  std::string director;    // Режисер
  std::string releaseDate; // Дата випуску
  std::string country;     // Країна

  double dudget;    // Бюджет
  double boxOffice; // Касові збори
};

/// Надрукувати помилку.
void printError(const std::string &text) {
  std::cerr << "error: " << text << "\n\n";
}

/// Надрукувати повідомлення.
void printMessage(const std::string &text) {
  std::cout << "messange: " << text << "\n\n";
}

/// Встановити базуданих фільмів.
void setMovieDatabase(std::vector<Movie> &movieDatabase) {
  std::ifstream fin{"MovieDatabase.txt"};

  if (!fin) {
    printError("Failed to open 'MovieDatabase.txt' for reading.");
    return;
  }

  Movie movie;

  while (std::getline(fin, movie.name, ';') &&
         std::getline(fin, movie.director, ';') &&
         std::getline(fin, movie.releaseDate, ';') &&
         std::getline(fin, movie.country, ';') &&
         fin >> movie.dudget >> movie.boxOffice) {
    fin.get(); // Fix '\n' bug

    movieDatabase.push_back(movie);
  }
}

/// Зберегти базуданих фільмів.
void saveMovieDatabase(const std::vector<Movie> &movieDatabase) {
  std::ofstream fout{"MovieDatabase.txt"};

  if (!fout) {
    printError("Failed to open 'MovieDatabase.txt' for writing.");
    return;
  }

  for (const auto &movie : movieDatabase) {
    fout << movie.name << ';' << movie.director << ';' << movie.releaseDate
         << ';' << movie.country << ';' << movie.dudget << ' '
         << movie.boxOffice << '\n';
  }

  printMessage("Movie database saved.");
}

/// Отримати фільм.
Movie getMovie() {
  Movie movie;

  std::cout << "Enter movie name.\n"
            << "> ";
  std::getline(std::cin, movie.name);
  std::cout << '\n';

  std::cout << "Enter movie director.\n"
            << "> ";
  std::getline(std::cin, movie.director);
  std::cout << '\n';

  std::cout << "Enter movie realese date.\n"
            << "> ";
  std::getline(std::cin, movie.releaseDate);
  std::cout << '\n';

  std::cout << "Enter movie country.\n"
            << "> ";
  std::getline(std::cin, movie.country);
  std::cout << '\n';

  std::cout << "Enter movie dudget (milion).\n"
            << "> ";
  std::cin >> movie.dudget;
  std::cout << '\n';

  std::cout << "Enter movie box office (milion).\n"
            << "> ";
  std::cin >> movie.boxOffice;
  std::cout << '\n';
  return movie;
}

/// Отримати індекс фільму.
size_t getMovieIndex(const std::vector<Movie> &movieDatabase,
                     const std::string &movieName) {
  for (size_t i = 0; i < movieDatabase.size(); ++i) {
    if (movieDatabase[i].name == movieName)
      return i;
  }
  return SIZE_MAX;
}

/// Надрукувати фільм.
void printMovie(const Movie &movie) {
  std::cout << movie.name << '\n'
            << "  Director: " << movie.director << '\n'
            << "  Realease date: " << movie.releaseDate << '\n'
            << "  Country: " << movie.country << '\n'
            << "  Dudget: $" << movie.dudget << " (milion)\n"
            << "  Box office: $" << movie.boxOffice << " (milion)\n"
            << "  Profit: $" << movie.boxOffice - movie.dudget
            << " (milion)\n\n";
}

/// Надрукувати базу даних фільмів.
void printMovieDatabase(const std::vector<Movie> &movieDatabase) {
  if (movieDatabase.empty()) {
    printMessage("Movie database is empty.");
    return;
  }

  for (const auto &movie : movieDatabase) {
    std::cout << std::string(48, '-') << '\n';

    printMovie(movie);
  }

  std::cout << std::string(48, '-') << "\n\n";
}

/// Знайти фільм.
void searchMovie(const std::vector<Movie> &movieDatabase) {
  std::cout << "Enter movie name for search.\n"
            << "> ";
  std::string movieName;
  std::getline(std::cin, movieName);
  std::cout << '\n';

  const size_t movieIndex = getMovieIndex(movieDatabase, movieName);

  if (movieIndex == SIZE_MAX) {
    printError(movieName + " is not in the database.");
    return;
  }

  printMovie(movieDatabase[movieIndex]);
}

/// Видалити фільм.
void deleteMovie(std::vector<Movie> &movieDatabase) {
  std::cout << "Enter movie name for delete.\n"
            << "> ";
  std::string movieName;
  std::getline(std::cin, movieName);
  std::cout << '\n';

  const size_t movieIndex = getMovieIndex(movieDatabase, movieName);

  if (movieIndex == SIZE_MAX) {
    printError(movieName + " is not in the database.");
    return;
  }

  movieDatabase.erase(movieDatabase.begin() + movieIndex);
  printMessage(movieName + " has been deleted from the database.");
}

/// Отримати індекс меню.
unsigned getMenuIndex(const int &minIndex, const int &maxIndex) {
  std::cout << "MAIN MENU\n"
            << "  1. Print movies\n"
            << "  2. Add movie\n"
            << "  3. Delete movie\n"
            << "  4. Search movie\n"
            << "  5. Save changes\n"
            << "  6. Exit\n\n";

  unsigned menuIndex;

  while (true) {
    std::cout << "> ";
    std::cin >> menuIndex;
    std::cout << '\n';

    if (menuIndex >= minIndex && menuIndex <= maxIndex) {
      std::cin.ignore();
      return menuIndex;
    }

    printError("Menu index is incorrect.");
  }
}

int main() {
  std::vector<Movie> movieDatabase;
  setMovieDatabase(movieDatabase);

  while (true) {
    switch (getMenuIndex(1, 6)) {
    case 1:
      printMovieDatabase(movieDatabase);
      break;
    case 2:
      movieDatabase.push_back(getMovie());
      break;
    case 3:
      deleteMovie(movieDatabase);
      break;
    case 4:
      searchMovie(movieDatabase);
      break;
    case 5:
      saveMovieDatabase(movieDatabase);
      break;
    case 6:
      return 0;
    }
  }
  return 0;
}
