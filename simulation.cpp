#include "applicantManager.hpp"
#include "utils.hpp"
#include "visaOfficerManager.hpp"
#include <iostream>
#include <thread>
#include <vector>

void processApplications(VisaOfficer *officer,
                         std::vector<Application *> applications)
{
  for (Application *app : applications)
  {
    officer->processApplication(app);
  }
}

int main()
{
  // Accessing singleton managers
  ApplicantManager &applicantManager = ApplicantManager::getInstance();
  VisaOfficerManager &visaOfficerManager = VisaOfficerManager::getInstance();

  // Creating visas
  Visa *touristVisa = new Visa(Visa::VisaType::TOURIST, "USA", 6);
  Visa *businessVisa = new Visa(Visa::VisaType::BUSINESS, "Germany", 12);
  Visa *studentVisa = new Visa(Visa::VisaType::STUDENT, "Australia", 24);
  Visa *businessVisa2 = new Visa(Visa::VisaType::BUSINESS, "Japan", 24);
  Visa *touristVisa2 = new Visa(Visa::VisaType::TOURIST, "Italy", 3);

  // Creating applicants
  Applicant *johnDoe = new Applicant("John Doe", "AB123456", "Canada");
  Applicant *janeSmith = new Applicant("Jane Smith", "XY789012", "UK");
  Applicant *aliceBrown = new Applicant("Alice Brown", "CD345678", "Australia");
  Applicant *bobWhite = new Applicant("Bob White", "EF901234", "India");
  Applicant *eveBlack = new Applicant("Eve Black", "GH567890", "France");

  // Adding applicants to the manager
  applicantManager.addApplicant(johnDoe);
  applicantManager.addApplicant(janeSmith);
  applicantManager.addApplicant(aliceBrown);
  applicantManager.addApplicant(bobWhite);
  applicantManager.addApplicant(eveBlack);

  // Creating visa officers (less than applicants)
  VisaOfficer *officer1 = new VisaOfficer("VO001", "Alice Smith");
  VisaOfficer *officer2 = new VisaOfficer("VO002", "Bob Johnson");

  // Adding visa officers to the manager
  visaOfficerManager.addVisaOfficer(officer1);
  visaOfficerManager.addVisaOfficer(officer2);

  // Creating applications
  Application *application1 = new Application("John Doe", touristVisa);
  Application *application2 = new Application("Jane Smith", businessVisa);
  Application *application3 = new Application("Alice Brown", studentVisa);
  Application *application4 = new Application("Bob White", businessVisa2);
  Application *application5 = new Application("Eve Black", touristVisa2);

  // Adding documents to applications
  Document *passportCopy1 = new Document("PASSPORT", "/path/to/passport1.pdf");
  Document *passportCopy2 =
      new Document("AADHAR CARD", "/path/to/passport2.pdf");
  Document *passportCopy3 = new Document("PASSPORT", "/path/to/passport3.pdf");
  Document *passportCopy4 = new Document("PASSPORT", "/path/to/passport4.pdf");
  Document *passportCopy5 = new Document("PASSPORT", "/path/to/passport5.pdf");

  application1->addDocument(passportCopy1);
  application2->addDocument(passportCopy2);
  application3->addDocument(passportCopy3);
  application4->addDocument(passportCopy4);
  application5->addDocument(passportCopy5);

  // Making payments for applications
  Payment *payment1 = new Payment(160.0, "Credit Card");
  Payment *payment2 = new Payment(200.0, "PayPal");
  Payment *payment3 = new Payment(250.0, "Debit Card");
  Payment *payment4 = new Payment(180.0, "Net Banking");
  Payment *payment5 = new Payment(220.0, "Credit Card");

  application1->makePayment(payment1);
  application2->makePayment(payment2);
  application3->makePayment(payment3);
  application4->makePayment(payment4);
  application5->makePayment(payment5);

  // Distribute applications between visa officers
  std::vector<Application *> officer1Applications = {application1,
                                                     application2};
  std::vector<Application *> officer2Applications = {application3, application4,
                                                     application5};

  // Create threads for visa officers processing applications
  std::thread officer1Thread(processApplications, officer1,
                             officer1Applications);
  std::thread officer2Thread(processApplications, officer2,
                             officer2Applications);

  // Wait for all threads to complete
  officer1Thread.join();
  officer2Thread.join();

  // Cleaning up dynamically allocated memory
  delete johnDoe;
  delete janeSmith;
  delete aliceBrown;
  delete bobWhite;
  delete eveBlack;

  delete officer1;
  delete officer2;

  delete touristVisa;
  delete businessVisa;
  delete studentVisa;
  delete businessVisa2;
  delete touristVisa2;

  delete application1;
  delete application2;
  delete application3;
  delete application4;
  delete application5;

  delete passportCopy1;
  delete passportCopy2;
  delete passportCopy3;
  delete passportCopy4;
  delete passportCopy5;

  delete payment1;
  delete payment2;
  delete payment3;
  delete payment4;
  delete payment5;

  return 0;
}
