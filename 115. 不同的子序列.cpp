class Solution {
public:
  int numDistinct(string s, string t) {
	int m = s.length();
	int n = t.length();
	vector<vector<long long>>v(m + 1, vector<long long>(n + 1));
	for (int i = 0; i <= m; i++)
	{
		v[i][0] = 1;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (s[i-1] == t[j-1])
			{
				v[i][j] = v[i - 1][j - 1];
			}
			v[i][j] += (v[i - 1][j])%(1000000009 );
		}
	}
	return v[m][n];
};
};
