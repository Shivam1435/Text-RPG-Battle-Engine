#include "Menu.h"

#include <limits>
#include <cstdlib>

using namespace std;

/*
--------------------------------------------------------
Constructor
--------------------------------------------------------
*/

Menu::Menu()
{
}

/*
--------------------------------------------------------
Splash Screen
--------------------------------------------------------
*/

void Menu::showSplashScreen() const
{
    cout << "\n";
    cout << "=============================================================\n";
    cout << "               TEXT RPG BATTLE ENGINE\n";
    cout << "=============================================================\n";
    cout << "           Every Legend Begins Somewhere...\n";
    cout << "=============================================================\n";
    cout << "\n";
}

/*
--------------------------------------------------------
Main Menu
--------------------------------------------------------
*/

void Menu::showMainMenu() const
{
    cout << "\n";
    cout << "====================== MAIN MENU ======================\n";
    cout << " 1. New Game\n";
    cout << " 2. Continue Game\n";
    cout << " 3. Help\n";
    cout << " 4. Credits\n";
    cout << " 5. Exit\n";
    cout << "=======================================================\n";
}

/*
--------------------------------------------------------
Pause Menu
--------------------------------------------------------
*/

void Menu::showPauseMenu() const
{
    cout << "\n";
    cout << "====================== GAME MENU ======================\n";
    cout << " 1. Resume Game\n";
    cout << " 2. Save Game\n";
    cout << " 3. Main Menu\n";
    cout << " 4. Exit Game\n";
    cout << "=======================================================\n";
}

/*
--------------------------------------------------------
Help Screen
--------------------------------------------------------
*/

void Menu::showHelp() const
{
    cout << "\n";
    cout << "======================== HELP =========================\n";
    cout << "Attack      : Perform a normal attack.\n";
    cout << "Skills      : Use mana to cast special abilities.\n";
    cout << "Inventory   : Use items like potions and equipment.\n";
    cout << "Save        : Save your current game progress.\n";
    cout << "Load        : Continue from your last save.\n";
    cout << "=======================================================\n";
}

/*
--------------------------------------------------------
Credits
--------------------------------------------------------
*/

void Menu::showCredits() const
{
    cout << "\n";
    cout << "======================= CREDITS =======================\n";
    cout << "Player System        : Member 1\n";
    cout << "Enemy System         : Member 2\n";
    cout << "Battle Engine        : Member 3\n";
    cout << "Skills System        : Member 4\n";
    cout << "Inventory & Items    : Member 5\n";
    cout << "Menu & Save/Load     : Member 6\n";
    cout << "Maps & Progression   : Member 7\n";
    cout << "=======================================================\n";
}

/*
--------------------------------------------------------
Input Validation
--------------------------------------------------------
*/

int Menu::getValidatedChoice(int minChoice, int maxChoice)
{
    int choice;

    while (true)
    {
        cout << "Enter your choice: ";

        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        if (choice < minChoice || choice > maxChoice)
        {
            cout << "Choice out of range! Try again.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return choice;
    }
}

/*
--------------------------------------------------------
Exit Confirmation
--------------------------------------------------------
*/

bool Menu::confirmExit() const
{
    char choice;

    cout << "\nAre you sure you want to exit? (Y/N): ";
    cin >> choice;

    choice = static_cast<char>(toupper(choice));

    return (choice == 'Y');
}

/*
--------------------------------------------------------
Start New Game
--------------------------------------------------------
*/

void Menu::startNewGame()
{
    cout << "\nStarting a New Game...\n";

    /*
        Member 7 will connect Story/Map progression here.
    */
}

/*
--------------------------------------------------------
Continue Game
--------------------------------------------------------
*/

void Menu::continueGame(Player& player)
{
    cout << "\nLoading Saved Game...\n";

    /*
        SaveLoad class will be called here.

        Example:

        SaveLoad save;
        save.loadGame(player);
    */
}

/*
--------------------------------------------------------
Save Current Game
--------------------------------------------------------
*/

void Menu::saveCurrentGame(const Player& player)
{
    cout << "\nSaving Game...\n";

    /*
        SaveLoad class will be called here.

        Example:

        SaveLoad save;
        save.saveGame(player);
    */
}