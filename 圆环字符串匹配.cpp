#include <iostream>
#include <vector>
#include <unordered_map>
//#include <climits>
#include <string>
using namespace std;
int fun(string s1, string s2)
{
    int m = s1.length();//环
    int n = s2.length();
    unordered_map<char, vector<int>>hash;
    for (int i = 0; i < m; i++)
    {
        hash[s1[i]].emplace_back(i);
    }
    vector<int>pre(m, INT_MAX);
    pre[0] = 0;
    for (char a : s2)
    {
        vector<int>cur(m, INT_MAX);
        for (int b : hash[a])
        {
            for (int i = 0; i < m; i++)
            {
                if (pre[i] == INT_MAX) continue;
                int t = abs(b - i);
                int tt = min(m - t, t);
                cur[b] = min(pre[i] + tt, cur[b]);  
            }
        }
        pre = cur;
    }
    int mx = INT_MAX;
    for (auto a : pre)
    {
        mx = min(mx, a);
    }
    return mx + n;
}
int main()
{
    cout << fun("abcde", "cde");
}
