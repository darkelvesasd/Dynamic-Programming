class Solution {
public:
int getMaxLen(vector<int>& nums) {
	int n = nums.size();
	int ret = 0;
	vector<vector<int>>v(2, vector<int>(n+1));//-1 1
	for (int i = 1; i <= n; i++)
	{
		if (nums[i-1] > 0)
		{
			v[1][i] = v[1][i - 1] + 1;
			v[0][i]=v[0][i-1] ==0?0: v[0][i - 1] + 1;
			ret = max(v[1][i], ret);
		}
		else if (nums[i-1] < 0)
		{
			v[0][i] = v[1][i - 1] + 1;
			v[1][i]=v[0][i-1] ==0?0: v[0][i - 1] + 1;
			ret = max(v[1][i], ret);
		}
	}
	return ret;
}
};
