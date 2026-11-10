// Last updated: 11/10/2026, 4:24:30 PM
1class Solution {
2public:
3    int climbStairs(int n, vector<int>& costs) {
4        int a = 0, b = 0, c = 0;
5        for (int i = 0; i < n; ++i) {
6            int nxt = min({a + 9, b + 4, c + 1}) + costs[i];
7            a = b;
8            b = c;
9            c = nxt;
10        }
11        return c;
12    }
13};