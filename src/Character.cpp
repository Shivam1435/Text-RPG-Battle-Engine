#include "Character.h"
#include <iostream>

using namespace std;

// Default Constructor
Character::Character()
{
    name = "Unknown";
    level = 1;

    maxHP = 100;
    currentHP = 100;

    maxMP = 50;
    currentMP = 50;

    attackPower = 10;
    defense = 5;
    speed = 5;
}

// Parameterized Constructor
Character::Character(string name,
                     int level,
                     int maxHP,
                     int maxMP,
                     int attackPower,
                     int defense,
                     int speed)
{
    this->name = name;
    this->level = level;

    this->maxHP = maxHP;
    this->currentHP = maxHP;

    this->maxMP = maxMP;
    this->currentMP = maxMP;

    this->attackPower = attackPower;
    this->defense = defense;
    this->speed = speed;
}

// Destructor
Character::~Character()
{
}

// Attack Function
void Character::attack(Character& target)
{
    int damage = attackPower - target.defense;

    if (damage < 1)
        damage = 1;

    target.currentHP -= damage;

    if (target.currentHP < 0)
        target.currentHP = 0;

    cout << name << " attacks "
         << target.name
         << " for "
         << damage
         << " damage!" << endl;
}

// Check Alive
bool Character::isAlive() const
{
    return currentHP > 0;
}

// Display Stats
void Character::displayStats() const
{
    cout << "\n===== Character Stats =====" << endl;
    cout << "Name : " << name << endl;
    cout << "Level : " << level << endl;
    cout << "HP : " << currentHP << "/" << maxHP << endl;
    cout << "MP : " << currentMP << "/" << maxMP << endl;
    cout << "Attack : " << attackPower << endl;
    cout << "Defense : " << defense << endl;
    cout << "Speed : " << speed << endl;
}

// Getters
string Character::getName() const
{
    return name;
}

int Character::getLevel() const
{
    return level;
}

int Character::getMaxHP() const
{
    return maxHP;
}

int Character::getCurrentHP() const
{
    return currentHP;
}

int Character::getMaxMP() const
{
    return maxMP;
}

int Character::getCurrentMP() const
{
    return currentMP;
}

int Character::getAttackPower() const
{
    return attackPower;
}

int Character::getDefense() const
{
    return defense;
}

int Character::getSpeed() const
{
    return speed;
}

// Setters
void Character::setName(string name)
{
    this->name = name;
}

void Character::setLevel(int level)
{
    this->level = level;
}

void Character::setMaxHP(int hp)
{
    maxHP = hp;
}

void Character::setCurrentHP(int hp)
{
    currentHP = hp;
}

void Character::setMaxMP(int mp)
{
    maxMP = mp;
}

void Character::setCurrentMP(int mp)
{
    currentMP = mp;
}

void Character::setAttackPower(int attack)
{
    attackPower = attack;
}

void Character::setDefense(int defense)
{
    this->defense = defense;
}

void Character::setSpeed(int speed)
{
    this->speed = speed;
}