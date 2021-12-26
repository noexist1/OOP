#include "execution.h"

using namespace std;


void computer();

void player();

void start();

void menu()
{
    cout << "Main Menu: \n 1.Rules\n 2.Play with Computer\n 3.Multiplayer\n 4.Exit\n";
}

void rules()
{
    system(std::string("start https://ru.wikipedia.org/wiki/%D0%91%D1%8B%D0%BA%D0%B8_%D0%B8_%D0%BA%D0%BE%D1%80%D0%BE%D0%B2%D1%8B").c_str());
    start();
}

void with_computer(int n)
{
    switch (n)
    {
        case 1:
            cout << "Make your first turn\n";
            break;
        case 2:
            cout << "Make your next turn\n";
            break;
        case 3:
            cout << "CONGRATULATION! YOU WON!\n";
            break;
        case 4:
            cout << "Result:\n";
            break;
        case 5:
            cout << "The attempts ended. Try again\n";
            break;
        case 6:
            cout << "Do you want to play again?\n    Y/N\n";
            break;
        case 7:
            cout << "Correct number:\n";
            break;
    }
}

void with_player(int n){
    switch (n)
    {
        case 1:
            cout << "1st player choose a number:\n";
            break;
        case 2:
            cout << "2nd player make your next turn\n";
            break;
        case 3:
            cout << "\n\n\n\n\n\n\n\n\n2nd player make your first turn\n";
            break;
        case 4:
            cout << "Result:\n";
            break;
        case 5:
            cout << "CONGRATULATION 2ND PLAYER!\n YOU WON!\n";
            break;
        case 6:
            cout << "CONGRATULATION 1ND PLAYER!\n YOU WON!\n";
            break;
        case 7:
            cout << "Do you want to play again?\n    Y/N\n";
            break;
    }
}
