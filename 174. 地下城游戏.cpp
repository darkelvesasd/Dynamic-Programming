class Solution {
public:
int calculateMinimumHP(vector<vector<int>>& dungeon) {
	int m = dungeon.size();
	int n = dungeon[0].size();
	vector<vector<int>>v(m+1, vector<int>(n+1));
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			v[i][j] = INT_MAX;
		}
	}
	v[m][n - 1] = 1;
	for (int i = m - 1; i >= 0; i--)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			v[i][j] = min(v[i + 1][j], v[i][j + 1])-dungeon[i][j]<1?1: min(v[i + 1][j], v[i][j + 1]) - dungeon[i][j];
		}
	}
	return v[0][0];
}
};
