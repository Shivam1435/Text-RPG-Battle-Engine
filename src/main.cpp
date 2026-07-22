#include <iostream>
#include "Menu.h"
#include "GameProgression.h"

#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));
    Menu menu;
    GameProgression game;

    int choice;

    do
    {
        menu.displayMainMenu();

        choice = menu.getChoice();

        switch (choice)
        {
        case 1:
            game.startGame();
            break;

        case 2:
           game.loadGame();
            break;

        case 3:
            cout << "\nThank you for playing!" << endl;
            break;

        default:
            cout << "\nInvalid Choice! Please try again." << endl;
        }

    } while (choice != 3);

    return 0;
}