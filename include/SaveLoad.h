#ifndef SAVELOAD_H
#define SAVELOAD_H

#include <string>

// Forward declaration
class Player;

/*
---------------------------------------------------------
SaveLoad Class
---------------------------------------------------------
Responsible for:
- Saving player progress
- Loading saved progress
- Checking if save file exists
- Managing save file path

This class ONLY handles file operations.
---------------------------------------------------------
*/

class SaveLoad
{
private:
    // Default save file location
    const std::string saveFilePath;

public:
    // Constructor
    SaveLoad();

    // Save player data
    bool saveGame(const Player& player);

    // Load player data
    bool loadGame(Player& player);

    // Check whether save file exists
    bool saveFileExists() const;

    // Get save file path
    std::string getSaveFilePath() const;
};

#endif // SAVELOAD_H