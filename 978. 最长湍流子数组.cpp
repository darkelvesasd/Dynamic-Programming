class Solution {
public:
int maxTurbulenceSize(vector<int>& arr) {
	int n = arr.size();
	int cnt = 1;
	vector<vector<int>>v(2,vector<int> (n,1));//sheng0jiang1
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > arr[i - 1])
		{
			v[0][i] = v[1][i-1]+1;
			cnt = max(v[0][i], cnt);
		}
		else if(arr[i]<arr[i-1])
		{
			v[1][i] = v[0][i-1] + 1;
			cnt = max(v[1][i], cnt);
		}
	}
	return cnt;
}
};
