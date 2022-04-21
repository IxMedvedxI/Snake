#pragma once
#include"Player.h"
class Field : protected Player
{
private:
	void BuildWalls(int** field,int n,int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0) {
                    if (j == 0) {
                        field[i][j] = 3;
                    }
                    else {
                        if (j == m - 1) {
                            field[i][j] = 4;
                        }
                        else {
                            field[i][j] = 2;
                        }
                    }
                }
                else {
                    if (i == n - 1) {
                        if (j == 0) {
                            field[i][j] = 5;
                        }
                        else {
                            if (j == m - 1) {
                                field[i][j] = 6;
                            }
                            else {
                                field[i][j] = 2;
                            }
                        }
                    }
                    else{
                        if (j == 0) {
                            field[i][j] = 1;
                        }
                        else {
                            if (j == m - 1) {
                                field[i][j] = 1;
                            }
                            else {
                                field[i][j] = 0;
                            }
                        }
                    }
                }
               
            }
        }
	}
	int n, m;
	int** field;
    char* walls;
    Player gaduka;
    int** coord;
public:
	Field();
    ~Field();

    int creatApple();
    int move(char ch);
    void print();
    void printWall(int i);
    friend ostream& operator<<(ostream& os,const Field& a);
};

