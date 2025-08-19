// Last updated: 8/19/2025, 11:15:09 AM
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int size = nums.size();
        int left = 0,right = 0;
        long long result = 0;
        int streak = 0;
        while(right < size){
            if(nums[right] == 0) streak++;
            else{
                result += 1LL*streak*1ll*(streak+1)/2;
                streak = 0;
            }
            right++;
        }
        result += 1LL*streak*1ll*(streak+1)/2;
        return result;
    }
};