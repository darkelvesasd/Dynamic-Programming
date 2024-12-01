class Solution {
public:
int findLength(vector<int>& nums1, vector<int>& nums2) {
	int m = nums1.size();
	int n = nums2.size();
	int mx = 0;
	vector<vector<int>>v(m + 1, vector<int>(n + 1));
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (nums1[i-1] == nums2[j-1])
			{
				v[i][j] = v[i - 1][j - 1]+1;
				mx = max(mx, v[i][j]);
			}
		}
	}
	return mx;
}
};
