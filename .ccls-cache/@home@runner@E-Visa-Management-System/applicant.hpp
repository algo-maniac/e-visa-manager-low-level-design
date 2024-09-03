
#include "application.cpp"
#include "notification.cpp"


class Applicant {

private:
    string name;
    string passportNumber;
    string nationality;
    vector<Application*> applications;


public:
    Applicant(const string &name, const string &passportNumber, const string &nationality);

    string getName() const;
    string getPassportNumber() const;
    string getNationality() const;
    void printApplicantDetails() const;
    
    void submitApplication(Application* application);
    void receiveNotification(const Notification& notification);


};