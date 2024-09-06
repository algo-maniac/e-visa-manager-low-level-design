#include "application.hpp"

Application::Application(string applicant_name, Visa *visa)
    : applicant_name(applicant_name), visa(visa)
{
  // print applicant name and visa details
  cout << "Applicant Name: " << applicant_name << endl;
  cout << "Applicant Visa Details: " << endl;
  if (visa->getVisaType() == Visa::VisaType::TOURIST)
  {
    cout << "Visa Type: Tourist" << endl;
  }
  else if (visa->getVisaType() == Visa::VisaType::BUSINESS)
  {
    cout << "Visa Type: Business" << endl;
  }
  else if (visa->getVisaType() == Visa::VisaType::STUDENT)
  {
    cout << "Visa Type: Student" << endl;
  }
  else
  {
    cout << "Visa Type: Work" << endl;
  }
  cout << "Country: " << visa->getCountry() << endl;
  cout << "Validity Months: " << visa->getValidityMonths() << endl;
  cout << endl;
};

// Status getStatus() const;
Application::Status Application::getStatus() const { return status; };

// void setStatus(Status status);

void Application::setStatus(Status status) { this->status = status; };

// void addDocument(Document* document);
void Application::addDocument(Document *document)
{
  documents.push_back(document);
};

// void makePayment(Payment* payment);
void Application::makePayment(Payment *payment) { this->payment = payment; }

// vector<Document*> getDocuments() const;
vector<Document *> Application::getDocuments() const { return documents; }

string Application::getApplicantName() const { return applicant_name; }