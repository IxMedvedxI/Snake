#include "Field.h"
Field::Field(){
	int mas[10] = {255,186,205,201,187,200,188,42,2,253};
	n = 15;
	m = 30;
	field = new int*[n];
	for (int i = 0; i < n; i++) {
		field[i] = new int[m];
	}
	walls = new char[10];
	for (int i = 0; i < 10; i++) {
		walls[i] = mas[i];
	}
	BuildWalls(field, n, m);
}



Field::~Field(){}

int Field::creatApple() {
	srand(time(NULL));
	int appx = 1 + rand() % (n -1);
	int appy = 1 + rand() % (m - 1);
	if (field[appx][appy] == 0) {
		field[appx][appy] = 9;
		return 0;
	}
	else {
		return 1;
	}
}

int Field::move(char ch){
	switch (ch){
	case 'w':
		if (field[gaduka.getX() - 1][gaduka.getY()] == 0 ) {
			field[gaduka.getLastX()][gaduka.getLastY()] = 0;
			gaduka.moveSnake(gaduka.getX() - 1, gaduka.getY());
			break;
		}
		else {
			if (field[gaduka.getX() - 1][gaduka.getY()] == 9) {
				while (creatApple())
					cout << *this;
				gaduka.eat(gaduka.getX() - 1, gaduka.getY());
				break;
			}
			else{
				cout << "You Failed" << "\n";
				return 0;
				break;
			}
		}
	case 's':
		if (field[gaduka.getX() + 1][gaduka.getY()] == 0) {
			field[gaduka.getLastX()][gaduka.getLastY()] = 0;
			gaduka.moveSnake(gaduka.getX() + 1, gaduka.getY());
			break;
		}
		else {
			if (field[gaduka.getX() + 1][gaduka.getY()] == 9) {
				while (creatApple())
					cout << *this;
				gaduka.eat(gaduka.getX() + 1, gaduka.getY());
				break;
			}
			else {
				cout << "You Failed"<<"\n";
				return 0;
				break;
			}
		}
	case'd':
		if (field[gaduka.getX()][gaduka.getY() + 1] == 0) {
			field[gaduka.getLastX()][gaduka.getLastY()] = 0;
			gaduka.moveSnake( gaduka.getX() , gaduka.getY() + 1 );
			break;
		}
		else {
			if (field[gaduka.getX()][gaduka.getY() + 1] == 9) {
				while (creatApple())
					cout << *this;
				gaduka.eat( gaduka.getX() , gaduka.getY() + 1 );
				break;
			}
			else {
				cout << "You Failed" << "\n";
				return 0;
				break;
			}
		}
	case'a':
		if (field[gaduka.getX()][gaduka.getY() - 1] == 0) {
			field[gaduka.getLastX()][gaduka.getLastY()] = 0;
			gaduka.moveSnake(gaduka.getX(), gaduka.getY() - 1);
			break;
		}
		else {
			if (field[gaduka.getX()][gaduka.getY() - 1] == 9) {
				while (creatApple())
					cout<<*this;
				gaduka.eat(gaduka.getX(), gaduka.getY() - 1);
				break;
			}
			else {
				cout << "You Failed" << "\n";
				return 0;
				break;
			}
		}
	default:
		return 1;
		break;
	}
	field[gaduka.getCoordinateX(1)][gaduka.getCoordinateY(1)] = 7;
	field[gaduka.getCoordinateX(0)][gaduka.getCoordinateY(0)] = 8;
	return 1;
}


void Field::printWall(int i)
{
	cout << walls[i];
}

ostream& operator<<(ostream& os,const Field& a)
{
	system("cls");
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < a.m; j++) {
			os << a.walls[a.field[i][j]];
		}
		os << "\n";
	}
	Sleep(50);
	return os;
}
