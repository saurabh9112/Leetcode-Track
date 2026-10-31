// Last updated: 10/31/2026, 3:34:50 PM
1class Solution {
2public:
3    int uniquePaths(vector<vector<int>>& grid) {
4        constexpr int MOD = 1'000'000'007;
5
6        int m = grid.size();
7        int n = grid[0].size();
8
9        // f[i][j][0]: enter (i, j) by moving down
10        // f[i][j][1]: enter (i, j) by moving right
11        vector<vector<array<long long, 2>>> f(
12            m, vector<array<long long, 2>>(n, {0, 0}));
13
14        f[0][0][0] = 1;
15
16        for (int i = 0; i < m; ++i) {
17            for (int j = 0; j < n; ++j) {
18                if (i > 0) {
19                    if (grid[i - 1][j] == 0) {
20                        f[i][j][0] = (f[i - 1][j][0] + f[i - 1][j][1]) % MOD;
21                    } else {
22                        f[i][j][0] = f[i - 1][j][1];
23                    }
24                }
25
26                if (j > 0) {
27                    if (grid[i][j - 1] == 0) {
28                        f[i][j][1] = (f[i][j - 1][0] + f[i][j - 1][1]) % MOD;
29                    } else {
30                        f[i][j][1] = f[i][j - 1][0];
31                    }
32                }
33            }
34        }
35
36        return (f[m - 1][n - 1][0] + f[m - 1][n - 1][1]) % MOD;
37    }
38};