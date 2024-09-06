#include "visaOfficer.cpp"

class VisaOfficerManager
{
public:
    static VisaOfficerManager &getInstance()
    {
        static VisaOfficerManager instance;
        return instance;
    }

    void addVisaOfficer(VisaOfficer *officer)
    {
        visaOfficers.push_back(officer);
    }

    VisaOfficer *findVisaOfficerById(const std::string &officerId)
    {
        for (auto &officer : visaOfficers)
        {
            if (officer->getOfficerId() == officerId)
            {
                return officer;
            }
        }
        return nullptr;
    }

private:
    VisaOfficerManager() = default;                                     // Private constructor
    ~VisaOfficerManager() = default;                                    // Private destructor
    VisaOfficerManager(const VisaOfficerManager &) = delete;            // Delete copy constructor
    VisaOfficerManager &operator=(const VisaOfficerManager &) = delete; // Delete copy assignment

    std::vector<VisaOfficer *> visaOfficers;
};
