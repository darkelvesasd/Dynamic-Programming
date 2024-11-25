class Solution {
public:
int numberOfArithmeticSlices(vector<int>& nums) 
{
	int n = nums.size();
	vector<vector<long long>>v(n,vector<long long>(n));
	unordered_map<long long, vector<int>>hash;
	hash[nums[0]].push_back(0);
	int count = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (hash.count((long long)nums[i] - nums[j]+nums[i]))
			{
				for (int k=0;k< hash[nums[i] - nums[j]+nums[i]].size();k++)
				{
					if (k < i)
						v[i][j] += v[hash[nums[i] - nums[j]+nums[i]][k]][i] + 1;
				}
				count += v[i][j];
			}
		}
		hash[nums[i]].push_back(i);
	}
	return count;
}
}; 
