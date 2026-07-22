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

    Enemy(std::string name,
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

    // Display
    void displayStats() const override;

    // Getters
    int getXPReward() const;
    int getGoldReward() const;

    // Setters
    void setXPReward(int xp);
    void setGoldReward(int gold);
};

#endif