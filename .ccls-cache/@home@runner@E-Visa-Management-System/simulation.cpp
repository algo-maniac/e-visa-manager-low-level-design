#include "applicant.cpp"
#include "utils.hpp"
#include "visaOfficer.cpp"

int main() {

  // Creating an applicant
  Applicant johnDoe("John Doe", "AB123456", "Canada");
  
  // Creating a visa
  Visa touristVisa(Visa::VisaType::TOURIST, "USA", 6);

  // Creating an application
  Application visaApplication("John Doe", &touristVisa);

  // Adding documents
  Document passportCopy("Passport", "/path/to/passport.pdf");
  visaApplication.addDocument(&passportCopy);

  // Making payment
  Payment visaPayment(160.0, "Credit Card");
  visaApplication.makePayment(&visaPayment);

  // Visa officer processing the application
  VisaOfficer officer("VO001", "Alice Smith");
  officer.processApplication(&visaApplication);

  // Approving the application
  officer.approveApplication(&visaApplication);

  // // Notification to the applicant
  // Notification approvalNotification("Your visa application has been
  // approved."); johnDoe.receiveNotification(approvalNotification);

  return 0;
}
