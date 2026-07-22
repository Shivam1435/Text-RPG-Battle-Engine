#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>
#include <fstream>
#include "Item.h"

using namespace std;

class Inventory
{
private:
    vector<Item> items;

public:
    // Constructor
    Inventory();

    // Destructor
    ~Inventory();

    // Inventory Operations
    void addItem(const Item& item);

    bool removeItem(string itemName);

    bool useItem(string itemName);

    bool isEmpty() const;

    int getItemCount() const;

    // Display
    void displayInventory() const;

    void saveInventory(std::ofstream& outFile) const;
};

#endif