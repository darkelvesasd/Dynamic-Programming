class Solution {
public:
int maxProfit(int k, vector<int>& prices) {
	int n = prices.size();
	vector<vector<int>>sell(n,vector<int>(k+1));
	vector<vector<int>>buy(n,vector<int>(k));
	int ret = 0;
	for (int i = 0; i < k; i++)
	{
		buy[0][i] = -prices[0];
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
			sell[i][1 + j] = max(sell[i - 1][j + 1], buy[i - 1][j] + prices[i]);
		}
	}
	return sell[n-1][k];
}
};
