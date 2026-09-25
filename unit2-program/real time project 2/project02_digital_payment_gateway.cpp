// ============================================================================
// File: project02_digital_payment_gateway.cpp
// Unit II: Inheritance - Real-Time Application 2
// Title: Digital Payment Gateway System
// Description: Implements a payment gateway processing engine utilizing polymorphism,
//              abstract classes, smart pointers (std::unique_ptr, std::make_unique),
//              and hierarchical inheritance for extensible payment modes.
// ============================================================================

#include <iostream>     // Include standard I/O stream library for printing transaction logs (std::cout)
#include <memory>       // Include memory library for smart pointer management (std::unique_ptr, std::make_unique)
#include <string>       // Include string library for object string attributes (std::string)
#include <string_view>  // Include string_view for efficient read-only string parameter passing
#include <vector>       // Include vector container library for dynamic collection of payment objects

// Abstract Base Class 'PaymentMethod' representing generic payment behavior
class PaymentMethod {
protected:
    std::string transactionId; // Unique transaction identifier string (accessible by derived payment modes)
    double amount;             // Transaction payment amount in rupees (accessible by derived payment modes)

public:
    // Parameterized Constructor: initializes common transaction fields using member initializer list
    PaymentMethod(std::string_view tid, double amt)
        : transactionId(tid), amount(amt) {} // Execute constructor body after member initialization

    // Pure Virtual Function: forces every specific payment mode to define its own processing logic
    virtual bool processPayment() const = 0;

    // Virtual Destructor: guarantees polymorphic deletion cleanup through base pointer references
    virtual ~PaymentMethod() = default;
};

// Derived Class 'CreditCardPayment': inherits publicly from base class 'PaymentMethod'
class CreditCardPayment : public PaymentMethod {
private:
    std::string maskedCardNumber; // Private masked credit card number string (e.g. XXXX-XXXX-1234)

public:
    // Parameterized Constructor: forwards transaction parameters to base class and stores masked card details
    CreditCardPayment(std::string_view tid, double amt, std::string_view card)
        : PaymentMethod(tid, amt), maskedCardNumber(card) {} // Initialize base and derived fields

    // Override pure virtual function to process and print credit card transaction details
    bool processPayment() const override {
        std::cout << "Credit-card transaction " << transactionId // Output transaction type and ID
                  << " for Rs. " << amount                      // Output transaction monetary amount
                  << " using " << maskedCardNumber               // Output masked card identifier
                  << " completed." << '\n';                      // Output completion message with newline
        return true;                                             // Return true indicating successful payment processing
    }
};

// Derived Class 'UPIPayment': inherits publicly from base class 'PaymentMethod'
class UPIPayment : public PaymentMethod {
private:
    std::string upiId; // Private Unified Payments Interface (UPI) virtual payment address string

public:
    // Parameterized Constructor: forwards transaction parameters to base class and stores UPI handle
    UPIPayment(std::string_view tid, double amt, std::string_view upi)
        : PaymentMethod(tid, amt), upiId(upi) {} // Initialize base and derived fields

    // Override pure virtual function to process and print UPI payment transaction details
    bool processPayment() const override {
        std::cout << "UPI transaction " << transactionId // Output transaction type and ID
                  << " for Rs. " << amount               // Output transaction monetary amount
                  << " from " << upiId                   // Output sender UPI address handle
                  << " completed." << '\n';               // Output completion message with newline
        return true;                                      // Return true indicating successful payment processing
    }
};

// Derived Class 'NetBankingPayment': inherits publicly from base class 'PaymentMethod'
class NetBankingPayment : public PaymentMethod {
private:
    std::string bankName; // Private financial institution name string for net banking transfer

public:
    // Parameterized Constructor: forwards transaction parameters to base class and stores bank name
    NetBankingPayment(std::string_view tid, double amt, std::string_view bank)
        : PaymentMethod(tid, amt), bankName(bank) {} // Initialize base and derived fields

    // Override pure virtual function to process and print net banking transaction details
    bool processPayment() const override {
        std::cout << "Net-banking transaction " << transactionId // Output transaction type and ID
                  << " for Rs. " << amount                       // Output transaction monetary amount
                  << " through " << bankName                     // Output facilitating bank institution name
                  << " completed." << '\n';                      // Output completion message with newline
        return true;                                              // Return true indicating successful payment processing
    }
};

// Main execution entry point
int main() {
    // Declare a vector container holding std::unique_ptr smart pointers to PaymentMethod base objects
    std::vector<std::unique_ptr<PaymentMethod>> payments;

    // Dynamically allocate and push CreditCardPayment transaction onto vector using std::make_unique
    payments.push_back(std::make_unique<CreditCardPayment>("TXN001", 2500, "XXXX-XXXX-1234"));

    // Dynamically allocate and push UPIPayment transaction onto vector using std::make_unique
    payments.push_back(std::make_unique<UPIPayment>("TXN002", 1200, "student@upi"));

    // Dynamically allocate and push NetBankingPayment transaction onto vector using std::make_unique
    payments.push_back(std::make_unique<NetBankingPayment>("TXN003", 5000, "Example Bank"));

    // Print section header banner for payment gateway execution
    std::cout << "=== Payment Gateway ===" << '\n';

    // Polymorphically iterate over each payment object pointer in vector using range-based for loop
    for (const auto& payment : payments) {
        // Call virtual processPayment method on each payment object through base pointer
        payment->processPayment();
    }

    // Return status code 0 indicating successful completion of program
    return 0;
}
