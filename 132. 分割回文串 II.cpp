class Solution {
public:
int minCut(string s) {
	int n = s.size();
	vector<vector<int>>vv(n, vector<int>(n));
	vector<int>dp(n,INT_MAX);
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = n - 1; j >= i; j--)
		{
			if (s[i] == s[j])
			{
				if (i == j || i + 1 == j)
				{
					vv[i][j] = true;
				}
				else
				{
					vv[i][j] = vv[i + 1][j - 1];
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (vv[0][i] == true)
		{
			dp[i] = 0;
		}
		else 
		{
			for (int j = i; j > 0; j--)
			{
				if (vv[j][i])
				{
					dp[i] = min(dp[i], dp[j-1]+1);
				}
			}
		}
	}
	return dp[n-1];
}
};
