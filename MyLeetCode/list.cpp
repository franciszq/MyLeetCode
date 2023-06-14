#include <iostream>
#include <vector>
using namespace std;


int searchInsert(vector<int>& nums, int target) {
	if (nums.size() == 0)
	{
		return 0;
	}
	if (target <= nums[0])
	{
		return 0;
	}
	if (target == nums[nums.size() - 1])
	{
		return nums.size() - 1;
	}
	if (target > nums[nums.size() - 1])
	{
		return nums.size();
	}

	for (int i = 0; i < nums.size() - 1; ++i)
	{
		if (target == nums[i])
		{
			return i;
		}
		if (target > nums[i] && target < nums[i + 1])
		{
			return i + 1;
		}
		}
	return 0;
}


int main()
{
	vector<int> test{ 1,3,5,6 };
	int target = 5;
	searchInsert(test, 5);

	return 0;
}