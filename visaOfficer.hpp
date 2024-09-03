#include "utils.hpp"

class VisaOfficer {

enum class Status { PENDING, APPROVED, REJECTED };
private:
    string officerId;
    string name;


public:
    VisaOfficer(const string& officerId, const string& name);

    void processApplication(Application* application);
    void approveApplication(Application* application);
    void rejectApplication(Application* application);

};