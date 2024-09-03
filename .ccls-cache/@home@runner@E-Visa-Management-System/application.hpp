#include "utils.hpp"
#include "visa.cpp"
#include "payment.cpp"
#include "document.cpp"


class Application {

enum class Status { PENDING, APPROVED, REJECTED };
private:
    string applicant_name;
    Visa* visa;
    Status status;
    vector<Document*> documents;
    Payment* payment;

public:
    Application(string applicant_name, Visa* visa);

    Status getStatus() const;
    void setStatus(Status status);
    void addDocument(Document* document);
    void makePayment(Payment* payment);


};