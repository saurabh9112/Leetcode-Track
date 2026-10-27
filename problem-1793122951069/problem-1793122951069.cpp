// Last updated: 10/27/2026, 11:12:31 PM
1class Solution {
2public:
3    vector<string> createGrid(int m, int n) {
4        vector<string> grid(m);
5        grid[0] = string(n, '.');
6        string row = string(n - 1, '#') + '.';
7        for (int i = 1; i < m; i++) {
8            grid[i] = row;
9        }
10        return grid;
11    }
12};