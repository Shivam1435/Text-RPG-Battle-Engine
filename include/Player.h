#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Inventory.h"

class Player : public Character
{
private:
    int experience;
    int gold;

    Inventory inventory;

public:
    // Constructors
    Player();

    Player(std::string name,
           int level,
           int maxHP,
           int maxMP,
           int attackPower,
           int defense,
           int speed,
           int experience,
           int gold);


    // Destructor
    ~Player();

    // Player Functions
    void gainExperience(int xp);
    void earnGold(int amount);


    // Display
    void displayStats() const override;

    // Getters
    int getExperience() const;
    int getGold() const;
    Inventory& getInventory();
const Inventory& getInventory() const;

    // Setters
    void setExperience(int xp);
    void setGold(int gold);
   
};

#endif