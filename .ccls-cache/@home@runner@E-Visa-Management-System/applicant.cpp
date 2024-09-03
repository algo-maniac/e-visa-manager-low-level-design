#include "applicant.hpp"

Applicant::Applicant(const string &name, const string &passportNumber,
                     const string &nationality) {
  this->name = name;
  this->passportNumber = passportNumber;
  this->nationality = nationality;
};

string Applicant::getName() const { return name; };
string Applicant::getPassportNumber() const { return passportNumber; };
string Applicant::getNationality() const { return nationality; };
// Print applicant details

void Applicant::printApplicantDetails() const {
  cout << "Applicant Name: " << name << endl;
  cout << "Applicant Passport Number: " << passportNumber << endl;
  cout << "Applicant Nationality: " << nationality << endl;
}

void Applicant::submitApplication(Application *application) {
  applications.push_back(application);
}

void Applicant::receiveNotification(const Notification &notification) {

  cout << "Applicant " << name
       << " received notification: " << notification.getMessage() << endl;
}