#include "Skill.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Default Constructor
Skill::Skill()
    : name("Basic Skill"),
      description("A generic skill."),
      mpCost(10),
      power(15),
      cooldownMax(0),
      cooldownCurrent(0),
      critChance(0.1f),
      critMultiplier(1.5f),
      isHealing(false)
{
}

// Parameterized Constructor
Skill::Skill(string name,
             string description,
             int mpCost,
             int power,
             int cooldownMax,
             float critChance,
             float critMultiplier,
             bool isHealing)
    : name(name),
      description(description),
      mpCost(mpCost),
      power(power),
      cooldownMax(cooldownMax),
      cooldownCurrent(0),
      critChance(critChance),
      critMultiplier(critMultiplier),
      isHealing(isHealing)
{
}

// Destructor
Skill::~Skill()
{
}

// Checks whether the caster has enough MP and the skill isn't on cooldown
bool Skill::canUse(const Character& caster) const
{
    if (isOnCooldown())
    {
        return false;
    }
    if (caster.getMP() < mpCost)
    {
        return false;
    }
    return true;
}

// Applies the skill's effect (damage or heal), spends MP, and starts cooldown
void Skill::use(Character& caster, Character& target)
{
    if (!canUse(caster))
    {
        cout << caster.getName() << " cannot use " << name << " right now!" << endl;
        return;
    }

    // Spend MP
    caster.useMP(mpCost);

    // Roll for critical hit
    bool isCrit = (static_cast<float>(rand()) / RAND_MAX) < critChance;
    int finalPower = power;
    if (isCrit)
    {
        finalPower = static_cast<int>(power * critMultiplier);
    }

    if (isHealing)
    {
        cout << caster.getName() << " uses " << name << " on " << target.getName() << "!" << endl;
        if (isCrit)
        {
            cout << "Critical heal!" << endl;
        }
        target.heal(finalPower);
    }
    else
    {
        cout << caster.getName() << " casts " << name << " on " << target.getName() << "!" << endl;
        if (isCrit)
        {
            cout << "Critical hit!" << endl;
        }
        target.takeDamage(finalPower);
    }

    // Start cooldown
    cooldownCurrent = cooldownMax;
}

// Reduces cooldown by 1, call once per turn/round
void Skill::tickCooldown()
{
    if (cooldownCurrent > 0)
    {
        cooldownCurrent--;
    }
}

// Immediately clears the cooldown
void Skill::resetCooldown()
{
    cooldownCurrent = 0;
}

// Display Skill Info
void Skill::displayInfo() const
{
    cout << "Skill: " << name << endl;
    cout << "  Description : " << description << endl;
    cout << "  MP Cost     : " << mpCost << endl;
    cout << "  Power       : " << power << endl;
    cout << "  Cooldown    : " << cooldownCurrent << " / " << cooldownMax << endl;
    cout << "  Crit Chance : " << (critChance * 100) << "%" << endl;
    cout << "  Type        : " << (isHealing ? "Healing" : "Damage") << endl;
}

// Getters
string Skill::getName() const { return name; }
string Skill::getDescription() const { return description; }
int Skill::getMPCost() const { return mpCost; }
int Skill::getPower() const { return power; }
int Skill::getCooldownMax() const { return cooldownMax; }
int Skill::getCooldownCurrent() const { return cooldownCurrent; }
float Skill::getCritChance() const { return critChance; }
float Skill::getCritMultiplier() const { return critMultiplier; }
bool Skill::getIsHealing() const { return isHealing; }
bool Skill::isOnCooldown() const { return cooldownCurrent > 0; }

// Setters
void Skill::setName(string name) { this->name = name; }
void Skill::setDescription(string description) { this->description = description; }
void Skill::setMPCost(int mpCost) { this->mpCost = mpCost; }
void Skill::setPower(int power) { this->power = power; }
void Skill::setCooldownMax(int cooldownMax) { this->cooldownMax = cooldownMax; }
void Skill::setCritChance(float critChance) { this->critChance = critChance; }
void Skill::setCritMultiplier(float critMultiplier) { this->critMultiplier = critMultiplier; }
void Skill::setIsHealing(bool isHealing) { this->isHealing = isHealing; }
