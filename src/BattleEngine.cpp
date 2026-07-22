#include "BattleEngine.h"
#include <iostream>

#include "Boss.h"
#include <cstdlib>
#include <ctime>

using namespace std;

BattleEngine::BattleEngine(Player* p, Character* e)
{
    this->player = p;
    this->enemy = e;
}
void BattleEngine::useItem()
{
    Inventory &inventory = player->getInventory();

    if (inventory.isEmpty())
    {
        cout << "\nInventory is empty!\n";
        return;
    }

    inventory.displayInventory();

    cout << "\nEnter item name: ";

    cin.ignore();
    string itemName;
    getline(cin, itemName);

    if (inventory.useItem(itemName))
    {
        if (itemName == "Health Potion")
        {
            int hp = player->getCurrentHP() + 50;

            if (hp > player->getMaxHP())
                hp = player->getMaxHP();

            player->setCurrentHP(hp);

            cout << "HP Restored!\n";
        }
        else if (itemName == "Mana Potion")
        {
            int mp = player->getCurrentMP() + 30;

            if (mp > player->getMaxMP())
                mp = player->getMaxMP();

            player->setCurrentMP(mp);

            cout << "MP Restored!\n";
        }
    }
    else
    {
        cout << "Item not found!\n";
    }
}
void BattleEngine::displayBattleMenu()
{
    cout << "\n====================================\n";
    cout << "            BATTLE\n";
    cout << "====================================\n";

    cout << "Player HP : "
         << player->getCurrentHP()
         << "/"
         << player->getMaxHP()
         << endl;

    cout << "Player MP : "
         << player->getCurrentMP()
         << "/"
         << player->getMaxMP()
         << endl;

    cout << "Enemy HP  : "
         << enemy->getCurrentHP()
         << "/"
         << enemy->getMaxHP()
         << endl;

    cout << "\nChoose Action\n";
    cout << "1. Attack\n";
    cout << "2. Use Skill\n";
    cout << "3. Use Item\n";
    cout << "4. View Stats\n";
    cout << "5. Save Game\n";
    cout << "6. Exit Battle\n";
}
void BattleEngine::useSkill()
{
    int choice;

    cout << "\n========== SKILLS ==========\n";
    cout << "Current MP : " << player->getCurrentMP()
         << "/" << player->getMaxMP() << endl;

    cout << "1. Fireball (20 MP)\n";
    cout << "2. Heal (15 MP)\n";
    cout << "3. Power Strike (25 MP)\n";
    cout << "4. Back\n";

    cout << "Enter choice: ";
    cin >> choice;

    switch(choice)
    {
    case 1:
        if(player->getCurrentMP() >= 20)
        {
            player->setCurrentMP(player->getCurrentMP() - 20);

            enemy->setCurrentHP(enemy->getCurrentHP() - 35);

            cout << "\nFireball used!\n";
            cout << "35 damage dealt.\n";
        }
        else
        {
            cout << "\nNot enough MP!\n";
        }
        break;

    case 2:
        if(player->getCurrentMP() >= 15)
        {
            player->setCurrentMP(player->getCurrentMP() - 15);

            int hp = player->getCurrentHP() + 30;

            if(hp > player->getMaxHP())
                hp = player->getMaxHP();

            player->setCurrentHP(hp);

            cout << "\nHeal used!\n";
            cout << "Recovered 30 HP.\n";
        }
        else
        {
            cout << "\nNot enough MP!\n";
        }
        break;

    case 3:
        if(player->getCurrentMP() >= 25)
        {
            player->setCurrentMP(player->getCurrentMP() - 25);

            enemy->setCurrentHP(enemy->getCurrentHP() - 50);

            cout << "\nPower Strike used!\n";
            cout << "50 damage dealt.\n";
        }
        else
        {
            cout << "\nNot enough MP!\n";
        }
        break;

    case 4:
        return;

    default:
        cout << "\nInvalid Choice!\n";
    }

    if(enemy->getCurrentHP() < 0)
        enemy->setCurrentHP(0);
}
int BattleEngine::getPlayerChoice()
{
    int choice;

    while (true)
    {
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 6)
            return choice;

        cout << "Invalid Choice!\n";
    }
}

bool BattleEngine::playerTurn()
{
    int choice = getPlayerChoice();

    switch (choice)
    {
    case 1:
        cout << "\nYou attacked the enemy!\n";
        player->attack(*enemy);
        return true;

    case 2:
        useSkill();
        return true;

    case 3:
        useItem();
        return true;

    case 4:
        player->displayStats();
        return false;

    case 5:
    {
        if (saveLoad.saveGame(*player, "savegame.dat"))
            cout << "\nGame Saved Successfully!\n";
        else
            cout << "\nFailed to Save Game!\n";

        return false;
    }

    case 6:
        cout << "\nYou ran away from battle.\n";
        player->setCurrentHP(0);
        return true;
    }

    return false;
}
void BattleEngine::enemyTurn()
{
    if (!enemy->isAlive())
        return;

    cout << "\nEnemy Turn\n";

    Boss* boss = dynamic_cast<Boss*>(enemy);

    if (boss != nullptr)
    {
        int chance = rand() % 100;

        if (chance < 30)
        {
            boss->specialAttack(*player);
            return;
        }
    }

    enemy->attack(*player);
}

void BattleEngine::startBattle()
{
    cout << "\n===== BATTLE START =====\n";

    while (player->isAlive() && enemy->isAlive())
    {
        displayBattleMenu();

        bool turnFinished = playerTurn();

        if (turnFinished && enemy->isAlive())
        {
            enemyTurn();
        }
    }

    if (player->isAlive())
    if (player->isAlive())
{
    cout << "\n====================================\n";
    cout << "         YOU WIN!\n";
    cout << "====================================\n";

    Enemy* defeatedEnemy = dynamic_cast<Enemy*>(enemy);

    if (defeatedEnemy != nullptr)
    {
        int xp = defeatedEnemy->getXPReward();
        int gold = defeatedEnemy->getGoldReward();

        player->setExperience(player->getExperience() + xp);
        player->setGold(player->getGold() + gold);

        cout << "\n========== REWARDS ==========\n";
        cout << "XP Gained   : +" << xp << endl;
        cout << "Gold Gained : +" << gold << endl;

        cout << "\nCurrent XP   : " << player->getExperience() << endl;
        cout << "Current Gold : " << player->getGold() << endl;
    }
}
    else
    {
        cout << "\n====================================\n";
        cout << "        GAME OVER\n";
        cout << "====================================\n";
    }
}