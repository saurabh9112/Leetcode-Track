// Last updated: 8/8/2025, 3:30:08 PM
class Solution {
public:
    double solve(double A, int B, vector<vector<double>> &dp) {
        int a = max(0, (int)A); // ensure indices are within bounds
        int b = max(0, B);

        if(dp[a][b] != -1.0) return dp[a][b];

        if(A <= 0 && B > 0) return dp[a][b] = 1.0;
        if(A <= 0 && B <= 0) return dp[a][b] = 0.5;
        if(A > 0 && B <= 0) return dp[a][b] = 0.0;

        dp[a][b] = 0.25 * (
            solve(A - 4, B, dp) +
            solve(A - 3, B - 1, dp) +
            solve(A - 2, B - 2, dp) +
            solve(A - 1, B - 3, dp)
        );
        return dp[a][b];
    }


    double soupServings(int n) {
        int m = int(ceil(n / 25.0));
        if(n >= 5000) return 1.0;
        vector<vector<double>> dp(m + 1, vector<double>(m + 1, -1.0));
        return solve(m, m, dp);
    }
};