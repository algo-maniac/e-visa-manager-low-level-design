#include "applicant.cpp"

class ApplicantManager
{
public:
    static ApplicantManager &getInstance()
    {
        static ApplicantManager instance;
        return instance;
    }

    void addApplicant(Applicant *applicant)
    {
        applicants.push_back(applicant);
    }

    Applicant *findApplicantByPassport(const std::string &passportNumber)
    {
        for (auto &applicant : applicants)
        {
            if (applicant->getPassportNumber() == passportNumber)
            {
                return applicant;
            }
        }
        return nullptr;
    }

private:
    ApplicantManager() = default;                                   // Private constructor
    ~ApplicantManager() = default;                                  // Private destructor
    ApplicantManager(const ApplicantManager &) = delete;            // Delete copy constructor
    ApplicantManager &operator=(const ApplicantManager &) = delete; // Delete copy assignment

    std::vector<Applicant *> applicants;
};
