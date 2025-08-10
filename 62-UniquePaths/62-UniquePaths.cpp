// Last updated: 8/10/2025, 11:05:46 PM
class Solution {
public:
    int solve(int row,int col,int m,int n,vector<vector<int>> &dp){
        if(row == m-1 && col == n-1) return 1;
        if(dp[row][col] != -1) return dp[row][col];
        if(row == m-1) return solve(row,col+1,m,n,dp);
        if(col == n-1) return solve(row+1,col,m,n,dp);
        int right = solve(row,col+1,m,n,dp); //going right
        int down = solve(row+1,col,m,n,dp); // going down
        dp[row][col] = right+down;
        return right+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solve(0,0,m,n,dp);
    }
};