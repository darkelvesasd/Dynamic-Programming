class Solution {
public:
int wiggleMaxLength(vector<int>& nums) {
	int n = nums.size();
	int mx = 1;
	vector<vector<int>>v(2,vector<int>(n,1));
	for (int i = 1; i < n; i++)
	{
		for (int j = i-1; j >= 0; j--)
		{
			if (nums[i] > nums[j])
			{
				v[1][i] = max(v[1][i], 1+v[0][j]);
				mx = max(v[1][i], mx);
			}
			else if (nums[i] < nums[j])
			{
				v[0][i] = max(1+v[1][j], v[0][i]);
				mx = max(v[0][i], mx);
			}
		}
	}
	return mx;
}
};
