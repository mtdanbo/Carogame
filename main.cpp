#include "base.h"
#include "control.h"
#include "compute.h"
#include "menu.h"

int main() {
	gotoXY(80 / 2,0);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout << "WELCOME TO CARO GAME IN 2018 MT Danbo" << endl;
	int sizeBoard;
	menuBoard();
	char choice = 'A';
	while (choice < 49 || choice > 53)
	{
		choice = _getch();
		if (choice == '1')
		{
			sizeBoard = drawBoard();
		}
	}
	Person p1;
	p1.x = 0;
	p1.y = 1;
	p1.text = "X";
	Person p2;
	p2.x = 0;
	p2.y = 1;
	p2.text = "O";
	Container container_p1;
	Container container_p2;
	while (1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		p1 = pControl_char(p1);
		p1.movement.push_back(make_pair(p1.x, p1.y));
		container_p1 = pAnalyze(p1.movement,container_p1);
		p1.win = container_p1.win_status;
		if (p1.win == 1)
		{
			gotoXY(0, sizeBoard+ 5);
			cout << "Congrat p1" << endl;
			break;
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		p2 = pControl_num(p2);
		p2.movement.push_back(make_pair(p2.x, p2.y));
		container_p2 = pAnalyze(p2.movement, container_p2);
		p2.win = container_p2.win_status;
		if (p2.win == 1)
		{
			gotoXY(0, sizeBoard + 5);
			cout << "Congrat p2" << endl;
			break;
		}



	}
	int quit = 0;
	while (quit==0)
	{
		char key = _getch();
		if (key == 'Q' || key == 'q')
		{
			quit = 1;
		}
	}

}