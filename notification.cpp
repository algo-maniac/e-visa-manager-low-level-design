#include "notification.hpp"

Notification::Notification(const string& message) : message(message) {}

string Notification::getMessage() const { return message; }

