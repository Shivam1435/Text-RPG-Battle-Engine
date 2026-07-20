#include "SaveLoad.h"
#include "Player.h"

#include <fstream>
#include <iostream>

using namespace std;

/*
---------------------------------------------------------
Constructor
---------------------------------------------------------
*/

SaveLoad::SaveLoad()
    : saveFilePath("saves/savegame.txt")
{
}

/*
---------------------------------------------------------
Returns save file path
---------------------------------------------------------
*/

string SaveLoad::getSaveFilePath() const
{
    return saveFilePath;
}

/*
---------------------------------------------------------
Checks if save file exists
---------------------------------------------------------
*/

bool SaveLoad::saveFileExists() const
{
    ifstream file(saveFilePath);

    return file.good();
}

/*
---------------------------------------------------------
Save Game
---------------------------------------------------------
*/

bool SaveLoad::saveGame(const Player& player)
{
    ofstream file(saveFilePath);

    if (!file.is_open())
    {
        cout << "Error: Unable to create save file.\n";
        return false;
    }

    /*
        Save player information.

        These getter functions should be
        provided by Member 1 (Player System).
    */

    file << "Name " << player.getName() << '\n';
    file << "Level " << player.getLevel() << '\n';

    file << "CurrentHP " << player.getCurrentHP() << '\n';
    file << "MaxHP " << player.getMaxHP() << '\n';

    file << "CurrentMP " << player.getCurrentMP() << '\n';
    file << "MaxMP " << player.getMaxMP() << '\n';

    file << "Attack " << player.getAttackPower() << '\n';
    file << "Defense " << player.getDefense() << '\n';
    file << "Speed " << player.getSpeed() << '\n';

    file << "Experience " << player.getExperience() << '\n';
    file << "Gold " << player.getGold() << '\n';

    file.close();

    cout << "Game Saved Successfully!\n";

    return true;
}

/*
---------------------------------------------------------
Load Game
---------------------------------------------------------
*/

bool SaveLoad::loadGame(Player& player)
{
    ifstream file(saveFilePath);

    if (!file.is_open())
    {
        cout << "No save file found.\n";
        return false;
    }

    string label;

    /*
        Read values in same order
        they were written.
    */

    string name;

    int level;
    int currentHP;
    int maxHP;

    int currentMP;
    int maxMP;

    int attack;
    int defense;
    int speed;

    int experience;
    int gold;

    file >> label >> name;

    file >> label >> level;

    file >> label >> currentHP;
    file >> label >> maxHP;

    file >> label >> currentMP;
    file >> label >> maxMP;

    file >> label >> attack;
    file >> label >> defense;
    file >> label >> speed;

    file >> label >> experience;
    file >> label >> gold;

    /*
        Restore player.

        These setter functions should
        be implemented by Member 1.
    */

    player.setName(name);

    player.setLevel(level);

    player.setCurrentHP(currentHP);
    player.setMaxHP(maxHP);

    player.setCurrentMP(currentMP);
    player.setMaxMP(maxMP);

    player.setAttackPower(attack);
    player.setDefense(defense);
    player.setSpeed(speed);

    player.setExperience(experience);
    player.setGold(gold);

    file.close();

    cout << "Game Loaded Successfully!\n";

    return true;
}