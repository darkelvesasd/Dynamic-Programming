class Solution {
public:
int maxSubarraySumCircular(vector<int>& nums) {
	int n = nums.size();
	int mn = INT_MAX;
	int mx = INT_MIN;
	vector<int>v(n + 1);
	vector<int>v1(n + 1);
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		v[i] = min(v[i - 1], 0) + nums[i-1];
		v1[i] = max(v1[i - 1] + nums[i - 1], nums[i - 1]) ;
		mx = max(mx, v1[i]);
		mn = min(mn, v[i]);
		sum += nums[i - 1];
	}
	if (mn == sum)
	{
		return mx;
	}
	return max(sum - mn,mx);
}
};
