#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item
{
private:
    string itemName;
    string description;
    int healAmount;
    int manaRestore;

public:
    // Constructors
    Item();

    Item(string itemName,
         string description,
         int healAmount,
         int manaRestore);

    // Destructor
    ~Item();

    // Display
    void displayItem() const;

    // Getters
    string getItemName() const;
    string getDescription() const;
    int getHealAmount() const;
    int getManaRestore() const;

    // Setters
    void setItemName(string itemName);
    void setDescription(string description);
    void setHealAmount(int healAmount);
    void setManaRestore(int manaRestore);
};

#endif