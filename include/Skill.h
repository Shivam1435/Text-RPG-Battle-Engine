#ifndef SKILL_H
#define SKILL_H

#include <string>
#include "Character.h"

using namespace std;

// Represents a single skill/ability a Character can learn and use.
// Handles MP cost, cooldown tracking, and critical hit chance.
class Skill
{
private:
    string name;
    string description;
    int mpCost;
    int power;            // base damage/heal amount before crit multiplier
    int cooldownMax;      // turns the skill is locked after use
    int cooldownCurrent;  // turns remaining before it can be used again
    float critChance;     // 0.0 - 1.0 chance to land a critical hit
    float critMultiplier; // damage multiplier on a crit (e.g. 1.5)
    bool isHealing;       // true if skill heals instead of damages

public:
    // Constructors
    Skill();
    Skill(string name,
          string description,
          int mpCost,
          int power,
          int cooldownMax,
          float critChance = 0.1f,
          float critMultiplier = 1.5f,
          bool isHealing = false);

    // Destructor
    ~Skill();

    // Core behavior
    bool canUse(const Character& caster) const;      // checks MP + cooldown
    void use(Character& caster, Character& target);  // applies effect, sets cooldown, spends MP
    void tickCooldown();                              // call once per turn/round
    void resetCooldown();

    // Display
    void displayInfo() const;

    // Getters
    string getName() const;
    string getDescription() const;
    int getMPCost() const;
    int getPower() const;
    int getCooldownMax() const;
    int getCooldownCurrent() const;
    float getCritChance() const;
    float getCritMultiplier() const;
    bool getIsHealing() const;
    bool isOnCooldown() const;

    // Setters
    void setName(string name);
    void setDescription(string description);
    void setMPCost(int mpCost);
    void setPower(int power);
    void setCooldownMax(int cooldownMax);
    void setCritChance(float critChance);
    void setCritMultiplier(float critMultiplier);
    void setIsHealing(bool isHealing);
};

#endif
