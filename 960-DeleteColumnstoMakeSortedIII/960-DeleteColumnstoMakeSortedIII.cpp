// Last updated: 12/26/2025, 9:49:51 PM
1#include <vector>
2#include <string>
3#include <algorithm>
4using namespace std;
5
6class Solution {
7public:
8    int minDeletionSize(vector<string>& strs) {
9        int n = (int)strs[0].size();
10        int m = (int)strs.size();
11        vector<int> dp(n, 1);
12
13        for (int i = 1; i < n; i++) {
14            for (int j = 0; j < i; j++) {
15                bool ok = true;
16                for (int r = 0; r < m; r++) {
17                    if (strs[r][j] > strs[r][i]) { ok = false; break; }
18                }
19                if (ok) dp[i] = max(dp[i], dp[j] + 1);
20            }
21        }
22
23        int mx = 0;
24        for (int v : dp) mx = max(mx, v);
25        return n - mx;
26    }
27};