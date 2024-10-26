class Solution {
public:
int maxSubArray(vector<int>& nums) {
	int n = nums.size();
	vector<int>f(n+1);
	int ret = INT_MIN;
	for (int i = 1; i <= n; i++)
	{
		f[i] = max(f[i - 1] + nums[i-1], nums[i-1]);
		ret = max(ret, f[i]);
	}
	return ret;
}
};
