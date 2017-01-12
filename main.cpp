#include <iostream>
#include <vector>
#include <queue>
#include <conio.h>
#include <cstdlib>
using namespace std;

int spaces;
int clock[20];
bool activated[20];     // activated describes whether a circle is already activated
vector <int> combo;     // combo is the current combination


// currentPos is the current circle the player is on
void findSolution(int currentPos)
{
    int posA,posB;

    activated[currentPos] = true;
    combo.push_back(currentPos);

    // Output combo if finished
    if (combo.size() == spaces) {
        for (int i = 0; i < spaces; i++)
            cout << combo[i] << " ";
        cout << endl;
    }

    posA = currentPos + clock[currentPos];
    posB = currentPos - clock[currentPos];

    // Keep positions between [0,spaces)
    if (posA > spaces-1)
        posA -= spaces;
    if (posB < 0)
        posB += spaces;

    // Try both possibilities
    if (activated[posA] == false)
        findSolution(posA);
    if (activated[posB] == false && posA != posB)
        findSolution(posB);

    // Backtrack
    activated[currentPos] = false;
    combo.pop_back();
}

int main()
{
    char pause;

    while (true)
    {
        system("CLS");
        cout << "Enter the number of spaces: ";
        cin >> spaces;

        // Vector describing the order the circles should be activated

        cout << "\nStarting from the top going clockwise, enter the values of the spaces:\n";
        for (int i = 0; i < spaces; i++)
            cin >> clock [i];

        cout << "\nPossible Combinations:\n";
        for (int i = 0; i < spaces; i++)
            findSolution(i);

        cout << "Press any key to continue ";
        pause = getche();
    }
}
