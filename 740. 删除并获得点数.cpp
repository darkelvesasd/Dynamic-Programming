class Solution {
public:
int deleteAndEarn(vector<int>& nums) {
	vector<int>v(10001);
	vector<int>f(10001);//0
	vector<int>g(10001);//1
	for (auto a : nums)
	{
		v[a] += a;
	}
	for (int i = 1; i <= 10000; i++)
	{
		g[i] = max(f[i - 1], g[i - 1]);
		f[i] = g[i - 1] + v[i];
	}
	return max(f[10000], g[10000]);
}
};
