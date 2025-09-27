#include <iostream>
#include <vector>
using namespace std;

struct Item {
    int sku;
    int quantity;
};

// Function to process sale
void processSale(vector<Item>& inventory, int sku, int qtySold) {
    bool skuFound = false;

    for (auto &item : inventory) {
        if (item.sku == sku) {
            skuFound = true;
            if (item.quantity >= qtySold) {
                item.quantity -= qtySold;
                cout << "Sale processed: " << qtySold << " units of SKU " << sku << ".\n";
            } else {
                cout << "Insufficient stock for SKU " << sku
                     << ". Available: " << item.quantity << "\n";
            }
            return;
        }
    }

    if (!skuFound) {
        cout << "SKU " << sku << " not found in inventory.\n";
    }
}

// Function to identify zero stock SKUs
vector<int> identifyZeroStock(const vector<Item>& inventory) {
    vector<int> zeroStockList;

    for (auto &item : inventory) {
        if (item.quantity == 0) {
            zeroStockList.push_back(item.sku);
        }
    }

    if (!zeroStockList.empty()) {
        cout << "Zero stock SKUs: ";
        for (int sku : zeroStockList) {
            cout << sku << " ";
        }
        cout << "\n";
    } else {
        cout << "No zero stock items found.\n";
    }

    return zeroStockList;
}

int main() {
    vector<Item> inventory = {{101, 50}, {102, 20}, {103, 0}};

    // Process Sales
    processSale(inventory, 101, 30);   // Normal sale
    processSale(inventory, 102, 25);   // Insufficient stock
    processSale(inventory, 104, 10);   // SKU not found

    // Identify Zero Stock
    vector<int> zeroStock = identifyZeroStock(inventory);

    // Show updated inventory
    cout << "\nUpdated Inventory:\n";
    for (auto &item : inventory) {
        cout << "SKU: " << item.sku << " | Qty: " << item.quantity << "\n";
    }

    return 0;
}
