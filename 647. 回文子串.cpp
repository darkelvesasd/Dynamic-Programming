class Solution {
public:
 int countSubstrings(string s) {
	int n = s.length();
	int count = 0;
	vector<vector<bool>>v(n+1, vector<bool>(n+1,false));
	v[0][n - 1] = true;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = n-1; j >= i; j--)
		{
			if (s[i] == s[j])
			{
				if (i == j)
				{
					v[i][j]= true;
				}
				else if (i + 1 == j)
				{
					v[i][j]= true;
				}
				else
				{
					v[i][j] = v[i + 1][j - 1];
				}
				count += v[i][j];
			}
		}
	}
	return count;
}
};
