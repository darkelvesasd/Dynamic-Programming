class Solution {
public:
int findNumberOfLIS(vector<int>& nums) {
	int n = nums.size();
	vector<int>v(n,1);
	vector<int>count(n, 1);
	int mxv = 1;
	int mxct = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = i-1; j >= 0; j--)
		{
			if (nums[j] < nums[i])
			{
				if (v[j]+1 == v[i])
				{
					count[i] += count[j];
				}
				else if (v[j] + 1 > v[i])
				{
					count[i] = count[j];
					v[i] = v[j] + 1;
				}
			}
		}
		//mxv = max(mxv, v[i]);
		if (v[i] == mxv)
		{
			mxct += count[i];
		}
		else if(v[i]>mxv)
		{
			mxct = count[i];
			mxv = v[i];
		}
	}
	return mxct;
}
};
