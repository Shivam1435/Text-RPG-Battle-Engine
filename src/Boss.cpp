#include "Boss.h"
#include <iostream>

using namespace std;

Boss::Boss(
    string name,
    int level,
    int hp,
    int mp,
    int attack,
    int defense,
    int speed,
    int expReward,
    int goldReward,
    int specialDamage
)
    : Enemy(name, level, hp, mp, attack, defense, speed, expReward, goldReward)
{
    specialAttackDamage = specialDamage;
}

int Boss::getSpecialAttackDamage() const
{
    return specialAttackDamage;
}

void Boss::specialAttack(Character& target)
{
    cout << "\n🔥 " << getName()
         << " uses SPECIAL ATTACK!\n";

    int damage = specialAttackDamage - target.getDefense();

    if (damage < 1)
        damage = 1;

    target.setCurrentHP(target.getCurrentHP() - damage);

    cout << target.getName()
         << " takes "
         << damage
         << " damage!\n";
}