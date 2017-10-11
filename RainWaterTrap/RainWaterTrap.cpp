// RainWaterTrap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct BarInfo
{
	BarInfo(int value, int left, int right)
	{
		height = value;
		maxLeft = left;
		maxRight = right;
	}

	int height;
	int maxLeft;
	int maxRight;
};

int ComputeRainWater(vector<int> bars)
{
	vector<BarInfo> barInfo;

	for (auto it = bars.begin(); it < bars.end(); ++it)
	{
		barInfo.emplace_back(*it, 0, 0);
	}

	int currentMaxLeft = 0;
	for (auto it = barInfo.begin(); it < barInfo.end(); ++it)
	{
		it->maxLeft = currentMaxLeft;
		currentMaxLeft = max(currentMaxLeft, it->height);
	}

	int currentMaxRight = 0;
	for (auto it = barInfo.rbegin(); it < barInfo.rend(); ++it)
	{
		it->maxRight = currentMaxRight;
		currentMaxRight = max(currentMaxRight, it->height);
	}

	int capacity = 0;
	for (auto it = barInfo.begin(); it < barInfo.end(); ++it)
	{
		int lower = min(it->maxLeft, it->maxRight);
		capacity += (lower > it->height) ? lower - it->height : 0;
	}

	return capacity;
}

int main()
{
	vector<int> bars = { 3, 1, 4 };
	cout << ComputeRainWater(bars) << endl;

	vector<int> bars2 = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	cout << ComputeRainWater(bars2) << endl;

	return 0;
}

