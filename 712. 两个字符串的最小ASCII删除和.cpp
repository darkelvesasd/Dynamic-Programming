class Solution {
public:
int minimumDeleteSum(string s1, string s2) {
	int m = s1.length();
	int n = s2.length();
	int sum = 0;
	for (auto a : s1)
	{
		sum += a;
	}
	for (auto a : s2)
	{
		sum += a;
	}
	vector<vector<int>>v(m+1, vector<int>(n+1));
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				v[i][j] = v[i - 1][j - 1]+s1[i-1];
			}
			else
			{
				v[i][j] = max(v[i - 1][j], v[i][j - 1]);
			}
		}
	}
	return sum - 2 * v[m][n];
}
};
