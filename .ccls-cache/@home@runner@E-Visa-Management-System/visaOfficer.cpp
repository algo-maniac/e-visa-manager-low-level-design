#include "visaOfficer.hpp"

// VisaOfficer(const string& officerId, const string& name);

VisaOfficer::VisaOfficer(const string &officerId, const string &name)
    : officerId(officerId), name(name){};

// void processApplication(Application* application);

void VisaOfficer::processApplication(Application *application) {

  cout << typeid(application->getStatus()).name() << endl;
  // if (application->getStatus() == Status::PENDING) {
  //   application->setStatus(Status::APPROVED);
  //   cout << "Application approved" << endl;
  // } else {
  //   cout << "Application already approved" << endl;
  // }
}
// void approveApplication(Application* application);

void VisaOfficer::approveApplication(Application *application) {
  // if (application->getStatus() == Status::PENDING) {
  //   application->setStatus(Status::APPROVED);
  // } else {
  //   cout << "Application already approved" << endl;
  // }
}
// void rejectApplication(Application* application);

void VisaOfficer::rejectApplication(Application *application) {
  // if (application->getStatus() == Status::PENDING) {
  //   application->setStatus(Status::REJECTED);
  // } else {
  //   cout << "Application already rejected" << endl;
  // }
}