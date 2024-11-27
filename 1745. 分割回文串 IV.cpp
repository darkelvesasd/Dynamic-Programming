class Solution {
public:
bool checkPartitioning(string s) {
    int n = s.length();
    vector<vector<bool>>v(n, vector<bool>(n));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= i; j--)
        {
            if (s[i] == s[j])
            {
                if (i == j)
                {
                    v[i][j] = true;
                }
                else if (i + 1 == j)
                {
                    v[i][j] = true;
                }
                else
                {
                    v[i][j] = v[i + 1][j - 1];
                }
            }
        }
    }
    for (int i = 0; i < n-2; i++)
    {
        for (int j = n-1; j >i+1; j--)
        {
            if (v[0][i] && v[i + 1][j - 1] && v[j][n - 1])
            {
                return true;
            }
        }
    }
    return false;
}
};
