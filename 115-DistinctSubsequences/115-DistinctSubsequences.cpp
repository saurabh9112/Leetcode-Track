// Last updated: 9/6/2026, 9:12:33 PM
1class Solution {
2public:
3    int numDistinct(string s, string t) {
4        int m = s.length(), n = t.length();
5        if (m < n) {
6            return 0;
7        }
8        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1));
9        for (int i = 0; i <= m; i++) {
10            dp[i][n] = 1;
11        }
12        for (int i = m - 1; i >= 0; i--) {
13            char sChar = s.at(i);
14            for (int j = n - 1; j >= 0; j--) {
15                char tChar = t.at(j);
16                if (sChar == tChar) {
17                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
18                } else {
19                    dp[i][j] = dp[i + 1][j];
20                }
21            }
22        }
23        return dp[0][0];
24    }
25};