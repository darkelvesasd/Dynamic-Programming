class Solution {
public:
int findLongestChain(vector<vector<int>>& pairs) {
	int n = pairs.size();
	int mx = 1;
	sort(pairs.begin(), pairs.end());
	vector<int>v(n,1);
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if (pairs[j][1] < pairs[i][0])
			{
				v[i] = max(v[i], v[j]+1);
				mx = max(mx, v[i]);
			}
		}
	}
	return mx;
}
};
