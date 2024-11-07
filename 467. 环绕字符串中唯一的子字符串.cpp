class Solution {
public:
int findSubstringInWraproundString(string s) {
	int n = s.length();
	vector<int>v(n+1,1);
	unordered_map<char, int>hash;
	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i!=1&&(s[i - 2] == s[i-1] - 1 || s[i-1] == 'a' && s[i - 2] == 'z'))
		{
			v[i] = v[i - 1] + 1;
		}
		hash[s[i - 1]] = max(hash[s[i - 1]], v[i]);
	}
	for (auto a : hash)
	{
		ret += a.second;
	}
	return ret;
}
};
