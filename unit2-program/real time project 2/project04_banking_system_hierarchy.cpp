// ============================================================================
// File: project04_banking_system_hierarchy.cpp
// Unit II: Inheritance - Mini-Project
// Title: Banking System with Account Hierarchy
// Description: Implements a comprehensive banking system with an Account base class
//              and derived classes (SavingsAccount, CurrentAccount, FixedDepositAccount).
//              Demonstrates virtual functions, method overriding, interest calculation,
//              overdraft processing, and dynamic polymorphic container management.
// ============================================================================

#include <iostream>     // Include standard input/output stream library for console logging (std::cout)
#include <memory>       // Include memory library for dynamic smart pointer management (std::unique_ptr, std::make_unique)
#include <string>       // Include string header for std::string type representation
#include <string_view>  // Include string_view for efficient read-only string parameter passing
#include <vector>       // Include vector container library for dynamic collection of bank accounts

// Base Class 'Account' representing general bank account structure and behaviors
class Account {
protected:
    std::string accountNumber; // Unique account identifier string (accessible in derived classes)
    std::string holderName;    // Full name of the account holder (accessible in derived classes)
    double balance;            // Current account balance amount in rupees (accessible in derived classes)

public:
    // Parameterized Constructor: initializes base account attributes via member initializer list
    Account(std::string_view accNum, std::string_view name, double initialBalance)
        : accountNumber(accNum), holderName(name), balance(initialBalance) {} // Initialize members

    // Deposit operation function: adds funds to the balance if deposit amount is positive
    virtual void deposit(double amount) {
        if (amount > 0) { // Check if deposit amount is valid (greater than zero)
            balance += amount; // Add deposit amount to existing account balance
            std::cout << "Deposited Rs. " << amount << " into Account " << accountNumber << '\n'; // Output deposit confirmation
        }
    }

    // Withdraw operation function: deducts funds if balance is sufficient; returns success status
    virtual bool withdraw(double amount) {
        if (amount <= balance) { // Check if withdrawal amount does not exceed available balance
            balance -= amount;   // Deduct withdrawal amount from current account balance
            std::cout << "Withdrew Rs. " << amount << " from Account " << accountNumber << '\n'; // Output withdrawal confirmation
            return true;        // Return true indicating successful withdrawal transaction
        } else {
            std::cout << "Insufficient balance in Account " << accountNumber << '\n'; // Output error message
            return false;       // Return false indicating failed withdrawal transaction
        }
    }

    // Virtual Function: calculates interest accrued (returns 0.0 by default in base class)
    virtual double calculateInterest() const {
        return 0.0; // Base account does not generate interest by default
    }

    // Virtual Function: displays basic account identification and balance information
    virtual void displayInfo() const {
        std::cout << "Account: " << accountNumber            // Output account number
                  << " | Holder: " << holderName            // Output account holder name
                  << " | Balance: Rs. " << balance;         // Output balance without newline
    }

    // Virtual Destructor: guarantees safe polymorphic cleanup when derived objects are destroyed
    virtual ~Account() = default;
};

// Derived Class 'SavingsAccount': inherits publicly from base class 'Account'
class SavingsAccount : public Account {
private:
    double interestRate; // Annual interest rate percentage (e.g., 4.0%)

public:
    // Parameterized Constructor: forwards base details to Account constructor and sets interest rate
    SavingsAccount(std::string_view accNum, std::string_view name, double initialBalance, double rate)
        : Account(accNum, name, initialBalance), interestRate(rate) {} // Initialize base and rate

    // Override calculateInterest to compute annual interest earned based on current balance
    double calculateInterest() const override {
        return balance * (interestRate / 100.0); // Formula: balance * rate / 100
    }

    // Override displayInfo to print Savings Account prefix, base info, interest rate, and calculated interest
    void displayInfo() const override {
        std::cout << "Savings Account | ";                                // Print savings account type prefix
        Account::displayInfo();                                            // Call base class displayInfo method
        std::cout << " | Interest Rate: " << interestRate << "%"           // Output interest rate percentage
                  << " | Annual Interest: Rs. " << calculateInterest()    // Output calculated annual interest amount
                  << '\n';                                                 // Output newline separator
    }
};

// Derived Class 'CurrentAccount': inherits publicly from base class 'Account'
class CurrentAccount : public Account {
private:
    double overdraftLimit; // Maximum negative balance threshold allowed for business transactions

public:
    // Parameterized Constructor: forwards base details to Account constructor and sets overdraft limit
    CurrentAccount(std::string_view accNum, std::string_view name, double initialBalance, double limit)
        : Account(accNum, name, initialBalance), overdraftLimit(limit) {} // Initialize base and overdraft limit

    // Override withdraw function to allow withdrawals up to (balance + overdraftLimit)
    bool withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) { // Check if withdrawal is within overdraft limit
            balance -= amount;                    // Deduct amount from balance (may result in negative balance)
            std::cout << "Withdrew Rs. " << amount << " (Overdraft allowed) from Account " << accountNumber << '\n'; // Print status
            return true;                         // Return true indicating successful overdraft withdrawal
        } else {
            std::cout << "Withdrawal exceeds overdraft limit for Account " << accountNumber << '\n'; // Print error
            return false;                        // Return false indicating withdrawal denied
        }
    }

    // Override displayInfo to print Current Account prefix, base info, and overdraft limit
    void displayInfo() const override {
        std::cout << "Current Account | ";                                // Print current account type prefix
        Account::displayInfo();                                            // Call base class displayInfo method
        std::cout << " | Overdraft Limit: Rs. " << overdraftLimit << '\n'; // Output overdraft limit and newline
    }
};

// Derived Class 'FixedDepositAccount': inherits publicly from base class 'Account'
class FixedDepositAccount : public Account {
private:
    int tenureMonths;    // Lock-in period duration in months
    double interestRate; // Annual interest rate percentage

public:
    // Parameterized Constructor: initializes base attributes, deposit tenure in months, and interest rate
    FixedDepositAccount(std::string_view accNum, std::string_view name, double initialBalance, int months, double rate)
        : Account(accNum, name, initialBalance), tenureMonths(months), interestRate(rate) {} // Initializer list

    // Override calculateInterest to compute total maturity interest for the deposit tenure
    double calculateInterest() const override {
        return balance * (interestRate / 100.0) * (tenureMonths / 12.0); // Formula: balance * rate% * tenure_years
    }

    // Override displayInfo to print Fixed Deposit prefix, base info, tenure, rate, and maturity interest
    void displayInfo() const override {
        std::cout << "Fixed Deposit Account | ";                            // Print fixed deposit account type prefix
        Account::displayInfo();                                            // Call base class displayInfo method
        std::cout << " | Tenure: " << tenureMonths << " months"            // Output deposit tenure in months
                  << " | Interest Rate: " << interestRate << "%"           // Output annual interest rate percentage
                  << " | Maturity Interest: Rs. " << calculateInterest()   // Output total maturity interest amount
                  << '\n';                                                 // Output newline separator
    }
};

// Main execution function
int main() {
    // Declare dynamic vector storing std::unique_ptr pointers to Account base objects
    std::vector<std::unique_ptr<Account>> bankAccounts;

    // Create and add SavingsAccount object: SAV1001, Rahul Sharma, initial balance 25000.0, rate 4.0%
    bankAccounts.push_back(std::make_unique<SavingsAccount>("SAV1001", "Rahul Sharma", 25000.0, 4.0));

    // Create and add CurrentAccount object: CUR2001, TechCorp Pvt Ltd, balance 50000.0, overdraft limit 20000.0
    bankAccounts.push_back(std::make_unique<CurrentAccount>("CUR2001", "TechCorp Pvt Ltd", 50000.0, 20000.0));

    // Create and add FixedDepositAccount object: FD3001, Priya Verma, balance 100000.0, tenure 12 months, rate 7.5%
    bankAccounts.push_back(std::make_unique<FixedDepositAccount>("FD3001", "Priya Verma", 100000.0, 12, 7.5));

    // Print banner header for account hierarchy demonstration
    std::cout << "=== Banking System Account Hierarchy ===" << "\n\n";

    // Polymorphically display details of all initial bank accounts in vector
    for (const auto& acc : bankAccounts) {
        acc->displayInfo(); // Call virtual displayInfo method for each account object
    }

    // Print section banner header for transaction execution log
    std::cout << "\n=== Transactions ===" << '\n';

    // Perform deposit transaction of Rs. 5000 on SavingsAccount (index 0)
    bankAccounts[0]->deposit(5000.0);

    // Perform withdrawal transaction of Rs. 60000 on CurrentAccount (index 1 using overdraft)
    bankAccounts[1]->withdraw(60000.0);

    // Print section banner header for updated account details
    std::cout << "\n=== Updated Account Details ===" << '\n';

    // Polymorphically display updated details of all bank accounts in vector after transactions
    for (const auto& acc : bankAccounts) {
        acc->displayInfo(); // Call virtual displayInfo method to show modified account states
    }

    // Return status code 0 indicating successful completion of program
    return 0;
}
