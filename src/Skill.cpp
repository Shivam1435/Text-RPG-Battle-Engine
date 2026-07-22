#include "Skill.h"
#include <iostream>

using namespace std;

// Default Constructor
Skill::Skill()
{
    skillName = "Unknown Skill";
    damage = 0;
    manaCost = 0;
    cooldown = 0;
    currentCooldown = 0;
}

// Parameterized Constructor
Skill::Skill(string skillName,
             int damage,
             int manaCost,
             int cooldown)
{
    this->skillName = skillName;
    this->damage = damage;
    this->manaCost = manaCost;
    this->cooldown = cooldown;
    currentCooldown = 0;
}

// Destructor
Skill::~Skill()
{
}

// Check if skill is ready
bool Skill::canUse() const
{
    return currentCooldown == 0;
}

// Use Skill
void Skill::useSkill()
{
    if (canUse())
    {
        currentCooldown = cooldown;
    }
}

// Reduce Cooldown
void Skill::reduceCooldown()
{
    if (currentCooldown > 0)
    {
        currentCooldown--;
    }
}

// Reset Cooldown
void Skill::resetCooldown()
{
    currentCooldown = 0;
}

// Display Skill
void Skill::displaySkill() const
{
    cout << "\n====== Skill ======" << endl;
    cout << "Name      : " << skillName << endl;
    cout << "Damage    : " << damage << endl;
    cout << "Mana Cost : " << manaCost << endl;
    cout << "Cooldown  : " << cooldown << endl;
    cout << "Current CD: " << currentCooldown << endl;
}

// Getters
string Skill::getSkillName() const
{
    return skillName;
}

int Skill::getDamage() const
{
    return damage;
}

int Skill::getManaCost() const
{
    return manaCost;
}

int Skill::getCooldown() const
{
    return cooldown;
}

int Skill::getCurrentCooldown() const
{
    return currentCooldown;
}

// Setters
void Skill::setSkillName(string skillName)
{
    this->skillName = skillName;
}

void Skill::setDamage(int damage)
{
    this->damage = damage;
}

void Skill::setManaCost(int manaCost)
{
    this->manaCost = manaCost;
}

void Skill::setCooldown(int cooldown)
{
    this->cooldown = cooldown;
}