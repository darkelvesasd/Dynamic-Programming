class Solution {
public:
 int minInsertions(string s) {
	int n = s.size();
	vector<vector<int>>v(n,vector<int>(n));
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i; j <n; j++)
		{
			if (s[i] == s[j])
			{
				if (i+1==j||i == j)
				{
					v[i][j] = 0;
				}
				else
				{
					v[i][j] = v[i + 1][j - 1];
				}
			}
			else
			{
				v[i][j] = min(v[i][j - 1] + 1, 1 + v[i + 1][j]);
			}
		}
	}
	return v[0][n - 1];
}
};
