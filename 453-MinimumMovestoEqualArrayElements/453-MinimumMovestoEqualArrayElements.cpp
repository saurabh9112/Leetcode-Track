// Last updated: 11/2/2026, 12:09:47 AM
1class Solution {
2public:
3    int minMoves(vector<int>& nums) {
4        return accumulate(nums.begin(), nums.end(), 0ll) - (nums.size() * ranges::min(nums));
5    }
6};