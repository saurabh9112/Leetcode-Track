// Last updated: 5/10/2026, 2:07:42 PM
1class Solution {
2public:
3    int maximumJumps(vector<int>& nums, int target) {
4        int n = nums.size();
5        vector<int> memo(n, INT_MIN);
6
7        function<int(int)> dfs = [&](int i) -> int {
8            if (i == n - 1) {
9                return 0;
10            }
11            if (memo[i] != INT_MIN) {
12                return memo[i];
13            }
14            int res = INT_MIN;
15            for (int j = i + 1; j < n; j++) {
16                if (abs(nums[i] - nums[j]) <= target) {
17                    res = max(res, dfs(j) + 1);
18                }
19            }
20            return memo[i] = res;
21        };
22
23        int ans = dfs(0);
24        return ans < 0 ? -1 : ans;
25    }
26};