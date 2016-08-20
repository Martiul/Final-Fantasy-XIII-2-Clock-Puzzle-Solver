#include <iostream>
#include <vector>
#include <queue>
#include <conio.h>
#include <cstdlib>
using namespace std;

int clock[20];
int spaces;

void findSolution(vector <int> combo, vector <bool> flag, int currentPos)
{
    int a,b;
    flag[currentPos] = true;
    combo.push_back(currentPos);

    if (combo.size() == spaces)
    {
        for (int i = 0; i < spaces; i++)
            cout << combo[i] << " ";
        cout << endl;
    }

    a = currentPos + clock[currentPos];
    b = currentPos - clock[currentPos];
    if (a > spaces-1)
        a -= spaces;
    if (b < 0)
        b += spaces;
    if (flag[a] != true)
        findSolution(combo,flag,a);
    if (flag[b] != true && a!=b)
        findSolution(combo,flag,b);
}

int main()
{
    char pause;
    while (true)
    {
        system("CLS");
        cout << "Enter the number of spaces:\n";
        cin >> spaces;
        vector <bool> flag(spaces,0);
        vector <int> combo(0);

        cout << "\nStarting from the top going clockwise, enter the values of the spaces:\n";
        for (int i = 0; i < spaces; i++)
            cin >> clock [i];
        cout << "\nPossible Combinations:\n";
        for (int i = 0; i < spaces; i++)
            findSolution(combo,flag,i);
        cout << "Press any key to continue ";
        pause = getche();
    }
}
