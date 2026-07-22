#include "SaveLoad.h"
#include <fstream>
#include <iostream>
#include <ctime>

using namespace std;

// Constructor
SaveLoad::SaveLoad()
{
}

// Destructor
SaveLoad::~SaveLoad()
{
}

// Save Game
bool SaveLoad::saveGame(const Player& player, const string& filename)
{
    // ----------------------------
    // Machine Save File
    // ----------------------------
    ofstream gameFile(filename);

    if (!gameFile.is_open())
    {
        cout << "Error: Unable to save game!" << endl;
        return false;
    }

    gameFile << player.getName() << endl;
    gameFile << player.getLevel() << endl;
    gameFile << player.getCurrentHP() << endl;
    gameFile << player.getMaxHP() << endl;
    gameFile << player.getCurrentMP() << endl;
    gameFile << player.getMaxMP() << endl;
    gameFile << player.getAttackPower() << endl;
    gameFile << player.getDefense() << endl;
    gameFile << player.getSpeed() << endl;
    gameFile << player.getExperience() << endl;
    gameFile << player.getGold() << endl;

    gameFile.close();

    // ----------------------------
    // Human Readable Report
    // ----------------------------
    ofstream report("save_report.txt");

    time_t now = time(0);

    report << "=========================================\n";
    report << "        RPG SAVE GAME REPORT\n";
    report << "=========================================\n\n";

    report << "Player Information\n";
    report << "-----------------------------------------\n";
    report << "Name          : " << player.getName() << endl;
    report << "Level         : " << player.getLevel() << endl;

    report << "\nHealth\n";
    report << "Current HP    : " << player.getCurrentHP() << endl;
    report << "Maximum HP    : " << player.getMaxHP() << endl;

    report << "\nMana\n";
    report << "Current MP    : " << player.getCurrentMP() << endl;
    report << "Maximum MP    : " << player.getMaxMP() << endl;

    report << "\nCombat Stats\n";
    report << "Attack        : " << player.getAttackPower() << endl;
    report << "Defense       : " << player.getDefense() << endl;
    report << "Speed         : " << player.getSpeed() << endl;

    report << "\nProgress\n";
    report << "Experience    : " << player.getExperience() << endl;
    report << "Gold          : " << player.getGold() << endl;

    report << "\nInventory\n";
    report << "-----------------------------------------\n";

    player.getInventory().saveInventory(report);

    report << "\nSave Time\n";
    report << "-----------------------------------------\n";
    report << ctime(&now);

    report << "\n=========================================\n";

    report.close();

    cout << "\nGame Saved Successfully!\n";
    cout << "Created:\n";
    cout << "1. savegame.dat\n";
    cout << "2. save_report.txt\n";

    return true;
}

// Load Game
bool SaveLoad::loadGame(Player& player, const string& filename)
{
    ifstream inFile(filename);

    if (!inFile.is_open())
    {
        cout << "Save file not found!" << endl;
        return false;
    }

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

    getline(inFile, name);

    inFile >> level;
    inFile >> currentHP;
    inFile >> maxHP;
    inFile >> currentMP;
    inFile >> maxMP;
    inFile >> attack;
    inFile >> defense;
    inFile >> speed;
    inFile >> experience;
    inFile >> gold;

    inFile.close();

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

    cout << "\nGame Loaded Successfully!\n";

    return true;
}