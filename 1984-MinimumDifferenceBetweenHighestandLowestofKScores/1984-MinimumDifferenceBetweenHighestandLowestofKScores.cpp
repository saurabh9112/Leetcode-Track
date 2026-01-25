// Last updated: 1/24/2026, 10:33:05 PM
1class Solution {
2public:
3    int minimumDifference(vector<int>& nums, int k) {
4        sort(nums.begin(),nums.end());
5        int size = nums.size();
6        if(k == 1) return 0;
7        int ans =  INT_MAX;
8        ans = nums[k-1] - nums[0];
9        for(int i=1;i<=size-k;i++){
10            ans = min(ans,nums[i+k-1]-nums[i]);
11        }
12        return ans;
13    }
14};