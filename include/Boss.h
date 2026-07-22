#ifndef BOSS_H
#define BOSS_H

#include "Enemy.h"

class Boss : public Enemy
{
private:
    int specialAttackDamage;

public:
    Boss(
        std::string name,
        int level,
        int hp,
        int mp,
        int attack,
        int defense,
        int speed,
        int expReward,
        int goldReward,
        int specialDamage
    );

    int getSpecialAttackDamage() const;

    void specialAttack(Character& target);
};

#endif
