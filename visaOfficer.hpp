#include "utils.hpp"

class VisaOfficer
{

private:
    string officerId;
    string name;

public:
    VisaOfficer(const string &officerId, const string &name);

    string getOfficerId() const;
    void processApplication(Application *application);
    void approveApplication(Application *application);
    void rejectApplication(Application *application);
};