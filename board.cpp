#include "board.h"
void drawBoard(int sizeBoard) {
	system("cls");
	for (int i = 0; i < sizeBoard; i++)
	{
		for (int k = 0; k < sizeBoard; k++)
		{
			cout << "_ ";
			Sleep(10);
		}
		cout << endl;
	}
}