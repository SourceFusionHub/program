#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int id;
    std::string name;
    int quantity;
    double price;
};

class InventoryManager {
private:
    std::vector<Item> inventory;

public:
  
    void addItem(int id, const std::string& name, int quantity, double price) {
        Item newItem = {id, name, quantity, price};
        inventory.push_back(newItem);
    }

    void displayInventory() const {
        std::cout << "Inventory:\n";
        std::cout << "ID\tName\tQuantity\tPrice\n";
        for (const auto& item : inventory) {
            std::cout << item.id << "\t" << item.name << "\t" << item.quantity << "\t\t" << item.price << "\n";
        }
    }

    void updateQuantity(int id, int newQuantity) {
        auto it = std::find_if(inventory.begin(), inventory.end(), [id](const Item& item) {
            return item.id == id;
        });

        if (it != inventory.end()) {
            it->quantity = newQuantity;
            std::cout << "Quantity updated successfully.\n";
        } else {
            std::cout << "Item not found in inventory.\n";
        }
    }

   
    double calculateInventoryValue() const {
        double totalValue = 0.0;
        for (const auto& item : inventory) {
            totalValue += item.quantity * item.price;
        }
        return totalValue;
    }
};

int main() {
    InventoryManager inventoryManager;

    inventoryManager.addItem(1, "Item1", 10, 5.99);
    inventoryManager.addItem(2, "Item2", 5, 10.99);
    inventoryManager.addItem(3, "Item3", 20, 2.49);

   
    inventoryManager.displayInventory();

 
    inventoryManager.updateQuantity(2, 8);

   
    inventoryManager.displayInventory();

    
    double totalValue = inventoryManager.calculateInventoryValue();
    std::cout << "Total inventory value: $" << totalValue << "\n";

    return 0;
}
