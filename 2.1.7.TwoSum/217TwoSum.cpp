// 217TwoSum1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

bool GetTwoSumIndex(std::vector<int> numbers, int sum, int& x, int& y)
{
	x = -1;
	y = -1;

	if (numbers.size() < 2)
		return false;

	for (int i = 0; i < numbers.size(); ++i)
	{
		for (int j = i + 1; j < numbers.size(); ++j)
		{
			if (numbers[i] + numbers[j] == sum)
			{
				x = i;
				y = j;
				return true;
			}
		}
	}

	return false;
}

std::vector<int> TwoSum(std::vector<int> nums, int target)
{
	vector<int> result = { -1,-1 };

	if (nums.size() < 2)
		return result;  // C++14: value moved.

	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = 0; j < nums.size(); ++j)
		{
			if (nums[i] + nums[j] == target)
			{
				result[0] = i;
				result[j] = j;
				return result;
			}
		}
	}

	return result;
}


// Note: it's only ok if we need the numbers instead of indice.
#include <algorithm>

vector<int> TwoSum(vector<int>& nums, int target)
{
	std::sort(nums.begin(), nums.end());

	vector<int> result = { -1, -1 };
	for (int i = 0, j = nums.size() - 1; i < j; )
	{
		int sum = nums[i] + nums[j];
		if (sum == target)
		{
			result[0] = i;
			result[1] = j;
			break;
		}
		else if (sum > target)
		{
			--j;
		}
		else
		{
			++i;
		}
	}

	return result;
}

// use hash. O(n)
#include <unordered_map>

vector<int> TwoSumHash(const vector<int>& nums, int target)
{
	unordered_map<int, int> ht;
	vector<int> result;

	for (int i = 0; i < nums.size(); ++i)
	{
		ht[nums[i]] = i;
	}

	for (int i = 0; i < nums.size(); ++i)
	{
		auto it = ht.find(target - nums[i]);
		if (it != ht.end())
		{
			result.push_back(i);
			result.push_back(it->second);
			break;
		}
	}

	return result;
}


int main()
{
	vector<int> nums = {3, 1, 5, 9, 18, 7, 6, 3, 8, 2};
	auto result = TwoSumHash(nums, 15);
	if (result.size() > 0)
	{
		cout << result[0] << ", " << result[1] << endl;
		cout << nums[result[0]] << ", " << nums[result[1]] << endl;
	}
	else
	{
		cout << "Not found." << endl;
	}

	int x = 0, y = 0;
	if (GetTwoSumIndex(nums, 15, x, y))
	{
		cout << x << ", " << y << endl;
	}
	else
	{
		cout << "Not found." << endl;
	}

    return 0;
}

