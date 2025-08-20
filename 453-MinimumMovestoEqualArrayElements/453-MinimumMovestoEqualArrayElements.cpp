// Last updated: 8/20/2025, 11:51:45 PM
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minNum = INT_MAX;
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            minNum = min(minNum,nums[i]);
            sum += nums[i];
        }
        return sum - minNum*n;

    }
};