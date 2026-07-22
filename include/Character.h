#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

using namespace std;

class Character
{
protected:
    string name;
    int level;

    int maxHP;
    int currentHP;

    int maxMP;
    int currentMP;

    int attackPower;
    int defense;
    int speed;

public:
    // Constructors
    Character();

    Character(string name,
              int level,
              int maxHP,
              int maxMP,
              int attackPower,
              int defense,
              int speed);

    // Destructor
    virtual ~Character();

    // Combat
    virtual void attack(Character& target);

    bool isAlive() const;

    // Display
    virtual void displayStats() const;

    // Getters
    string getName() const;
    int getLevel() const;

    int getMaxHP() const;
    int getCurrentHP() const;

    int getMaxMP() const;
    int getCurrentMP() const;

    int getAttackPower() const;
    int getDefense() const;
    int getSpeed() const;

    // Setters
    void setName(string name);
    void setLevel(int level);

    void setMaxHP(int hp);
    void setCurrentHP(int hp);

    void setMaxMP(int mp);
    void setCurrentMP(int mp);

    void setAttackPower(int attack);
    void setDefense(int defense);
    void setSpeed(int speed);
};

#endif