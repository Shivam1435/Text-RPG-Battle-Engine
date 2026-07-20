#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>

// Forward declaration
class Player;

/*
--------------------------------------------------------
Menu Class
--------------------------------------------------------
Responsible for:
- Displaying all game menus
- Handling user interaction
- Starting a new game
- Continuing a saved game
- Displaying help and credits
- Calling Save/Load operations
--------------------------------------------------------
*/

class Menu
{
private:
    // Validates integer input within a given range
    int getValidatedChoice(int minChoice, int maxChoice);

public:
    // Constructor
    Menu();

    // ---------- Display Functions ----------
    void showSplashScreen() const;
    void showMainMenu() const;
    void showPauseMenu() const;
    void showHelp() const;
    void showCredits() const;

    // ---------- Menu Operations ----------
    void startNewGame();
    void continueGame(Player& player);
    void saveCurrentGame(const Player& player);

    // ---------- Utility ----------
    bool confirmExit() const;
};

#endif // MENU_H