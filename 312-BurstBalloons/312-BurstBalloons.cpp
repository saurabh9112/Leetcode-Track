// Last updated: 8/5/2025, 1:08:12 PM
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+2,vector<int> (n+2,0));
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        for(int windSize = 1;windSize<=n;windSize++){
            int left = 1;
            int right = windSize;
            while(right <= n){
                for(int i=left;i<=right;i++){
                    int ans = dp[left][i-1] + dp[i+1][right] + nums[i] * nums[left-1] * nums[right+1];
                    dp[left][right] = max(dp[left][right],ans);
                }
                right++;
                left++;
            }
        }
        return dp[1][n];
    }
};