#include <conio.h>
#include"Field.h"
#pragma warning(disable : 4996)
using namespace std;
const int n = 20;
const int m = 30;
int main()
{
    Field game;
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

