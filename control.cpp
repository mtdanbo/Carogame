#include "control.h"

Person pControl_char(Person p) {
	int press = 0;
	gotoXY(p.x, p.y);
	while (press == 0)
	{
		char key = _getch();
		if (key == 'A' || key == 'a')
		{
			p.x -= 2;
		}
		if (key == 'W' || key == 'w')
		{
			p.y -= 1;
		}
		if (key == 'S' || key == 's')
		{
			p.y += 1;
		}
		if (key == 'D' || key == 'd')
		{
			p.x += 2;
		}
		gotoXY(p.x, p.y);
		if (key == 'H' || key == 'h')
		{
			cout << p.text;
			press = 1;
		}
	}
	return p;

}

Person pControl_num(Person p) {
	int press = 0;
	gotoXY(p.x, p.y);
	while (press == 0)
	{
		char key = _getch();
		if (key == 75)
		{
			p.x -= 2;
		}
		if (key == 72)
		{
			p.y -= 1;
		}
		if (key == 80)
		{
			p.y += 1;
		}
		if (key == 77)
		{
			p.x += 2;
		}
		gotoXY(p.x, p.y);
		if (key == '1')
		{
			cout << p.text;
			press = 1;
		}
	}
	return p;

}