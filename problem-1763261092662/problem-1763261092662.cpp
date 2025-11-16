// Last updated: 11/16/2025, 8:14:52 AM
class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int ans = INT_MIN;
        int size = nums.size();
        sort(nums.begin(),nums.end());
        int a = nums[size-1];
        int b = nums[size-2];
        int c = nums[0];
        return a+b-c;
    }
};