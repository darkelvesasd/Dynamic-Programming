class Solution {
public:
int longestSubsequence(vector<int>& arr, int difference) {
	int n = arr.size();
	int ret = 1;
	unordered_map<int, int>hash;
	hash[arr[0]] = 1;
	for (int i = 1; i < n; i++)
	{
			hash[arr[i]] = hash[arr[i] - difference]+1;
			ret = max(ret, hash[arr[i]]);
	}
	return ret;
}
};
