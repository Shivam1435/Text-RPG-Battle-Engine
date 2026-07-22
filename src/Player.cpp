#include "Player.h"
#include <iostream>

using namespace std;

// Default Constructor
Player::Player() : Character()
{
    experience = 0;
    gold = 0;

    inventory.addItem(
        Item("Health Potion",
             "Restores 50 HP",
             50,
             0));

    inventory.addItem(
        Item("Health Potion",
             "Restores 50 HP",
             50,
             0));

    inventory.addItem(
        Item("Mana Potion",
             "Restores 30 MP",
             0,
             30));
}

// Parameterized Constructor
Player::Player(string name,
               int level,
               int maxHP,
               int maxMP,
               int attackPower,
               int defense,
               int speed,
               int experience,
               int gold)
    : Character(name,
                level,
                maxHP,
                maxMP,
                attackPower,
                defense,
                speed)
{
    this->experience = experience;
    this->gold = gold;
    inventory.addItem(
    Item("Health Potion",
         "Restores 50 HP",
         50,
         0));

inventory.addItem(
    Item("Health Potion",
         "Restores 50 HP",
         50,
         0));

inventory.addItem(
    Item("Mana Potion",
         "Restores 30 MP",
         0,
         30));
}

// Destructor
Player::~Player()
{
}

// Gain Experience
void Player::gainExperience(int xp)
{
    experience += xp;
    cout << name << " gained " << xp << " XP!" << endl;
}

// Earn Gold
void Player::earnGold(int amount)
{
    gold += amount;
    cout << name << " earned " << amount << " gold!" << endl;
}

// Display Player Stats
void Player::displayStats() const
{
    cout << "\n========== PLAYER ==========" << endl;
    cout << "Name       : " << name << endl;
    cout << "Level      : " << level << endl;
    cout << "HP         : " << currentHP << "/" << maxHP << endl;
    cout << "MP         : " << currentMP << "/" << maxMP << endl;
    cout << "Attack     : " << attackPower << endl;
    cout << "Defense    : " << defense << endl;
    cout << "Speed      : " << speed << endl;
    cout << "Experience : " << experience << endl;
    cout << "Gold       : " << gold << endl;
    cout << "============================" << endl;
}

// Getters
int Player::getExperience() const
{
    return experience;
}

int Player::getGold() const
{
    return gold;
}

// Setters
void Player::setExperience(int xp)
{
    experience = xp;
}

void Player::setGold(int gold)
{
    this->gold = gold;
}

Inventory& Player::getInventory()
{
    return inventory;
}
const Inventory& Player::getInventory() const
{
    return inventory;
}