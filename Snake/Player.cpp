#include "Player.h"

Player::Player(){
	length = 3;
	coordinates = new int* [length];
	for (int i = 0; i < length ; i++) {
		coordinates[i] = new int[2];
		coordinates[i][0] = 2;
		coordinates[i][1] = 5 - i;
	}
	bufer = new int* [length];
	for (int i = 0; i < length; i++) {
		bufer[i] = new int[2];
	}
}

int Player::getX()
{
	return coordinates[0][0];
}

int Player::getY()
{
	return coordinates[0][1];
}

void Player::moveSnake(int x, int y)
{
	
	for (int i = 0; i < length; i++) {
		bufer[i][0] = coordinates[i][0];
		bufer[i][1] = coordinates[i][1];
	}

	for (int i = 1; i < length; i++) {
		coordinates[i][0] = bufer[i-1][0];
		coordinates[i][1] = bufer[i-1][1];
		
	}
	coordinates[0][0] = x;
	coordinates[0][1] = y;
}

int Player::getLeght()
{
	return length;
}

int** Player::getCoordinate()
{
	return coordinates;
}

int Player::getCoordinateX(int i)
{
	return coordinates[i][0];
}

int Player::getLastX()
{
	return coordinates[length-1][0];
}
int Player::getLastY()
{
	return coordinates[length - 1][1];
}

int Player::getCoordinateY(int i)
{
	return coordinates[i][1];
}



void Player::eat(int x, int y)
{

	for (int i = 0; i < length; i++) {
		bufer[i][0] = coordinates[i][0];
		bufer[i][1] = coordinates[i][1];
	}
	length++;

	coordinates = new int*[length];
	for (int i = 0; i < length; i++) {
		coordinates[i] = new int[2];
	}
	for (int i = 1; i < length; i++) {
		coordinates[i][0] = bufer[i - 1][0];
		coordinates[i][1] = bufer[i - 1][1];
	}
	coordinates[0][0] = x;
	coordinates[0][1] = y;
	bufer = new int* [length];
	for (int i = 0; i < length; i++) {
		bufer[i] = new int[2];
	}

}
