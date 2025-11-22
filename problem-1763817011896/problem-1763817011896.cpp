// Last updated: 11/22/2025, 6:40:11 PM
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int size = nums.size();
        int ans = 0;
        for(int i=0;i<size;i++){
            if(nums[i]%3 != 0) ans++;
        }
        return ans;
        
    }
};