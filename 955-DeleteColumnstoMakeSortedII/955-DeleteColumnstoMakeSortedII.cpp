// Last updated: 12/21/2025, 11:34:41 AM
1class Solution {
2public:
3    int minDeletionSize(vector<string>& strs) {
4        int n = strs.size();
5        int m = strs[0].size();
6
7        // resolved[i] indicates strs[i] < strs[i+1] is finalized
8        vector<bool> resolved(n - 1, false);
9        int unresolved = n - 1;
10        int deletions = 0;
11
12        for (int col = 0; col < m && unresolved > 0; col++) {
13            bool bad = false;
14
15            // Check for lexicographical violation
16            for (int i = 0; i < n - 1; i++) {
17                if (!resolved[i] && strs[i][col] > strs[i + 1][col]) {
18                    bad = true;
19                    break;
20                }
21            }
22
23            if (bad) {
24                deletions++;
25                continue;
26            }
27
28            // Lock in strictly ordered row pairs
29            for (int i = 0; i < n - 1; i++) {
30                if (!resolved[i] && strs[i][col] < strs[i + 1][col]) {
31                    resolved[i] = true;
32                    unresolved--;
33                }
34            }
35        }
36
37        return deletions;
38    }
39};