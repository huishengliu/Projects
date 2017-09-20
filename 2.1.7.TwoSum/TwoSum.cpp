bool GetTwoSumIndex(std::vector<int> numbers, int sum, int& x, int& y)
{
	x = -1;
	y = -1;
	
	if (numbers.size() < 2)
		return false;
	
	for (int i=0; i<numbers.size(); ++i)
	{
		for (int j=i+1; j<numbers.size(); ++j)
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

vector<int> TwoSum(vector<int> nums, int target)
{
	vector<int> result={-1,-1};
	
	if (nums.size() < 2)
		return result;  // C++14: value moved.
	
	for (int i=0; i<nums.size(); ++i)
	{
		for (int j=0; j<nums.size(); ++j)
		{
			if (nums[i]+nums[j]==target)
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

	vector<int> result[2] = {-1, -1};
	for (int i=0, j=nums.size()-1; i < j; )
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
