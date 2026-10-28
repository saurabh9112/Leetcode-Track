// Last updated: 10/28/2026, 10:47:34 PM
1class Solution {
2public:
3    int minCost(vector<vector<int>>& grid) {
4        const int m = grid.size();
5        const int n = grid[0].size();
6
7        vector<array<bool, 1024>> dp(n);
8        array<bool, 1024> next{};
9
10        dp[0][grid[0][0]] = true;
11
12        for (int i = 0; i < m; i++) {
13            for (int j = 0; j < n; j++) {
14                if (i == 0 && j == 0) {
15                    continue;
16                }
17
18                const int value = grid[i][j];
19                next.fill(false);
20
21                for (int k = 0; k < 1024; k++) {
22                    if (dp[j][k] || (j > 0 && dp[j - 1][k])) {
23                        next[k ^ value] = true;
24                    }
25                }
26
27                dp[j] = next;
28            }
29        }
30
31        for (int k = 0; k < 1024; k++) {
32            if (dp[n - 1][k]) {
33                return k;
34            }
35        }
36
37        return -1;
38    }
39};