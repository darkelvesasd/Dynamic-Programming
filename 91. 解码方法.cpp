class Solution {
public:
int numDecodings(string s) {
	if (s[0] == '0')
	{
		return 0;
	}
	int n = s.length();
	vector<int>v(n+1);
	v[0]=v[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (s[i-1] != '0')
		{
			v[i] += v[i - 1];
		}
		if (10 * (s[i - 2] - '0') + s[i-1]-'0' <= 26 && 10 * (s[i - 2] - '0') + s[i - 1]-'0' > 0&& s[i-2]!='0')
		{
			v[i] += v[i - 2];
		}
	}
	return v[n];
}
};
