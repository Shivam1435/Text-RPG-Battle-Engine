#include "GameProgression.h"
#include "SaveLoad.h"
#include "Boss.h"
#include <iostream>

using namespace std;

// Constructor
GameProgression::GameProgression()
{
    player = Player("Hero", 1, 100, 50, 15, 5, 5, 0, 0);

    currentLevel = 1;
    maxLevel = 5;
}

// Destructor
GameProgression::~GameProgression()
{
}

// Start Game
void GameProgression::startGame()
{
    cout << "\n===== GAME START =====\n";

    while (!isGameCompleted() && player.isAlive())
    {
        playLevel();
    }

    if (player.isAlive())
    {
        cout << "\nCongratulations! You completed the game.\n";
    }
    else
    {
        cout << "\nGame Over!\n";
    }
}

// Load Game
bool GameProgression::loadGame()
{
    SaveLoad saveLoad;

    if (!saveLoad.loadGame(player, "savegame.dat"))
    {
        cout << "\nNo saved game found!\n";
        return false;
    }

    cout << "\n=====================================\n";
    cout << "      GAME LOADED SUCCESSFULLY\n";
    cout << "=====================================\n";

    player.displayStats();

    startGame();

    return true;
}

// Play One Level
void GameProgression::playLevel()
{
    displayGameStatus();

    Character* enemy = createEnemy();

    BattleEngine battle(&player, enemy);

    battle.startBattle();

    delete enemy;

    if (player.isAlive())
{
    if (player.getExperience() >= getRequiredXP())
    {
        cout << "\n=====================================\n";
        cout << "       LEVEL UP AVAILABLE!\n";
        cout << "=====================================\n";

        levelUpPlayer();
    }

    currentLevel++;
}
}
// Create Enemy / Boss
Character* GameProgression::createEnemy()
{
    if (currentLevel % 5 == 0)
    {
        cout << "\n=====================================\n";
        cout << "            BOSS BATTLE!\n";
        cout << "=====================================\n";

        return new Boss(
            "Dragon Boss",
            currentLevel,
            300,      // HP
            100,      // MP
            40,       // Attack
            20,       // Defense
            15,       // Speed
            500,      // EXP Reward
            1000,     // Gold Reward
            60         // Special Attack Damage
        );
    }

    return new Enemy(
        "Enemy " + to_string(currentLevel),
        currentLevel,
        80 + currentLevel * 20,
        30,
        10 + currentLevel * 5,
        5 + currentLevel,
        5 + currentLevel,
        currentLevel * 100,
        currentLevel * 50
    );
}

// Check Completion
bool GameProgression::isGameCompleted() const
{
    return currentLevel > maxLevel;
}

// Level Up
void GameProgression::levelUpPlayer()
{
    player.setLevel(player.getLevel() + 1);

    player.setMaxHP(player.getMaxHP() + 20);
    player.setCurrentHP(player.getMaxHP());

    player.setMaxMP(player.getMaxMP() + 10);
    player.setCurrentMP(player.getMaxMP());

    player.setAttackPower(player.getAttackPower() + 5);
    player.setDefense(player.getDefense() + 2);
    player.setSpeed(player.getSpeed() + 1);

    cout << "\nPlayer leveled up to Level "
         << player.getLevel() << "!\n";
}

// Display Status
void GameProgression::displayGameStatus() const
{
    cout << "\n========== LEVEL "
         << currentLevel
         << " ==========\n";

    player.displayStats();
}
int GameProgression::getRequiredXP() const
{
    switch (player.getLevel())
    {
    case 1:
        return 100;

    case 2:
        return 250;

    case 3:
        return 450;

    case 4:
        return 700;

    default:
        return 1000;
    }
}