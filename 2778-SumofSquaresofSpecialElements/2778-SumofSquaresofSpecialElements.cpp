// Last updated: 10/11/2026, 9:06:11 PM
1class Solution {
2public:
3    int sumOfSquares(vector<int>& nums) {
4        int n = nums.size();
5        int ans = 0;
6        for (int i = 1; i * i <= n; ++i) {
7            if (n % i == 0) {
8                ans += nums[i - 1] * nums[i - 1];
9                if (i * i != n) {
10                    ans += nums[n / i - 1] * nums[n / i - 1];
11                }
12            }
13        }
14        return ans;
15    }
16};