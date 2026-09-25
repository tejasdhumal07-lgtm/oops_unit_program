// Include standard stream library for console input and output
#include <iostream>
// Include string library for handling product names
#include <string>

// Define Product class representing items in an e-commerce catalog
class Product {
// Private section encapsulating data members and static counters
private:
    // Unique integer identifier for product
    int productId;
    // Name description string of the product
    std::string productName;
    // Price of the product in local currency (Rupees)
    double price;
    // Quantity of units available in inventory stock
    int stockQuantity;
    // Static data member tracking total active Product instances across system
    static int totalProducts;

// Public section exposing interface methods, constructors, and destructors
public:
    // Parameterized constructor initializing product properties and incrementing static count
    Product(int id, const std::string& name, double p, int stock)
        // Initialize productId, productName, price, and stockQuantity via initializer list
        : productId(id), productName(name), price(p), stockQuantity(stock) {
        // Increment static totalProducts counter when a new Product is created
        totalProducts++;
    }

    // Inline accessor function returning product ID
    inline int getId() const { return productId; }
    // Inline accessor function returning product name
    inline std::string getName() const { return productName; }
    // Inline accessor function returning product price
    inline double getPrice() const { return price; }

    // Member function to update current stock quantity of product
    void updateStock(int quantity) {
        // Assign new quantity value to private stockQuantity member
        stockQuantity = quantity;
    }

    // Static member function to retrieve the total number of active product objects
    static int getTotalProducts() {
        // Return current static totalProducts counter value
        return totalProducts;
    }

    // Const member function displaying product information to standard output
    void display() const {
        // Format and output product ID, name, price, and available stock
        std::cout << "ID: " << productId
                  << " | Product: " << productName
                  << " | Price: Rs. " << price
                  << " | Stock: " << stockQuantity << std::endl;
    }

    // Destructor called automatically upon object destruction to decrement total count
    ~Product() {
        // Decrement static totalProducts counter when a Product instance is destroyed
        totalProducts--;
    }
};

// Define and initialize static member variable outside class scope to 0
int Product::totalProducts = 0;

// Application main entry point
int main() {
    // Instantiate first Product object p1 for Laptop
    Product p1(1001, "Laptop", 55000, 15);
    // Instantiate second Product object p2 for Mouse
    Product p2(1002, "Mouse", 450, 50);
    // Instantiate third Product object p3 for Keyboard
    Product p3(1003, "Keyboard", 1200, 30);

    // Print catalog section title header
    std::cout << "=== Product Catalog ===" << std::endl;

    // Display product details for p1
    p1.display();
    // Display product details for p2
    p2.display();
    // Display product details for p3
    p3.display();

    // Output total count of products in catalog using static member function
    std::cout << "\nTotal Products in Catalog: "
              << Product::getTotalProducts() << std::endl;

    // Return 0 indicating successful program execution
    return 0;
}
