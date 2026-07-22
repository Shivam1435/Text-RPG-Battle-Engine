#ifndef BATTLEENGINE_H
#define BATTLEENGINE_H

#include "Player.h"
#include "Enemy.h"
#include "SaveLoad.h"

class BattleEngine
{
private:
    Player* player;
    Character* enemy;

    SaveLoad saveLoad;

    void displayBattleMenu();
    bool playerTurn();
    void enemyTurn();
    int getPlayerChoice();
    void useSkill();
    void useItem();

public:
    BattleEngine(Player* p, Character* e);
    void startBattle();
};

#endif