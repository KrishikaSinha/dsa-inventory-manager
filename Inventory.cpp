#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Product {
    string sku;
    string name;
    int quantity;
};

vector<Product> inventory;

// Function to check if SKU exists
int findProductBySKU(const string &sku) {
    for (int i = 0; i < inventory.size(); i++) {
        if (inventory[i].sku == sku) return i;
    }
    return -1;
}

// Insert product
void insertProduct() {
    Product p;
    cout << "Enter SKU: ";
    cin >> p.sku;

    if (findProductBySKU(p.sku) != -1) {
        cout << "Product with this SKU already exists!\n";
        return;
    }

    cout << "Enter Product Name: ";
    cin.ignore();
    getline(cin, p.name);

    if (p.name.empty()) {
        cout << "Error: Product name cannot be empty.\n";
        return;
    }

    cout << "Enter Quantity: ";
    cin >> p.quantity;

    if (cin.fail() || p.quantity <= 0) {
        cout << "Error: Quantity must be a positive number.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    inventory.push_back(p);
    cout << "Product inserted successfully.\n";
}

// Display inventory
void displayInventory() {
    if (inventory.empty()) {
        cout << "Inventory is empty.\n";
        return;
    }

    cout << "\nCurrent Inventory:\n";
    cout << "SKU\t\tProduct Name\t\tQuantity\n";
    cout << "-----------------------------------------------\n";

    for (auto &item : inventory) {
        cout << item.sku << "\t\t" << item.name << "\t\t" << item.quantity << "\n";
    }
}

// Delete product
void deleteProduct() {
    string sku;
    cout << "Enter SKU to delete: ";
    cin >> sku;

    int index = findProductBySKU(sku);
    if (index == -1) {
        cout << "Product not found.\n";
    } else {
        cout << "Product " << inventory[index].name << " removed.\n";
        inventory.erase(inventory.begin() + index);
    }
}

// Search product by SKU
void searchBySKU() {
    string sku;
    cout << "Enter SKU to search: ";
    cin >> sku;

    int index = findProductBySKU(sku);
    if (index == -1) {
        cout << "Product not found.\n";
    } else {
        cout << "Product Found: " << inventory[index].sku
             << " | " << inventory[index].name
             << " | Qty: " << inventory[index].quantity << "\n";
    }
}

// Search product by Name
void searchByName() {
    string name;
    cout << "Enter Product Name to search: ";
    cin.ignore();
    getline(cin, name);

    bool found = false;
    for (auto &item : inventory) {
        if (item.name == name) {
            cout << "Product Found: " << item.sku
                 << " | " << item.name
                 << " | Qty: " << item.quantity << "\n";
            found = true;
        }
    }
    if (!found) cout << "No product found with name " << name << ".\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\nInventory Stock Manager\n";
        cout << "1. Insert New Product\n";
        cout << "2. Display Inventory\n";
        cout << "3. Search by SKU\n";
        cout << "4. Search by Name\n";
        cout << "5. Delete Product\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insertProduct(); break;
            case 2: displayInventory(); break;
            case 3: searchBySKU(); break;
            case 4: searchByName(); break;
            case 5: deleteProduct(); break;
            case 6: cout << "Exiting Inventory Manager.\n"; return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }
}