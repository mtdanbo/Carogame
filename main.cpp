#include "base.h"
#include "control.h"
#include "compute.h"
#include "menu.h"
#include "board.h"

//--------------------PvP mode--------------------//

void PvP_mode() {
	system("cls");
	//=================Set initial value for each player ===================//
	Person p1;
	p1.x = 0;
	p1.y = 0;
	Container container_p1;

	Person p2;
	p2.x = 0;
	p2.y = 0;
	Container container_p2;

	//=================== Set icon for each player ==========================//
	string icon_input;
	cout << "Please choose icon for each character" << endl;
	cout << "You can only choose X or O icon for each character" << endl;
	cout << "Player 1: ";
	cin >> icon_input;
	p1.text = icon_input;
	cout << "Player 2: ";
	cin >> icon_input;
	p2.text = icon_input;
	//=================== Set color for each icon ==========================//
	if (p1.text == "X")
	{
		p1.color = 12;
		p2.color = 10;
	}
	else
	{
		p1.color = 10;
		p2.color = 12;
	}
	cout << "OK tks, P1 icon is: " << p1.text << endl;
	cout << "Ok tks, P2 icon is: " << p2.text << endl;
	system("pause");
	system("cls");

	//=================== Set the size of the board ==========================//
	cout << "OK next step, please choose your mode" << endl;
	cout << "1. 3x3" << endl;
	cout << "2. 4x4" << endl;
	cout << "3. NxN (with N >= 5)" << endl;
	int mode_choice;
	cout << "Your choice is: ";
	cin >> mode_choice;
	system("pause");
	system("cls");
	//=================== Compute win or loose for player ==========================//

	//----------------- Compute for 3X3 -------------------//
	if (mode_choice == 1)
	{
		drawBoard(3);
		while (1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p1.color);
			p1 = pControl_char(p1);
			p1.movement.push_back(make_pair(p1.x, p1.y));
			container_p1 = pAnalyze(p1.movement, container_p1);
			p1.win = container_p1.win_status;
			if (p1.win == 1)
			{
				gotoXY(0, 3 + 5);
				cout << "Congrat p1" << endl;
				break;
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p2.color);
			p2 = pControl_num(p2);
			p2.movement.push_back(make_pair(p2.x, p2.y));
			container_p2 = pAnalyze(p2.movement, container_p2);
			p2.win = container_p2.win_status;
			if (p2.win == 1)
			{
				gotoXY(0, 3 + 5);
				cout << "Congrat p2" << endl;
				break;
			}
		}
		int quit = 0;
		while (quit == 0)
		{
			char key = _getch();
			if (key == 'Q' || key == 'q')
			{
				quit = 1;
			}
		}
	}
	//----------------- Compute for 4X4 -------------------//
	if (mode_choice == 2)
	{
		drawBoard(4);
		while (1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p1.color);
			p1 = pControl_char(p1);
			p1.movement.push_back(make_pair(p1.x, p1.y));
			container_p1 = pAnalyze(p1.movement, container_p1);
			p1.win = container_p1.win_status;
			if (p1.win == 1)
			{
				gotoXY(0, 4 + 5);
				cout << "Congrat p1" << endl;
				break;
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p2.color);
			p2 = pControl_num(p2);
			p2.movement.push_back(make_pair(p2.x, p2.y));
			container_p2 = pAnalyze(p2.movement, container_p2);
			p2.win = container_p2.win_status;
			if (p2.win == 1)
			{
				gotoXY(0, 4 + 5);
				cout << "Congrat p2" << endl;
				break;
			}
		}
		int quit = 0;
		while (quit == 0)
		{
			char key = _getch();
			if (key == 'Q' || key == 'q')
			{
				quit = 1;
			}
		}
	}
	//----------------- Compute for NxN -------------------//
	if (mode_choice == 3)
	{
		int sizeBoard;
		cout << "Please choose your board size: ";
		cin >> sizeBoard;
		cout << "Ok, tks your size board is: " << sizeBoard << endl;
		system("pause");
		drawBoard(sizeBoard);
		while (1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p1.color);
			p1 = pControl_char(p1);
			p1.movement.push_back(make_pair(p1.x, p1.y));
			container_p1 = pAnalyze(p1.movement, container_p1);
			p1.win = container_p1.win_status;
			if (p1.win == 1)
			{
				gotoXY(0, sizeBoard + 5);
				cout << "Congrat p1" << endl;
				break;
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p2.color);
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
		while (quit == 0)
		{
			char key = _getch();
			if (key == 'Q' || key == 'q')
			{
				quit = 1;
			}
		}
	}

}

//--------------------PvC mode--------------------//




//-----------------Main game----------------//
int main() {
	gotoXY(80 / 2,0);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout << "WELCOME TO CARO GAME IN 2018" << endl;
	menuBoard();
	char choice = 'A';
	while (choice < 49 || choice > 53)
	{
		choice = _getch();
		if (choice == '1')
		{
			PvP_mode();
		}
	}
}