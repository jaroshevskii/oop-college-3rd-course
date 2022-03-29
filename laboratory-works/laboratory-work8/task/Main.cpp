#include <iostream>

class Doctor {
private:
  std::string firstName;
  std::string middleName;
  std::string lastName;

  std::string specialty;
  int experience;
  int maxNumPatients;

  // Service fees for one patient.
  double serviceFees;

public:
  Doctor();

  Doctor(const std::string &firstName, const std::string &middleName,
         const std::string &lastName, const std::string &specialty,
         int experience, int maxNumParients, double serviceFees);

  ~Doctor();

  std::string getFirstName();
  std::string getMiddleName();
  std::string getLastName();
  std::string getSpecialty();
  int getExperience();
  int getMaxNumParients();
  double getServiceFees();

  void setFirstName(const std::string &firstName);
  void setMiddleName(const std::string &middleName);
  void setLastName(const std::string &lastName);
  void setSpecialty(const std::string &specialty);
  void setExperience(int exprience);
  void setMaxNumParients(int maxNumParients);
  void setServiceFees(double serveceFees);

  void print();

  // TODO: Add compare class field.

  // TODO: Add another class field.
};

Doctor::Doctor() {
  firstName = "";
  middleName = "";
  lastName = "";

  specialty = "";
  experience = 0;
  maxNumPatients = 0;
  serviceFees = 0.0;
}

Doctor::Doctor(const std::string &firstName, const std::string &lastName,
               const std::string &middleName, const std::string &specialty,
               int experience, int maxNumPatients, double serviceFees) {
  Doctor::firstName = firstName;
  Doctor::middleName = middleName;
  Doctor::lastName = lastName;

  Doctor::specialty = specialty;
  Doctor::experience = experience;
  Doctor::maxNumPatients = maxNumPatients;
  Doctor::serviceFees = serviceFees;
}

Doctor::~Doctor() {}

std::string Doctor::getFirstName() { return firstName; }

std::string Doctor::getMiddleName() { return middleName; }

std::string Doctor::getLastName() { return lastName; }

std::string Doctor::getSpecialty() { return specialty; }

int Doctor::getExperience() { return experience; }

int Doctor::getMaxNumParients() { return maxNumPatients; }

double Doctor::getServiceFees() { return serviceFees; }

void Doctor::setFirstName(const std::string &firstName) {
  Doctor::firstName = firstName;
}

void Doctor::setMiddleName(const std::string &middleName) {
  Doctor::middleName = middleName;
}

void Doctor::setLastName(const std::string &lastName) {
  Doctor::lastName = lastName;
}

void Doctor::setSpecialty(const std::string &specialty) {
  Doctor::specialty = specialty;
}

void Doctor::setExperience(int exprience) { Doctor::experience = experience; }

void Doctor::setMaxNumParients(int maxNumParients) {
  Doctor::maxNumPatients = maxNumParients;
}

void Doctor::setServiceFees(double serveceFees) {
  Doctor::serviceFees = serveceFees;
}

void Doctor::print() {
  std::cout << firstName << ' ' << lastName << ' ' << middleName << ":\n"
            << "  " << "Specialty:              " << specialty << '\n'
            << "  " << "Experience:             " << experience << '\n'
            << "  " << "Max number of patients: " << maxNumPatients << '\n'
            << "  " << "Service fees            " << serviceFees << "\n\n";
}

int main() {
  Doctor doctor{"First", "Second", "Middle", "???", 3, 5, 25.0};
  
  doctor.print();
  return 0;
}
