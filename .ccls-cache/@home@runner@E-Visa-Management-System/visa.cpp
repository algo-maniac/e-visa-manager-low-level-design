#include "visa.hpp"

// Visa(VisaType type, const string& country, int validityMonths);

Visa::Visa(VisaType type, const string &country, int validityMonths)
    : type(type), country(country), validityMonths(validityMonths) {}

// VisaType getVisaType() const;
// string getCountry() const;
// int getValidityMonths() const;

Visa::VisaType Visa::getVisaType() const { return type; }

string Visa::getCountry() const { return country; }

int Visa::getValidityMonths() const { return validityMonths; }
