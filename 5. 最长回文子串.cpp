class Solution {
public:
string longestPalindrome(string s) {
    int n = s.length();
    int ret = 1;
    vector<int>r(2);
    r[0] = 0;
    r[1] = 0;
    vector<vector<bool>>v(n, vector<bool>(n));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n-1; j >= i; j--)
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
            if (v[i][j]&&ret<j-i+1)
            {
                ret =  j - i + 1;
                r[0] = i;
                r[1] = j;
            }
        }
    }
    return s.substr(r[0], r[1]-r[0] + 1);
}
};
