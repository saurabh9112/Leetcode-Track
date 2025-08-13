// Last updated: 8/13/2025, 10:14:16 PM
class Solution {
public:
    int solve(int i, bool holding, vector<int>& prices, int fee, vector<vector<int>>& dp) {
        if (i == prices.size()) return 0;
        if (dp[i][holding] != -1) return dp[i][holding];

        if (holding) {
            int sell = prices[i] - fee + solve(i + 1, false, prices, fee, dp);
            int hold = solve(i + 1, true, prices, fee, dp);
            return dp[i][holding] = max(sell, hold);
        } else {
            int buy = -prices[i] + solve(i + 1, true, prices, fee, dp);
            int skip = solve(i + 1, false, prices, fee, dp);
            return dp[i][holding] = max(buy, skip);
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, false, prices, fee, dp);
    }
};
