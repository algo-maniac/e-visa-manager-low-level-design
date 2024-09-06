#include "visaOfficer.hpp"

// VisaOfficer(const string& officerId, const string& name);

VisaOfficer::VisaOfficer(const string &officerId, const string &name)
    : officerId(officerId), name(name) {};

// void processApplication(Application* application);

// get officer id
string VisaOfficer::getOfficerId() const { return officerId; }

void VisaOfficer::processApplication(Application *application)
{

  // cout << typeid(application->getStatus()).name() << endl;
  if (application->getStatus() == Application::Status::PENDING)
  {

    cout << "Processing application for " << application->getApplicantName()
         << "....." << endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    vector<Document *> documents = application->getDocuments();
    bool f = 0;
    for (auto it : documents)
    {
      if (it->getDocumentType() == "PASSPORT")
      {
        f = 1;
        break;
      }
    }

    if (f)
    {
      this->approveApplication(application);
    }
    else
    {
      this->rejectApplication(application);
    }
  }
  else
  {
    cout << "Application already approved" << endl;
  }
}
// void approveApplication(Application* application);

void VisaOfficer::approveApplication(Application *application)
{
  application->setStatus(Application::Status::APPROVED);
  cout << "Application approved for " << application->getApplicantName()
       << endl;
}
// void rejectApplication(Application* application);

void VisaOfficer::rejectApplication(Application *application)
{
  application->setStatus(Application::Status::REJECTED);
  cout << "Application rejected for " << application->getApplicantName()
       << endl;
}