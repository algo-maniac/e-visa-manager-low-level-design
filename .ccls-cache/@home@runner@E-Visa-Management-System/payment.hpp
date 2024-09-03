#include "utils.hpp"


class Payment {
public:
    Payment(double amount, const string& paymentMethod);

    double getAmount() const;
    string getPaymentMethod() const;

private:
    double amount;
    string paymentMethod;
};
