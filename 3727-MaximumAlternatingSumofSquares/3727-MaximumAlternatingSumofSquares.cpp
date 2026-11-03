// Last updated: 11/2/2026, 8:44:11 AM
1class Solution {
2public:
3    long long maxAlternatingSum(vector<int>& nums) {
4        int n = nums.size();
5        for (auto& num : nums) {
6            num *= num;
7        }
8        ranges::sort(nums);
9        return -accumulate(nums.begin(), nums.begin() + n / 2, 0LL) +
10               accumulate(nums.begin() + n / 2, nums.end(), 0LL);
11    }
12};