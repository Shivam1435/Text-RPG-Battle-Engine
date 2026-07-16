#include "Enemy.h"
#include <iostream>

using namespace std;

// Default Constructor
Enemy::Enemy()
    : Character()
{
    xpReward = 50;
    goldReward = 20;
}

// Parameterized Constructor
Enemy::Enemy(string name,
             int level,
             int maxHP,
             int maxMP,
             int attackPower,
             int defense,
             int speed,
             int xpReward,
             int goldReward)
    : Character(name, level, maxHP, maxMP, attackPower, defense, speed)
{
    this->xpReward = xpReward;
    this->goldReward = goldReward;
}

// Destructor
Enemy::~Enemy()
{
}

// Attack Function
void Enemy::attack(Character& target)
{
    cout << name << " attacks " << target.getName() << "!" << endl;

    target.takeDamage(attackPower);
}

// Display Enemy Stats
void Enemy::displayStats() const
{
    Character::displayStats();

    cout << "XP Reward   : " << xpReward << endl;
    cout << "Gold Reward : " << goldReward << endl;
}

// Getters
int Enemy::getXPReward() const
{
    return xpReward;
}

int Enemy::getGoldReward() const
{
    return goldReward;
}

// Setters
void Enemy::setXPReward(int xpReward)
{
    this->xpReward = xpReward;
}

void Enemy::setGoldReward(int goldReward)
{
    this->goldReward = goldReward;
}