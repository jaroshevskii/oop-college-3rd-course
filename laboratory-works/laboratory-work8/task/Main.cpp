#include <iostream>

class Doctor {
private:
  std::string myFirstName{};
  std::string myMiddleName{};
  std::string myLastName{};

  std::string mySpecialty{};
  int myExperience{};
  int myMaxNumPatients{};

  // Service fees for one patient.
  double myServiceFees{};

public:
  Doctor() = default;

  Doctor(const std::string &firstName, const std::string &middleName,
         const std::string &lastName, const std::string &specialty,
         int experience, int maxNumParients, double serviceFees)
      : myFirstName{firstName}, myMiddleName{middleName}, myLastName{lastName},
        mySpecialty{specialty}, myExperience{experience},
        myMaxNumPatients{maxNumParients}, myServiceFees{serviceFees} {}

  // MARK: get- methods.

  /// Returns the first name.
  std::string getFirstName() const { return myFirstName; }

  /// Returns the middle name.
  std::string getMiddleName() const { return myMiddleName; }

  /// Returns the last name.
  std::string getLastName() const { return myLastName; }

  /// Returns the specialty.
  std::string getSpecialty() const { return mySpecialty; }

  /// Returns the experience.
  int getExperience() const { return myExperience; }

  /// Returns the max number of partients.
  int getMaxNumParients() const { return myMaxNumPatients; }

  /// Returns the servece fees.
  double getServiceFees() const { return myServiceFees; }

  // MARK: set- methods.

  /// Set the first name.
  void setFirstName(const std::string &firstName) { myFirstName = firstName; }

  /// Set the middle name.
  void setMiddleName(const std::string &middleName) {
    myMiddleName = middleName;
  }

  /// Set the last name.
  void setLastName(const std::string &lastName) { myLastName = lastName; }

  /// Set the specialty.
  void setSpecialty(const std::string &specialty) { mySpecialty = specialty; }

  /// Set the exprience.
  void setExperience(int exprience) { myExperience = exprience; }

  /// Set the max number of partients.
  void setMaxNumParients(int maxNumParients) {
    myMaxNumPatients = maxNumParients;
  }

  /// Set the serviece fees.
  void setServiceFees(double serveceFees) { myServiceFees = serveceFees; }

  // MARK: Other methods.

  /// Print class fields.
  void print() const {
    std::cout << myFirstName << ' ' << myMiddleName << ' ' << myLastName
              << ":\n"
              << "  Specialty:              " << mySpecialty << '\n'
              << "  Experience:             " << myExperience << '\n'
              << "  Max number of patients: " << myMaxNumPatients << '\n'
              << "  Service fees            " << myServiceFees << "\n\n";
  }

  /// Compare current and transmissions class by max number of patients.
  void compare(const Doctor &doctor) const {
    std::cout << myFirstName << ' ' << myMiddleName << ' ' << myLastName
              << ":\n"
              << "  Max number of patients: " << myMaxNumPatients << "\n\n"
              << doctor.myFirstName << ' ' << doctor.myMiddleName << ' '
              << doctor.myLastName << ":\n"
              << "  Max number of patients: " << doctor.myMaxNumPatients
              << "\n\n";
  }

  // TODO: Add another class field.
};

int main() {
  Doctor doctor{"First", "Second", "Middle", "???", 3, 5, 25.0};

  doctor.print();

  doctor.compare(Doctor{"First", "Second", "Middle", "???", 3, 5, 25.0});
  return 0;
}