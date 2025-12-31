// Last updated: 12/30/2025, 6:25:05 PM
1class DSU {
2    vector<int> root, size;
3
4public:
5    DSU(int n) : root(n), size(n, 1) { iota(root.begin(), root.end(), 0); }
6
7    int find(int x) {
8        if (root[x] != x)
9            root[x] = find(root[x]);
10        return root[x];
11    }
12
13    void unite(int x, int y) {
14        int rx = find(x), ry = find(y);
15        if (rx == ry)
16            return;
17        if (size[rx] > size[ry])
18            swap(rx, ry);
19        root[rx] = ry;
20        size[ry] += size[rx];
21    }
22};
23
24class Solution {
25public:
26    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
27        DSU dsu(row * col + 2);
28        vector<vector<int>> grid(row, vector<int>(col, 0));
29        int dirs[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
30                          {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
31
32        for (int i = 0; i < row * col; i++) {
33            int r = cells[i][0] - 1, c = cells[i][1] - 1;
34            grid[r][c] = 1;
35            int id1 = r * col + c + 1;
36
37            for (auto& d : dirs) {
38                int nr = r + d[0], nc = c + d[1];
39                if (nr >= 0 && nr < row && nc >= 0 && nc < col &&
40                    grid[nr][nc] == 1) {
41                    int id2 = nr * col + nc + 1;
42                    dsu.unite(id1, id2);
43                }
44            }
45
46            if (c == 0)
47                dsu.unite(0, id1);
48            if (c == col - 1)
49                dsu.unite(row * col + 1, id1);
50
51            if (dsu.find(0) == dsu.find(row * col + 1))
52                return i;
53        }
54        return -1;
55    }
56};
57