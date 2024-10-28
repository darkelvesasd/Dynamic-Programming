class Solution {
public:
int maxProduct(vector<int>& nums) {
	int n = nums.size();
	int ret = nums[0];
	vector<vector<int>>v(2, vector<int>(n));//0max1min
	v[0][0] = v[1][0] = nums[0];
	for (int i = 1; i < n; i++)
	{
		v[0][i] = max(nums[i] * v[1][i - 1], max(nums[i], nums[i] * v[0][i - 1]));
		v[1][i] = min(nums[i] * v[0][i - 1], min(nums[i], nums[i] * v[1][i - 1]));
		ret = max(v[0][i], ret);
	}
	return ret;
}
};
