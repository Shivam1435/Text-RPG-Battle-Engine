#include "Item.h"
#include <iostream>

using namespace std;

// Default Constructor
Item::Item()
{
    itemName = "Unknown Item";
    description = "No Description";
    healAmount = 0;
    manaRestore = 0;
}

// Parameterized Constructor
Item::Item(string itemName,
           string description,
           int healAmount,
           int manaRestore)
{
    this->itemName = itemName;
    this->description = description;
    this->healAmount = healAmount;
    this->manaRestore = manaRestore;
}

// Destructor
Item::~Item()
{
}

// Display Item
void Item::displayItem() const
{
    cout << "\n========== ITEM ==========" << endl;
    cout << "Name         : " << itemName << endl;
    cout << "Description  : " << description << endl;
    cout << "Heal Amount  : " << healAmount << endl;
    cout << "Mana Restore : " << manaRestore << endl;
    cout << "==========================" << endl;
}

// Getters
string Item::getItemName() const
{
    return itemName;
}

string Item::getDescription() const
{
    return description;
}

int Item::getHealAmount() const
{
    return healAmount;
}

int Item::getManaRestore() const
{
    return manaRestore;
}

// Setters
void Item::setItemName(string itemName)
{
    this->itemName = itemName;
}

void Item::setDescription(string description)
{
    this->description = description;
}

void Item::setHealAmount(int healAmount)
{
    this->healAmount = healAmount;
}

void Item::setManaRestore(int manaRestore)
{
    this->manaRestore = manaRestore;
}