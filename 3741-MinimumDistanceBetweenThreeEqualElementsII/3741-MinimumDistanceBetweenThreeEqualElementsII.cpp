// Last updated: 4/11/2026, 2:44:53 PM
1class Solution {
2public:
3    int minimumDistance(vector<int>& nums) {
4        int n = nums.size();
5        std::vector<int> next(n, -1);
6        std::unordered_map<int, int> occur;
7        int ans = n + 1;
8
9        for (int i = n - 1; i >= 0; i--) {
10            if (occur.count(nums[i])) {
11                next[i] = occur[nums[i]];
12            }
13            occur[nums[i]] = i;
14        }
15
16        for (int i = 0; i < n; i++) {
17            int secondPos = next[i];
18            if (secondPos != -1) {
19                int thirdPos = next[secondPos];
20                if (thirdPos != -1) {
21                    ans = std::min(ans, thirdPos - i);
22                }
23            }
24        }
25
26        return ans == n + 1 ? -1 : ans * 2;
27    }
28};