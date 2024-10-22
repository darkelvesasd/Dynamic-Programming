class Solution {
public:
int minFallingPathSum(vector<vector<int>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	int ret = INT_MAX;
	vector<vector<int>>v(m+1, vector<int>(n+2));
	for (int i = 1; i <= m; i++)
	{
		v[i][0] = v[i][n + 1] = INT_MAX;
	}
	for (int i = 0; i < n + 2; i++)
	{
		v[0][i] = 0;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			v[i][j] = matrix[i - 1][j - 1] + min(min(v[i - 1][j - 1], v[i - 1][j]), v[i - 1][j + 1]);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		ret = min(v[m][i], ret);
	}
	return ret;
}
};
