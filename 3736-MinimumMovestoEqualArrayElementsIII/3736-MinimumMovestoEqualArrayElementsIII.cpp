// Last updated: 11/2/2026, 8:38:39 AM
1class Solution {
2public:
3    int minMoves(vector<int>& nums) {
4        int size = nums.size();
5        int maxNum = INT_MIN;
6        for(int i=0;i<size;i++){
7            maxNum = max(maxNum,nums[i]);
8        }
9        int ans = 0;
10        for(int i=0;i<size;i++){
11            ans += (maxNum - nums[i]);
12        }
13        return ans;
14    }
15};