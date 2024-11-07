class Solution {
public:
int lengthOfLIS(vector<int>& nums) {
	int ret = 1;
	int n = nums.size();
	vector<int>v(n,1);
	for (int i=1;i<n;i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if (nums[i] > nums[j])
			{
				v[i] = max(v[j] + 1,v[i]);
				ret = max(ret, v[i]);
			}
		}
	}
	return ret;
}
};
