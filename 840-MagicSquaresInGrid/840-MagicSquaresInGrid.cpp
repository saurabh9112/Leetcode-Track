// Last updated: 12/30/2025, 1:42:42 PM
1class Solution {
2public:
3    int numMagicSquaresInside(vector<vector<int>>& grid) {
4        int ans = 0;
5        int m = grid.size();
6        int n = grid[0].size();
7        for (int row = 0; row + 2 < m; row++) {
8            for (int col = 0; col + 2 < n; col++) {
9                if (isMagicSquare(grid, row, col)) {
10                    ans++;
11                }
12            }
13        }
14        return ans;
15    }
16
17private:
18    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
19        // The sequences are each repeated twice to account for
20        // the different possible starting points of the sequence
21        // in the magic square
22        string sequence = "2943816729438167";
23        string sequenceReversed = "7618349276183492";
24
25        string border = "";
26        // Flattened indices for bordering elements of 3x3 grid
27        vector<int> borderIndices = {0, 1, 2, 5, 8, 7, 6, 3};
28        for (int i : borderIndices) {
29            int num = grid[row + i / 3][col + (i % 3)];
30            border += to_string(num);
31        }
32
33        // Make sure the sequence starts at one of the corners
34        return (grid[row][col] % 2 == 0 && grid[row + 1][col + 1] == 5 &&
35                (sequence.find(border) != string::npos ||
36                 sequenceReversed.find(border) != string::npos));
37    }
38};