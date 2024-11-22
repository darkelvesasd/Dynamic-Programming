class Solution {
public:
int longestArithSeqLength(vector<int>& nums) {
	unordered_map<int, int>hash;
	int n = nums.size();
	int ret = 2;
	vector<vector<int>>v(n, vector<int>(n,2));
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (hash.count(2 * nums[i] - nums[j]))
			{
				v[i][j] = max(v[i][j], v[hash[2 * nums[i] - nums[j]]][i]+1);
				ret = max(ret, v[i][j]);
			}
		} 
		hash[nums[i]] = i;
	}
	return ret;
}
};
