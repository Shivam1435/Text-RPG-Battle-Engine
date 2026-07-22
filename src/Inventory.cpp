#include "Inventory.h"
#include <iostream>

using namespace std;

// Constructor
Inventory::Inventory()
{
}

// Destructor
Inventory::~Inventory()
{
}

// Add Item
void Inventory::addItem(const Item& item)
{
    items.push_back(item);
    cout << item.getItemName() << " added to inventory." << endl;
}

// Remove Item
bool Inventory::removeItem(string itemName)
{
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        if (it->getItemName() == itemName)
        {
            items.erase(it);
            return true;
        }
    }

    return false;
}

// Use Item
bool Inventory::useItem(string itemName)
{
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        if (it->getItemName() == itemName)
        {
            cout << "Using " << it->getItemName() << endl;

            // Item effect can be applied here later

            items.erase(it);
            return true;
        }
    }

    return false;
}

// Check if Empty
bool Inventory::isEmpty() const
{
    return items.empty();
}

// Total Items
int Inventory::getItemCount() const
{
    return static_cast<int>(items.size());
}

// Display Inventory
void Inventory::displayInventory() const
{
    if (items.empty())
    {
        cout << "Inventory is Empty!" << endl;
        return;
    }

    cout << "\n========== INVENTORY ==========" << endl;

    for (size_t i = 0; i < items.size(); i++)
    {
        cout << "Item " << i + 1 << ":" << endl;
        items[i].displayItem();
    }

    cout << "===============================" << endl;
}
void Inventory::saveInventory(ofstream& outFile) const
{
    if (items.empty())
    {
        outFile << "Inventory is Empty!\n";
        return;
    }

    for (size_t i = 0; i < items.size(); i++)
    {
        outFile << "Item " << i + 1 << "\n";
        outFile << "Name         : " << items[i].getItemName() << "\n";
        outFile << "Description  : " << items[i].getDescription() << "\n";
        outFile << "Heal Amount  : " << items[i].getHealAmount() << "\n";
        outFile << "Mana Restore : " << items[i].getManaRestore() << "\n";
        outFile << "----------------------------------\n";
    }
}