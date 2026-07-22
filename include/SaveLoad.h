#ifndef SAVELOAD_H
#define SAVELOAD_H

#include <string>
#include "Player.h"

using namespace std;

class SaveLoad
{
public:
    // Constructor
    SaveLoad();

    // Destructor
    ~SaveLoad();

    // Save & Load Functions
    bool saveGame(const Player& player, const string& filename);

    bool loadGame(Player& player, const string& filename);
};

#endif