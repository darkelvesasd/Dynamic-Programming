class Solution {
public:
int longestPalindromeSubseq(string s) {
	int n = s.size();
	vector<vector<int>>vv(n, vector<int>(n));
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i; j <= n - 1; j++)
		{
			if (s[i] == s[j])
			{
				if (i == j)
				{
					vv[i][j] = 1;
				}
				else if (i + 1 == j)
				{
					vv[i][j] = 2;
				}
				else
				{
					vv[i][j] = vv[i + 1][j - 1] + 2;
				}
			}
			else
			{
				vv[i][j] = max(vv[i + 1][j], vv[i][ j - 1]);
			}
		}
	}
	return vv[0][n-1];
}
};
