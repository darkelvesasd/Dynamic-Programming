class Solution {
public:
int minCost(vector<vector<int>>& costs) {
	int n = costs.size();
	vector<int>f(n+1);
	auto g = f;
	auto h = g;
	for (int i = 1; i <= n; i++)
	{
		f[i] = min(g[i - 1], h[i - 1])+costs[i-1][0];
		g[i] = min(f[i - 1], h[i - 1])+costs[i-1][1];
		h[i] = min(f[i - 1], g[i - 1])+costs[i-1][2];
	}
	return min(min(f[n], g[n]), h[n]);
}
};
