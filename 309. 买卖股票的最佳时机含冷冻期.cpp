class Solution {
public:
int maxProfit(vector<int>& prices) {
	int n = prices.size();
	vector<vector<int>>v(n+1, vector<int>(3));
	v[0][1] = -prices[0];
	for (int i = 1; i <= n; i++)
	{
		v[i][0] = max(v[i - 1][2], v[i - 1][0]);//ke
		v[i][1] = max(v[i - 1][0] - prices[i - 1], v[i - 1][1]);//mai
		v[i][2] = v[i - 1][1] + prices[i - 1];//leng
	}
	return max(v[n][0], v[n][2]);
}
};
