#ifndef GAMEPROGRESSION_H
#define GAMEPROGRESSION_H

#include "Player.h"
#include "Enemy.h"
#include "BattleEngine.h"
#include "SaveLoad.h"


class GameProgression
{
private:
    Player player;
    int currentLevel;
    int maxLevel;

public:
    // Constructor
    GameProgression();

    // Destructor
    ~GameProgression();

    // Game Functions
    void startGame();
    bool loadGame();

    void playLevel();

    Character* createEnemy();

    bool isGameCompleted() const;

    void levelUpPlayer();
    
    int getRequiredXP() const;

    void displayGameStatus() const;
};

#endif