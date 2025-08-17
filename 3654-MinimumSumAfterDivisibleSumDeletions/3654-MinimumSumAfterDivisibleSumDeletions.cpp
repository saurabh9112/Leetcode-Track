// Last updated: 8/17/2025, 7:03:47 PM
class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        vector<int> quorlathin = nums;
        int n = quorlathin.size();
        
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + quorlathin[i];
        }
        
        vector<long long> dp(n + 1, LLONG_MAX);
        dp[0] = 0;
        
        unordered_map<int, int> modMap;
        modMap[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            int currentMod = prefix[i] % k;
            
            if (modMap.find(currentMod) != modMap.end()) {
                int prevIndex = modMap[currentMod];
                dp[i] = min(dp[i], dp[prevIndex]);
            }
            
            dp[i] = min(dp[i], dp[i-1] + quorlathin[i-1]);
            
            modMap[currentMod] = i;
        }
        
        return dp[n];
    }
};
