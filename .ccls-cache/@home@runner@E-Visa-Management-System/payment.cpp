#include "payment.hpp"

// Payment(double amount, const string& paymentMethod);
Payment::Payment(double amount, const string &paymentMethod)
    : amount(amount), paymentMethod(paymentMethod){};

// double getAmount() const;
double Payment::getAmount() const { return amount; };

// string getPaymentMethod() const;
string Payment::getPaymentMethod() const { return paymentMethod; };