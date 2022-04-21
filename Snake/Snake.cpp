#include <conio.h>
#include"Field.h"
#pragma warning(disable : 4996)
using namespace std;
const int n = 20;
const int m = 30;
int main()
{
    Field game;
    //game.print();
   /* int field[n][m];
    char walls[7] = { 255, 186,205,201,187,200,188 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << walls[field[i][j]];
        }
        cout << "\n";
    }*/
    char ch = 'd';
    int code;
    int start = 1;
    while (game.creatApple());
    while (start)
    {
        while (!kbhit()) {
            start = game.move(ch);
            cout << game;
        }
        ch = getch();
        
    }
    cout << "You failed";

}

