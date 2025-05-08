
#include <iostream>
#include <vector>
using namespace std;

class Product {
private:
    int Product_id;
    string Name;
    int Quantity;
    double Price;

public:
    Product() {
        Product_id = 0;
        Name = "Unknown";
        Quantity = 0;
        Price = 0.0;
    }

    void Set_details(int id, string n, int q, double p) {
        Product_id = id;
        Name = n;
        Quantity = q;
        Price = p;
    }

    void Update_quantity(int newQuantity) {
        Quantity = newQuantity;
    }

    double Calculate_total_price() const {
        return Quantity * Price;
    }

    void Display() const {
        cout << "ID: " << Product_id << ", Name: " << Name << ", Quantity: " << Quantity << ", Price: " << Price << endl;
    }

    int Get_Product_id() const {
        return Product_id;
    }
};

class Inventory {
private:
    vector<Product> products;

public:
    void Add_inventory() {
        Product p;
        int id, Quantity;
        string Name;
        double Price;

        cout << "Enter Product ID, Name, Quantity, and Price: ";
        cin >> id >> Name >> Quantity >> Price;
        p.Set_details(id, Name, Quantity, Price);
        products.push_back(p);
    }

    void Update_Product_Quantity() {
        int id, newQuantity;
        cout << "Enter Product ID and new Quantity: ";
        cin >> id >> newQuantity;

        for (Product &product : products) {
            if (product.Get_Product_id() == id) {
                product.Update_quantity(newQuantity);
                cout << "Product Quantity updated successfully!" << endl;
                return;
            }
        }
        cout << "Product not found!" << endl;
    }

    void Calculate_total_inventory_value() {
        double totalValue = 0;
        for (const Product &product : products) {
            totalValue += product.Calculate_total_price();
        }
        cout << "Total Inventory Value: " << totalValue << endl;
    }

    void Display_inventory() {
        for (const Product &product : products) {
            product.Display();
        }
    }
};

int main() {
    Inventory storeInventory;
    int choice;

    do {
        cout << "\n1. Add Product\n2. Update Quantity\n3. Display Inventory\n4. Calculate Total Value\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                storeInventory.Add_inventory();
                break;
            case 2:
                storeInventory.Update_Product_Quantity();
                break;
            case 3:
                storeInventory.Display_inventory();
                break;
            case 4:
                storeInventory.Calculate_total_inventory_value();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
