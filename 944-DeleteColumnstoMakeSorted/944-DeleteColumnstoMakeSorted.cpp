// Last updated: 12/20/2025, 2:37:40 PM
1class Solution {
2    bool isUnsorted(const vector<string>& strs, int j) {
3        for (int i = 1; i < strs.size(); i++)
4            if (strs[i][j] < strs[i - 1][j])
5                return true;
6        return false;
7    }
8
9public:
10    int minDeletionSize(vector<string>& strs) {
11        int res = 0;
12        for (int j = 0; j < strs[0].size(); j++)
13            res += isUnsorted(strs, j);
14        return res;
15    }
16};
17