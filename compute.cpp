#include "compute.h"
int analyze_vertical(int x, vector<pair<int, int>> data) {
	vector<int> temp;
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i].first == x)
		{
			temp.push_back(data[i].second);
		}
	}
	sort(temp.begin(), temp.end());
	int count = 0;
	for (int i = 0; i < temp.size() - 1; i++)
	{
		if (temp[i + 1] - temp[i] == 1)
		{
			count += 1;
		}
		else
		{
			count = 0;
		}
		if (count >= 4)
		{
			return 1;
		}
	}
	return 0;

}
int analyze_horizontal(int y, vector<pair<int, int>> data) {
	vector<int> temp;
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i].second == y)
		{
			temp.push_back(data[i].first);
		}
	}
	sort(temp.begin(), temp.end());
	int count = 0;
	for (int i = 0; i < temp.size() - 1; i++)
	{
		if (temp[i + 1] - temp[i] == 2)
		{
			count += 1;
		}
		else
		{
			count = 0;
		}
		if (count >= 4)
		{
			return 1;
		}
	}


	return 0;
}
int analyze_diagonal_up(vector<pair<int, int>>data) {
	sort(data.begin(), data.end());
	int count = 0;
	for (int i = 0; i < data.size(); i++)
	{
		count = 0;
		int base_x = data[i].first;
		int base_y = data[i].second;
		for (int k = i + 1; k < data.size(); k++)
		{
			if ((data[k].first - base_x == 2) && (base_y - data[k].second == 1))
			{
				base_x = data[k].first;
				base_y = data[k].second;
				count += 1;
			}

		}
		if (count >= 4)
		{
			break;
		}
	}
	if (count >= 4)
	{
		return 1;
	}
	return 0;
}


int analyze_diagonal_down(vector<pair<int, int>>data) {
	sort(data.begin(), data.end());
	int count = 0;
	for (int i = 0; i < data.size(); i++)
	{
		count = 0;
		int base_x = data[i].first;
		int base_y = data[i].second;
		for (int k = i + 1; k < data.size(); k++)
		{
			if ((data[k].first - base_x == 2) && (data[k].second - base_y == 1))
			{
				base_x = data[k].first;
				base_y = data[k].second;
				count += 1;
			}

		}
		if (count >= 4)
		{
			break;
		}
	}
	if (count >= 4)
	{
		return 1;
	}
	return 0;

}
Container pAnalyze(vector<pair<int, int>> data, Container container) {
	//map<int, int> x_axis;
	//map<int, int> y_axis;
	int temp_x = data[data.size() - 1].first;
	int temp_y = data[data.size() - 1].second;
	if (container.x_axis.count(temp_x) == 0)
	{
		container.x_axis[temp_x] = 1;
	}
	else
	{
		container.x_axis[temp_x] += 1;
		if (container.x_axis[temp_x] >= 5)
		{
			container.win_status = analyze_vertical(temp_x, data);
			if (container.win_status == 1)
			{
				return container;
			}
		}
	}
	if (container.y_axis.count(temp_y) == 0)
	{
		container.y_axis[temp_y] = 1;
	}
	else
	{
		container.y_axis[temp_y] += 1;
		if (container.y_axis[temp_y] >= 5)
		{
			container.win_status = analyze_horizontal(temp_y, data);
			if (container.win_status == 1)
			{
				return container;
			}
		}
	}
	if (container.x_axis.size() >= 5 && container.y_axis.size() >= 5)
	{
		container.win_status = analyze_diagonal_up(data);
		if (container.win_status == 1)
		{
			return container;
		}
	}
	if (container.x_axis.size() >= 5 && container.y_axis.size() >= 5)
	{
		container.win_status = analyze_diagonal_down(data);
		if (container.win_status == 1)
		{
			return container;
		}
	}

	return container;

}