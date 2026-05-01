// Last updated: 5/1/2026, 5:19:12 PM
1class Solution {
2public:
3    int maxRotateFunction(vector<int>& nums) {
4        int f = 0, n = nums.size();
5        int numSum = accumulate(nums.begin(), nums.end(), 0);
6        for (int i = 0; i < n; i++) {
7            f += i * nums[i];
8        }
9        int res = f;
10        for (int i = n - 1; i > 0; i--) {
11            f += numSum - n * nums[i];
12            res = max(res, f);
13        }
14        return res;
15    }
16};