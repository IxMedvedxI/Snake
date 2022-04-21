#pragma once
#include <iostream>
#include <windows.h>
using namespace std;
class Player{
private:
	int length;
	int** coordinates;
	int** bufer;
public:
	Player();

	void eat(int x, int y);
	int getX();
	int getY();
	void moveSnake(int x, int y);
	int getLeght();
	int** getCoordinate();
	int getCoordinateX(int i);
	int getCoordinateY(int i);
	int getLastX();
	int getLastY();

};

