#include "Enemy.h"
#include <iostream>

using namespace std;

// Default Constructor
Enemy::Enemy() : Character()
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
    : Character(name,
                level,
                maxHP,
                maxMP,
                attackPower,
                defense,
                speed)
{
    this->xpReward = xpReward;
    this->goldReward = goldReward;
}

// Destructor
Enemy::~Enemy()
{
}

// Display Enemy Stats
void Enemy::displayStats() const
{
    cout << "\n========== ENEMY ==========" << endl;
    cout << "Name       : " << name << endl;
    cout << "Level      : " << level << endl;
    cout << "HP         : " << currentHP << "/" << maxHP << endl;
    cout << "MP         : " << currentMP << "/" << maxMP << endl;
    cout << "Attack     : " << attackPower << endl;
    cout << "Defense    : " << defense << endl;
    cout << "Speed      : " << speed << endl;
    cout << "XP Reward  : " << xpReward << endl;
    cout << "Gold Reward: " << goldReward << endl;
    cout << "===========================" << endl;
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
void Enemy::setXPReward(int xp)
{
    xpReward = xp;
}

void Enemy::setGoldReward(int gold)
{
    goldReward = gold;
}