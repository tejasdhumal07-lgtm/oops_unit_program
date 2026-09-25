// Header for input/output operations
#include <iostream>

// Class Account holding private financial data
class Account {
private:
    // Private variable balance
    double balance;
    // Declare Auditor as a friend class to grant access to private members
    friend class Auditor;

public:
    // Explicit constructor initializing initial balance
    explicit Account(double initialBalance) : balance(initialBalance) {}
};

// Class Auditor inspecting Account details
class Auditor {
public:
    // Function taking constant reference to Account and accessing its private member balance
    void inspect(const Account& account) const {
        // Output private account balance accessed via friend privilege
        std::cout << "Account Balance: " << account.balance << '\n';
    }
};

// Program entry point
int main() {
    // Instantiate Account object with initial balance of 5000.0
    Account account(5000.0);
    // Instantiate Auditor object
    Auditor auditor;
    // Perform inspection on account
    auditor.inspect(account);
    // Return 0 for successful completion
    return 0;
}
