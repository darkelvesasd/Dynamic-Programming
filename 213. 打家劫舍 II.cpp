class Solution {
public:
    int n;
    int r(int begin, int end, vector<int>& nums) {
        vector<int> f(n + 1); // 0
        vector<int> g(n + 1); // 1
        for (int i = begin; i <= end; i++) {
            g[i] = max(g[i - 1], f[i - 1]);
            f[i] = g[i - 1] + nums[i];
        }
        return max(f[end], g[end]);
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        return max(nums[0] + r(2, n - 2, nums), r(1, n - 1, nums));
    }
};
