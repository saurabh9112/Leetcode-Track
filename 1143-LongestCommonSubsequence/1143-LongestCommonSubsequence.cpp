// Last updated: 8/10/2025, 11:06:09 PM
class Solution {
public:
    int solve(string text1, string text2,int i,int j,vector<vector<int>> &dp){
        if(i == text1.size() || j == text2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(text1[i] == text2[j]){
            ans = 1 + solve(text1,text2,i+1,j+1,dp);
        }
        else{
            int ans1 = solve(text1,text2,i+1,j,dp);
            int ans2 = solve(text1,text2,i,j+1,dp);
            ans = max(ans1,ans2);
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    int solveTab(string a, string b){
        vector<vector<int>> dp(a.size()+1,vector<int> (b.size()+1,0));
        for(int i=a.length()-1;i>=0;i--){
            for(int j=b.length()-1;j>=0;j--){
                if(a[i] == b[j]){
                    dp[i][j] = 1+dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>> dp(text1.size(),vector<int> (text2.size(),-1));
        return solveTab(text1,text2);
    }
};