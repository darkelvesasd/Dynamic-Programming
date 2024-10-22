class Solution {
public:
int minPathSum(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>>v(m+1, vector<int>(n+1));
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			v[i][j] = INT_MAX;
		}
	}
	v[0][1] = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			v[i][j] = min(v[i - 1][j], v[i][j - 1]) + grid[i - 1][j - 1];
		}
	}
	return v[m][n];
}
};
