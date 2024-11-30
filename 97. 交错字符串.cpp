class Solution {
public:
bool isInterleave(string s1, string s2, string s3) {
	int m = s1.length();
	int n = s2.length();
	if (m + n != s3.length())
	{
		return false;
	}
	vector<vector<bool>>v(m+1, vector<bool>(n+1));
	v[0][0] = true;
	for (int i = 1; i <= m; i++)
	{
		if (s1[i - 1] == s3[i - 1])
			v[i][0] = true;
		else
			break;
	}
	for (int j = 1; j <= n; j++)
	{
		if (s2[j - 1] == s3[j - 1])
			v[0][j] = true;
		else
			break;
	}
	for (int i = 1; i <=m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (s1[i - 1] == s3[i + j - 1]&&  v[i - 1][j])
			{
				v[i][j] = true;
				continue;
			}
			if (s2[j - 1] == s3[i + j - 1]&&  v[i][j-1])
			{
				v[i][j] = true;
			}
		}
	}
	return v[m][n];
}
};
