#include "menu.h"
void menuBoard() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	vector<string> menuContent = { "Person vs Person", "Person vs Computer", "Load game", "Leaderboard", "Exit game" };

	for (int i = 0; i < menuContent.size(); i++)
	{
		gotoXY(80 / 2, i + 1);
		cout << i + 1 << ". " << menuContent[i];
	}
}
