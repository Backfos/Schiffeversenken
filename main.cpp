#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include<windows.h>
#include "everything.h"
using namespace std;


int feld[4][4] =
{
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};
int fertig[4][4] =
{
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

void create()
{
    int botnummer;
    int a;
    int b;

    cin.get();
    cout << "how many parts do you want change: ";
    cin >> botnummer;

    if (botnummer == 0)
    {
        cout << "Du kannst nicht 0 Boote angeben!!!";
    }
    while (botnummer != 0)
    {
        int a = rand() % 4;
        cout << "\n" << a;
        int b = rand() % 4;
        cout << "\n" << b;
        feld[a][b] = 1;
        --botnummer;
    }
}

int main()
{
    int f;
    int g;
    int targets = 0;
    

    create();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            while(feld[i][j] == fertig[i][j])
            {
                cout << "Welches Feld moechtest du angreifen? (Zeile): ";
                cin >> f;
                cout << "Welches Feld moechtest du angreifen? (Spalte): ";
                cin >> g;

                if (feld[f][g] == 1)
                {
                    cout << "Treffer! Du hast ein Schiff versenkt!" << endl;
                    feld[f][g] = 0;
                    ++targets;
                    if (targets == 2)
                    {
                        cout << "Du hast gewonnen!" << endl;
                        Sleep(10000);
                        return 0;
                    }
                }
                else if (feld[f][g] == 0)
                {
                     cout << "Daneben!" << endl;
                }
                else 
                {
                     cout << "Ungültige Eingabe!" << endl;
                }
                    
            }
        }
    }
}
