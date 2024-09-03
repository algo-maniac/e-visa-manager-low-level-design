#include "utils.hpp"


class Visa {

public:
enum class VisaType { TOURIST, BUSINESS, STUDENT, WORK };

private:
    VisaType type;
    string country;
    int validityMonths;

public:

    Visa(VisaType type, const string& country, int validityMonths);
    VisaType getVisaType() const;
    string getCountry() const;
    int getValidityMonths() const;
};