// Last updated: 1/25/2026, 10:03:14 PM
1class Solution {
2public:
3    vector<vector<int>> minimumAbsDifference(vector<int>& A) {
4        sort(A.begin(), A.end());
5        int minDiff = INT_MAX;
6        vector<vector<int>> res;
7
8        for (int i = 1; i < A.size(); i++) {
9            int diff = A[i] - A[i - 1];
10            if (diff < minDiff) {
11                minDiff = diff;
12                res.clear();
13                res.push_back({A[i - 1], A[i]});
14            } else if (diff == minDiff)
15                res.push_back({A[i - 1], A[i]});
16        }
17
18        return res;
19    }
20};
21