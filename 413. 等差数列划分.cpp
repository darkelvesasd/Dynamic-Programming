class Solution {
public:
int numberOfArithmeticSlices(vector<int>& nums) {
	int n = nums.size();
	int ret = 0;
	vector<int>v(n);
	if (n <= 2)
	{
		return 0;
	}
	for (int i = 2; i < n; i++)
	{
		if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
		{
			v[i] = v[i - 1] + 1;
			ret += v[i];
		}
	}
	return ret;
}
};
