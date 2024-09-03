#include "application.hpp"

Application::Application(string applicant_name, Visa *visa)
    : applicant_name(applicant_name), visa(visa){};

// Status getStatus() const;
Application::Status Application::getStatus() const { return status; };

// void setStatus(Status status);

void Application::setStatus(Status status) { this->status = status; };

// void addDocument(Document* document);
void Application::addDocument(Document *document) {
  documents.push_back(document);
};

// void makePayment(Payment* payment);
void Application::makePayment(Payment *payment) { this->payment = payment; }