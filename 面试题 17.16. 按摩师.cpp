class Solution {
public:
int massage(vector<int>& nums) {
	int n = nums.size();
	vector<int>f(1 + n);
	vector<int>g(1 + n);
	for (int i = 1; i <= n; i++)
	{
		f[i] = g[i - 1]+nums[i-1];
		g[i] = max(g[i - 1], f[i - 1]);
	}
	return max(f[n], g[n]);
}
};
