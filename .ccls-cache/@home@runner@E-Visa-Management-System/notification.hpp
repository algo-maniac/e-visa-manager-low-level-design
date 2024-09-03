#include "utils.hpp"

class Notification {
public:
    Notification(const string& message);

    string getMessage() const;

private:
    string message;
};