// Last updated: 11/2/2026, 8:40:19 AM
1class Solution {
2public:
3    int minMoves2(vector<int>& nums) {
4        auto mid = nums.begin() + nums.size() / 2;
5        ranges::nth_element(nums, mid);
6        int med = *mid, moves = 0;
7        for (int x : nums) moves += abs(x - med);
8        return moves;
9    }
10};