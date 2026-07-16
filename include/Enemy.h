#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy : public Character
{
private:
    int xpReward;
    int goldReward;

public:
    // Constructors
    Enemy();

    Enemy(string name,
          int level,
          int maxHP,
          int maxMP,
          int attackPower,
          int defense,
          int speed,
          int xpReward,
          int goldReward);

    // Destructor
    ~Enemy();

    // Battle Function
    void attack(Character& target) override;

    // Display
    void displayStats() const override;

    // Getters
    int getXPReward() const;
    int getGoldReward() const;

    // Setters
    void setXPReward(int xpReward);
    void setGoldReward(int goldReward);
};

#endif