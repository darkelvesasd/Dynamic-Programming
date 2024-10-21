class Solution {
public:
int minCostClimbingStairs(vector<int>& cost) {
	int n = cost.size();
	vector<int>v(n+1);
	v[1] = cost[0];
	for (int i = 2; i <= n; i++)
	{
		v[i] = min(v[i - 2], v[i - 1]) + cost[i - 1];
	}
	return min(v[n], v[n - 1]);
}
};
