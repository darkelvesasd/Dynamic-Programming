class Solution {
public:
int waysToStep(int n) {
	if (n == 1)
	{
		return 1;
	}
	if (n == 2)
	{
		return 2;
	}
	if (n == 3)
	{
		return 4;
	}
	vector<long long>v(n);
	v[0] = 1;
	v[1] = 2;
	v[2] = 4;
	for (int i = 3; i < n; i++)
	{
		v[i] = (v[i - 3]%1000000007 + v[i - 2]%1000000007 + v[i - 1]%1000000007)%1000000007;
	}
	return v[n - 1];
}
};
