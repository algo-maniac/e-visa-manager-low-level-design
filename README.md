# ***E-Visa Management Low Level Design***

![Sprint Planning](https://github.com/user-attachments/assets/1720c57a-cd76-479e-bc10-d38e6d38e6cd)



---

# Visa Processing Simulation

This project simulates a visa application processing system using multithreaded C++ code. The simulation involves applicants submitting visa applications, and visa officers reviewing, processing, and approving/rejecting them. The system supports multiple applicants and visa officers, where officers process applications concurrently using threads.

## Features

- **Multiple Applicants and Visa Officers**: Simulate real-world scenarios where multiple applicants submit visa applications.
- **Multithreaded Processing**: Visa officers process applications concurrently to simulate parallel work environments.
- **Document and Payment Handling**: Each application contains necessary documents and payment information.
- **Flexible Payment System**: Payment is handled through various payment methods like Credit Card, UPI, and Net Banking.
- **Singleton Managers**: Applicant and Visa Officer management is handled through singleton classes.
- **Dynamic Memory Allocation**: Objects are dynamically created and managed.

---

## Classes Overview

### 1. **Applicant**

Represents an individual applying for a visa. Each `Applicant` object contains basic details like name, passport number, and country of origin.

- **Attributes**:
  - `name`: Applicant's full name.
  - `passportNumber`: Applicant's passport number.
  - `country`: Applicant's country of origin.
  
- **Usage**: Applicants are created and added to the `ApplicantManager` for centralized management.

### 2. **Visa**

Represents a visa being applied for by an applicant. It contains details about the visa type, destination country, and validity period.

- **Attributes**:
  - `VisaType`: Enum representing the type of visa (TOURIST, BUSINESS, STUDENT).
  - `destinationCountry`: The country for which the visa is being applied.
  - `validity`: Number of months the visa will be valid.
  
- **Usage**: Each applicant’s visa application will reference a `Visa` object.

### 3. **Application**

Represents a visa application for an applicant. It includes the visa details, associated documents, payment, and the current status of the application (PENDING, APPROVED, REJECTED).

- **Attributes**:
  - `applicantName`: Name of the applicant.
  - `visa`: Pointer to the visa object associated with the application.
  - `documents`: List of documents submitted.
  - `payment`: Pointer to the payment object.
  - `status`: Status of the application (PENDING, APPROVED, REJECTED).

- **Methods**:
  - `addDocument`: Adds a document to the application.
  - `makePayment`: Associates payment details with the application.
  - `setStatus`: Sets the current status (APPROVED/REJECTED).
  
### 4. **VisaOfficer**

Represents a visa officer responsible for processing visa applications. Each `VisaOfficer` can process and either approve or reject an application.

- **Attributes**:
  - `officerId`: Unique ID of the visa officer.
  - `name`: Full name of the visa officer.
  
- **Methods**:
  - `processApplication`: Simulates the officer processing a given application.
  - `approveApplication`: Approves the application.
  - `rejectApplication`: Rejects the application.

### 5. **Document**

Represents a document that is part of a visa application. For example, a copy of the passport or an ID.

- **Attributes**:
  - `type`: Type of document (e.g., Passport, ID).
  - `path`: Path to the document file.

### 6. **Payment (Interface)**

`Payment` is an interface that represents payment for visa applications. Specific payment methods (Credit Card, UPI, Net Banking) are implemented as subclasses.

#### Subclasses:

1. **CreditCardPayment**:
   - Represents payment via credit card.
   - **Attributes**: Card number, cardholder name, expiration date, etc.
   
2. **UPIPayment**:
   - Represents payment via UPI.
   - **Attributes**: UPI ID, linked bank account.

3. **NetBankingPayment**:
   - Represents payment via net banking.
   - **Attributes**: Bank name, account number.

- **Methods** (Implemented by subclasses):
  - `processPayment`: Processes the payment based on the specific method.

### 7. **ApplicantManager (Singleton)**

Manages all applicants in the system. Implements the Singleton design pattern to ensure only one instance of the manager exists.

- **Methods**:
  - `addApplicant`: Adds an applicant to the system.
  - `getApplicant`: Retrieves an applicant by name.

### 8. **VisaOfficerManager (Singleton)**

Manages all visa officers in the system. Implements the Singleton design pattern.

- **Methods**:
  - `addVisaOfficer`: Adds a visa officer to the system.
  - `getVisaOfficer`: Retrieves a visa officer by ID.

---

## How Classes are Related

- **Applicant and Application**: Each `Applicant` submits one or more `Application` objects for different visa types.
- **Application and Visa**: Each `Application` references a `Visa` object which holds the type, destination, and validity of the visa being applied for.
- **Application and Document**: An `Application` can have multiple `Document` objects attached to it, such as passport copies or other identification documents.
- **Application and Payment**: The `Payment` class is an interface, and each `Application` is associated with a payment method like `CreditCardPayment`, `UPIPayment`, or `NetBankingPayment`.
- **VisaOfficer and Application**: A `VisaOfficer` processes, approves, or rejects an `Application`. Visa officers can handle multiple applications concurrently.
- **ApplicantManager and VisaOfficerManager**: Both are singleton managers that handle the creation and management of `Applicant` and `VisaOfficer` objects respectively, ensuring only one instance manages all applicants and officers.

---

## Multithreading

The system uses C++'s `std::thread` to simulate multithreaded visa processing. Each visa officer operates in a separate thread to process a group of applications concurrently. This simulates a parallel work environment where multiple officers process visa applications at the same time.

---

## Getting Started

### Prerequisites

- C++11 or higher
- A compiler that supports threading (e.g., GCC or Clang)
  
### Compilation and Execution

To compile the program:

```bash
g++ -std=c++11 -pthread -o visa_simulation main.cpp applicantManager.cpp visaOfficerManager.cpp visaOfficer.cpp application.cpp payment.cpp
```

To run the program:

```bash
./visa_simulation
```

### Notes

- Ensure you have all the necessary headers and source files (`applicantManager.hpp`, `visaOfficerManager.hpp`, `visaOfficer.hpp`, `payment.hpp`, etc.) before compiling.
- Modify file paths for documents and payment methods as necessary.

---

## Future Enhancements

- **Error Handling**: Add error handling for invalid payments, incomplete applications, or missing documents.
- **More Visa Types**: Extend the `VisaType` enum to include more visa types like work visas or medical visas.
- **User Interface**: Implement a simple CLI or GUI for more interactive simulation and better user experience.

---

## Replit Link

Check out the live version of this project on Replit: [E-Visa Management System](https://replit.com/@competitivecod3/E-Visa-Management-System#visaOfficerManager.hpp)

---

## License

This project is licensed under the MIT License.

--- 
