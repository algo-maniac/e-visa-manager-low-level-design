#include "utils.hpp"
#include "visa.cpp"
#include "payment.cpp"
#include "document.cpp"

class Application
{
public:
    enum class Status
    {
        PENDING,
        APPROVED,
        REJECTED
    };

private:
    string applicant_name;
    Visa *visa;
    Status status;
    vector<Document *> documents;
    Payment *payment;

public:
    Application(string applicant_name, Visa *visa);

    string getApplicantName() const;
    Status getStatus() const;
    void setStatus(Status status);
    vector<Document *> getDocuments() const;
    void addDocument(Document *document);
    void makePayment(Payment *payment);
};