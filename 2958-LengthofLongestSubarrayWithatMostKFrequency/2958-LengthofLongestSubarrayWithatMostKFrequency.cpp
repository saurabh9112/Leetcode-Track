// Last updated: 8/12/2026, 4:26:20 AM
1class Solution {
2public:
3    int maxSubarrayLength(vector<int>& nums, int k) {
4        int ans = 0, start = -1;
5        unordered_map<int, int> frequency;
6        
7        for (int end = 0; end < nums.size(); end++) {
8            frequency[nums[end]]++;
9            while (frequency[nums[end]] > k) {
10                start++;
11                frequency[nums[start]]--;
12            }
13            ans = max(ans, end - start);
14        }
15        
16        return ans;
17    }
18};