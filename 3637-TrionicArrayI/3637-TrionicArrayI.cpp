// Last updated: 8/6/2025, 2:03:32 PM
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int count = 0;
        bool increasing = true;
        int size = nums.size();
        if(nums[0] >= nums[1] || nums[size-2] >= nums[size-1]) return false;
        for(int i=0;i<size-1;i++){
            if(increasing){
                if(nums[i] >= nums[i+1]){
                    count++;
                    increasing = false;
                }
            }
            else{
                if(nums[i] <= nums[i+1]){
                    count++;
                    increasing = true;
                }
            }
            if(nums[i] == nums[i+1]) return false;
        }
        return count == 2;
    }
};