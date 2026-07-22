#ifndef SKILL_H
#define SKILL_H

#include <string>

using namespace std;

class Skill
{
private:
    string skillName;
    int damage;
    int manaCost;
    int cooldown;
    int currentCooldown;

public:
    // Constructors
    Skill();

    Skill(string skillName,
          int damage,
          int manaCost,
          int cooldown);

    // Destructor
    ~Skill();

    // Functions
    bool canUse() const;
    void useSkill();
    void reduceCooldown();
    void resetCooldown();

    void displaySkill() const;

    // Getters
    string getSkillName() const;
    int getDamage() const;
    int getManaCost() const;
    int getCooldown() const;
    int getCurrentCooldown() const;

    // Setters
    void setSkillName(string skillName);
    void setDamage(int damage);
    void setManaCost(int manaCost);
    void setCooldown(int cooldown);
};

#endif