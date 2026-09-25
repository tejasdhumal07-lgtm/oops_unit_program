// Concept 15: Payment Processing System
// Aim: To implement a real-world polymorphic payment system.

// Include stream I/O header for console operations
#include <iostream>
// Include string library header
#include <string>

// Abstract base class representing generic Payment interface
class Payment {
public:
    // Pure virtual pay function taking payment amount
    virtual void pay(double amount) const = 0;
    // Default virtual destructor for safe dynamic cleanup
    virtual ~Payment() = default;
};

// Derived concrete class for Card Payment method
class CardPayment : public Payment {
public:
    // Implementation of pay method for Card
    void pay(double amount) const override {
        // Output confirmation message for card payment
        std::cout << "Paid Rs. " << amount << " using card\n";
    }
};

// Derived concrete class for UPI Payment method
class UpiPayment : public Payment {
public:
    // Implementation of pay method for UPI
    void pay(double amount) const override {
        // Output confirmation message for UPI payment
        std::cout << "Paid Rs. " << amount << " using UPI\n";
    }
};

// Derived concrete class for Net Banking Payment method
class NetBankingPayment : public Payment {
public:
    // Implementation of pay method for Net Banking
    void pay(double amount) const override {
        // Output confirmation message for net banking payment
        std::cout << "Paid Rs. " << amount << " using net banking\n";
    }
};

// Standalone handler processing payment polymorphically via base reference
void processPayment(const Payment& payment, double amount) {
    // Dynamic dispatch triggers specific derived class pay() logic
    payment.pay(amount);
}

// Application main execution entry point
int main() {
    // Instantiate concrete CardPayment object
    CardPayment card;

    // Instantiate concrete UpiPayment object
    UpiPayment upi;

    // Instantiate concrete NetBankingPayment object
    NetBankingPayment netBanking;

    // Process card payment of 1250.0
    processPayment(card, 1250.0);

    // Process UPI payment of 750.0
    processPayment(upi, 750.0);

    // Process net banking payment of 500.0
    processPayment(netBanking, 500.0);

    // Return 0 for success
    return 0;
}
