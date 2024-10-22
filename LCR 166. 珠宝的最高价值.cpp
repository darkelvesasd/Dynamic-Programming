class Solution {
public:
int jewelleryValue(vector<vector<int>>& frame) {
	int m = frame.size();
	int n = frame[0].size();
	vector<vector<int>>v(m+1,vector<int>(n+1));
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			v[i][j] = max(v[i - 1][j] , v[i][j - 1])+frame[i-1][j-1];
		}
	}
	return v[m][n];
}
};
