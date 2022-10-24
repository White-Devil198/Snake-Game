#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include<conio.h>
#include<cstdlib>
using namespace std;
struct point {
	int x;
	int y;
};
void Color(int color)//to change colour
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void displaysnake(point p[], int size) {
	int index;
	for (index = 0; index < size; index++) {
		gotoxy(p[index].x, p[index].y);
		cout << "o";
	}
}
void removesnake(point p[], int size) {
	int index;
	for (index = 0; index < size; index++) {
		gotoxy(p[index].x, p[index].y);
		cout << " ";
	}
}
void moveup(point p[], int size) {
	int index;
	for (index = size - 1; index > 0; index--) {
		p[index].x = p[index - 1].x;
		p[index].y = p[index - 1].y;

	}
	p[index].y = p[index].y - 1;
}
void movedown(point p[], int size) {
	int index;
	for (index = size - 1; index > 0; index--) {
		p[index].x = p[index - 1].x;
		p[index].y = p[index - 1].y;

	}
	p[index].y = p[index].y + 1;
}
void moveright(point p[], int size) {
	int index;
	for (index = size - 1; index > 0; index--) {
		p[index].x = p[index - 1].x;
		p[index].y = p[index - 1].y;

	}
	p[index].x = p[index].x + 1;
}
void moveleft(point p[], int size) {
	int index;
	for (index = size - 1; index > 0; index--) {
		p[index].x = p[index - 1].x;
		p[index].y = p[index - 1].y;

	}
	p[index].x = p[index].x - 1;
}
void movement(char input, point p[], int size) {
	if (input == 'w') {
		moveup(p, size);

	}
	if (input == 's') {
		movedown(p, size);

	}
	if (input == 'd') {
		moveright(p, size);

	}
	if (input == 'a') {
		moveleft(p, size);

	}
}
int gameoverbyhistail(point p[], int size) {
	int i;
	for (i = 1; i < size; i++) {
		if (p[0].x == p[i].x && p[0].y == p[i].y) {
			return 1;
		}
	}
	return 0;
}
int gameoverbyboundary(point p[])
{
	int a = 0, b = 0, c = 20, d = 50;
	for (int x = 0; x <= 50; x++) {
		if (p[0].x == x && p[0].y == a) {
			return 1;
		}
	}
	for (int y = 1; y <= 20; y++) {
		if (p[0].x == b && p[0].y == y) {
			return 1;
		}
	}
	for (int x = 0; x <= 50; x++) {
		if (p[0].x == x && p[0].y == c) {
			return 1;
		}
	}
	for (int y = 1; y <= 20; y++) {
		if (p[0].x == d && p[0].y == y) {
			return 1;
		}
	}
	return 0;
}
int teleport(point p[])
{
	if (p[0].x >= 50)//right teleport
		p[0].x = 1;
	if (p[0].x < 1)//left teleport
		p[0].x = 50 - 1;

	if (p[0].y >= 20)//bottom
		p[0].y = 1;
	else if (p[0].y < 1)//top
		p[0].y = 20 - 1;

	return 0;
}
int generatefood(point p[], int& size, int& a, int& b, int c, int& score) {
	if (c == 1) {
		a = rand() % 50;
		b = rand() % 20;
		if (b == 0) {
			b = b + 1;
		}
		gotoxy(a, b);
		cout << "#";
	}
	if (p[0].x == a && p[0].y == b) {
		size++;
		score = score + 10;
		return 1;
	}
	return 0;
}

void storepoints(point p[], int size) {
	int index;
	int x = 5; int y = 10;
	for (index = 0; index < size; index++) {
		p[index].x = x;
		p[index].y = y;
		x++;
		y++;
	}
}
void makeboundary() {
	int x = 0, y = 0;
	for (int y = 1; y <= 20; y++)  //left wall
	{
		gotoxy(x, y);
		Color(3);
		cout << ")";
	}
	for (int y = 0; y <= 50; y++) //top bowder of snacke
	{
		gotoxy(y, x);
		Color(3);
		cout << ")";
	}
	for (int y = 1; y <= 20; y++) //right side of wall
	{
		gotoxy(50, y);
		Color(3);  //right
		cout << "(";
	}
	for (int y = 0; y <= 50; y++) //bottem side of wall
	{
		gotoxy(y, 20);
		Color(3);
		cout << ")";
	}

}
void makeobs()
{
	gotoxy(10, 11);		//TO DRAW OBESTECLES
	cout << "IIIIIIIII";


	gotoxy(33, 7);		//TO DRAW OBESTECLES
	cout << "IIIIIIIII";




}

int killobj(point p[])
{
	if (p[0].y == 11 && p[0].x >= 10 && p[0].x <= 18)
	{
		return 1;
	}

	if (p[0].y == 7 && p[0].x >= 33 && p[0].x <= 41)
	{
		return 1;
	}


}
void controls()
{
	Color(017);
	cout << "CONTROLS" << endl;
	Color(01);
	cout << "PRESS ";
	Color(017);
	cout << " W ";
	Color(01);
	cout << "TO MOVE UP" << endl;
	Color(01);
	cout << "PRESS ";
	Color(017);
	cout << " S ";
	Color(01);
	cout << "TO MOVE DOWN" << endl;
	Color(01);
	cout << "PRESS ";
	Color(017);
	cout << " A ";
	Color(01);
	cout << "TO MOVE LEFT" << endl;
	Color(01);
	cout << "PRESS ";
	Color(017);
	cout << " D ";
	Color(01);
	cout << "TO MOVE RIGHT" << endl;
}

int speed() // this for the speed setting 
{
	int j;
	system("cls");

	Color(2);
	cout << "\n\n\n\n\n\n\t\t\t\t\t\t:::::::::::::::::::\n";
	cout << "\t\t\t\t\t\t:: 5: Very Fast. ::\n";
	cout << "\t\t\t\t\t\t:: 4: Fast.      ::\n";
	cout << "\t\t\t\t\t\t:: 3: Normal     ::\n";
	cout << "\t\t\t\t\t\t:: 2: Slow       ::\n";
	cout << "\t\t\t\t\t\t:: 1: Very Slow. ::" << endl;
	cout << "\t\t\t\t\t\t:::::::::::::::::::\n";
	cout << "\t\t\t\t\t\tEnter The Speed: ";
	cin >> j;
	system("cls");
	if (j == 1)
		j = 300;
	if (j == 2)
		j = 100;
	if (j == 3)
		j = 60;
	if (j == 4)
		j = 30;
	if (j == 5)
		j = 1;
	return j;
}
void controls_instruction()
{
	Color(3);
	cout << ":::::::::::::::::::::::::::\n";
	cout << "\t\t\t\t\t::How to Play Game       ::\n";
	cout << "\t\t\t\t\t:::::::::::::::::::::::::::\n";

	Color(5);
	cout << "\n\n\t\t\t\t\tPress W = Up\n";
	cout << "\t\t\t\t\tPress S = Down\n";
	cout << "\t\t\t\t\tPress A = Left\n";
	cout << "\t\t\t\t\tPress D = Right\n";
	cout << "\t\t\t\t\tPress Space = Pause\n";
}


int main()
{
	int		n = 3;						//SIZE OF TAIL
	int a, u, b, set, c = 1, score = 0, z, j, spe;
	point p[30];
	storepoints(p, n);
	char input = 'd';
	Color(3);
	cout << "\n\n\n\n\n\n\t\t\t\t\tThis Game is develope by:\n\n";
	Color(6);
	cout << "\t\t\t\t\t:::::::::::::::::::::::::::::::::::\n";
	cout << "\t\t\t\t\t::  Muhammad Haris               ::\n";
	cout << "\t\t\t\t\t::  Muhammad Ahsanullah Mangat   ::\n";
	cout << "\t\t\t\t\t::  Hafiz Hammad Sharafat Satti  ::\n";
	cout << "\t\t\t\t\t:::::::::::::::::::::::::::::::::::\n\n";
	Color(4);
	cout << "\t\t\t\t\t::Select the Options from Menu::\n\n";
	Color(5);
	cout << "\t\t\t\t\t1: Start the Basic Game.\n";
	cout << "\t\t\t\t\t2: Select The Map.\n";
	cout << "\t\t\t\t\t3: How to play.\n";
	cin >> set;
	if (set == 1)  // start the basic game
	{
		spe = speed();  // snack speed
		system("CLS");
		makeboundary(); // draw boundrys
		while (1)
		{
			if (_kbhit())
			{
				input = _getch();
			}

			c = generatefood(p, n, a, b, c, score); // food draw

			gotoxy(0, 21);
			Color(02);      //Printing Score
			cout << "\t\t:::::::::::::::" << endl;
			cout << "\t\t   Score:" << score << endl;
			cout << "\t\t:::::::::::::::" << endl;


			movement(input, p, n); // for snack movement
			teleport(p);  // if map was boundryless
			displaysnake(p, n);  // draw snak
			Sleep(spe); // speed
			removesnake(p, n);   //after move snack

			j = gameoverbyhistail(p, n);
			if (j == 1) {
				break;
			}
		}
	}
	if (set == 2)
	{
		system("cls");
		//Game start menu setting
		Color(6);
		cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t   ::::::::::::::::::::\n";
		cout << "\t\t\t\t\t   :::";

		Color(4);
		cout << "Select the Map";

		Color(6);
		cout << ":::\n";
		cout << "\t\t\t\t\t   ::::::::::::::::::::\n\n\n";

		Color(2);
		cout << "\t\t\t\t\t1: Bodarless Map\n";
		cout << "\t\t\t\t\t2: Box Bodar Map\n";
		cout << "\t\t\t\t\t3: Obstacle Map With Bordor\n";
		cout << "\t\t\t\t\t4: Obstacle Map Without Bordor\n";

		int map;
		cin >> map;
		if (map == 1)
		{
			spe = speed();
			system("CLS");
			makeboundary();
			while (1)
			{
				if (_kbhit())
				{
					input = _getch();
				}

				c = generatefood(p, n, a, b, c, score);

				gotoxy(0, 21);  //Printing Score
				Color(02);
				cout << "\t\t:::::::::::::::" << endl;
				cout << "\t\t   Score:" << score << endl;
				cout << "\t\t:::::::::::::::" << endl;

				movement(input, p, n);
				teleport(p);
				displaysnake(p, n);
				Sleep(spe);
				removesnake(p, n);

				j = gameoverbyhistail(p, n);
				if (j == 1) {
					break;
				}
			}
		}
		else if (map == 2) // if select map 2
		{
			spe = speed();
			system("CLS");
			Color(4);
			makeboundary();
			Color(017);
			while (1)
			{
				if (_kbhit()) {
					input = _getch();
				}
				displaysnake(p, n);
				Sleep(spe);
				removesnake(p, n);
				c = generatefood(p, n, a, b, c, score);

				gotoxy(0, 21);  //Printing Score
				Color(02);
				cout << "\t\t:::::::::::::::" << endl;
				cout << "\t\t   Score:" << score << endl;
				cout << "\t\t:::::::::::::::" << endl;

				movement(input, p, n);
				z = gameoverbyboundary(p);
				if (z == 1) {
					break;
				}
				j = gameoverbyhistail(p, n);
				if (j == 1) {
					break;
				}
			}
		}
		else if (map == 3)
		{
			spe = speed();
			system("CLS");
			makeboundary();
			makeobs();
			while (1)
			{
				if (_kbhit()) {
					input = _getch();
				}
				displaysnake(p, n);
				Sleep(spe);
				removesnake(p, n);

				c = generatefood(p, n, a, b, c, score);

				gotoxy(0, 21);  //Printing Score
				Color(02);
				cout << "\t\t:::::::::::::::" << endl;
				cout << "\t\t   Score:" << score << endl;
				cout << "\t\t:::::::::::::::" << endl;

				movement(input, p, n);
				z = gameoverbyboundary(p);
				if (z == 1) {
					break;
				}
				u = killobj(p);
				if (u == 1)
				{
					break;
				}
				j = gameoverbyhistail(p, n);
				if (j == 1)
				{
					break;


				}
			}
		}
		else if (map == 4)
		{
			spe = speed();
			system("CLS");
			makeboundary();
			makeobs();
			while (1)
			{
				if (_kbhit()) {
					input = _getch();
				}
				displaysnake(p, n);
				Sleep(spe);
				removesnake(p, n);

				c = generatefood(p, n, a, b, c, score);

				gotoxy(0, 21);  //Printing Score
				Color(02);
				cout << "\t\t:::::::::::::::" << endl;
				cout << "\t\t   Score:" << score << endl;
				cout << "\t\t:::::::::::::::" << endl;

				movement(input, p, n);
				teleport(p);
				u = killobj(p);
				if (u == 1)
				{
					break;
				}
				j = gameoverbyhistail(p, n);
				if (j == 1)
				{
					break;


				}
			}
		}

	}
	if (set == 3)
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\t\t\t\t\t";
		controls_instruction();
		int ext, retun;

		Color(2);
		cout << "\n\n\t\t\t\t\tPress 1 to Play Basic Game.\n";
		cout << "\t\t\t\t\tPress 2 to Exit.";
		cin >> retun;

		Color(017);
		if (retun == 1)
		{

			system("cls");

			spe = speed();
			system("CLS");
			makeboundary();
			while (1)
			{
				if (_kbhit())
				{
					input = _getch();
				}

				c = generatefood(p, n, a, b, c, score);

				gotoxy(0, 21);  //Printing Score
				Color(02);
				cout << "\t\t:::::::::::::::" << endl;
				cout << "\t\t   Score:" << score << endl;
				cout << "\t\t:::::::::::::::" << endl;

				movement(input, p, n);
				teleport(p);
				displaysnake(p, n);
				Sleep(spe);
				removesnake(p, n);

				j = gameoverbyhistail(p, n);
				if (j == 1) {
					break;
				}


			}

		}
		{
			if (retun == 2)
			{
				return 0;
			}
		}




	}
	else if (set > 3 || set <= 0)
	{
		Color(04);
		cout << "\n\n\n::::::::::::::::::::::::::\n";
		cout << "::::invilaid Selection::::\n";
		cout << "::::::::::::::::::::::::::\n\n\n\n\n";
		Color(07);
	}

	system("CLS");
	Color(4);
	cout << "\n\n\n\n\n\t\t\t  #####                          #######                      \n";
	cout << "\t\t\t #     #   ##   #    # ######    #     # #    # ###### #####  \n";
	cout << "\t\t\t #        #  #  ##  ## #         #     # #    # #      #    # \n";
	cout << "\t\t\t #  #### #    # # ## # #####     #     # #    # #####  #    # \n";
	cout << "\t\t\t #     # ###### #    # #         #     # #    # #      #####  \n";
	cout << "\t\t\t #     # #    # #    # #         #     #  #  #  #      #   #  \n";
	cout << "\t\t\t  #####  #    # #    # ######    #######   ##   ###### #    # \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	Color(7);






}