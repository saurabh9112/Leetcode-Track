// Last updated: 11/22/2025, 11:47:56 PM
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int size = nums.size();
        vector<int> oneRem;
        vector<int> twoRem;
        int sum = 0;
        for(int i=0;i<size;i++){
            sum += nums[i];
            if(nums[i]%3 == 1){
                oneRem.push_back(nums[i]);
            }
            else if(nums[i]%3 == 2){
                twoRem.push_back(nums[i]);
            }
        }
        if(sum%3 == 0) return sum;
        int sum1 = sum,sum2 = sum;
        sort(oneRem.begin(),oneRem.end());
        sort(twoRem.begin(),twoRem.end());
        int ans;
        if(sum%3 == 1){
            if(!oneRem.empty() && twoRem.size() >= 2){
                sum1 -= oneRem[0];
                sum2 -= twoRem[0] + twoRem[1];
                ans = max(sum1,sum2);
            }
            else if(oneRem.empty()){
                sum2 -= twoRem[0] + twoRem[1];
                ans = sum2;
            }
            else{
                sum1 -= oneRem[0];
                ans = sum1;
            }
            // ans = max()
        }
        else{
            if(!twoRem.empty() && oneRem.size() >= 2){
                sum1 -= twoRem[0];
                sum2 -= oneRem[0] + oneRem[1];
                ans = max(sum1,sum2);
            }
            else if(twoRem.empty()){
                sum2 -= oneRem[0] + oneRem[1];
                ans = sum2;
            }
            else{
                sum1 -= twoRem[0];
                ans = sum1;
            }
        }
        return ans;
    }
};