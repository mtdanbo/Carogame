#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

void gotoXY(int x_pos, int y_pos);
struct Person
{
	int x;
	int y;
	string text;
	vector<pair<int, int>>movement;
	int win;
};
struct Container
{
	map<int, int>x_axis;
	map<int, int>y_axis;
	int win_status = 0;
};