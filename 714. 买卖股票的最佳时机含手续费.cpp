class Solution {
public:
int maxProfit(vector<int>& prices, int fee) {
	int n = prices.size();
	vector<vector<int>>v(n+1, vector<int>(2));
	v[0][1] = -prices[0]-fee;
	for (int i = 1; i <= n; i++)
	{
		v[i][1] = max(v[i - 1][1], v[i - 1][0] - prices[i - 1] - fee);
		v[i][0] = max(v[i - 1][0], v[i - 1][1] + prices[i - 1]);
	}
	return max(v[n][0], v[n][1]);
}
};
