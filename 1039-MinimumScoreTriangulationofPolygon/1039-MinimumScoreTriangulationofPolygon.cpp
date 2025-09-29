// Last updated: 9/29/2025, 7:59:25 PM
class Solution {
private:
    int solveMem(vector<int>& values,int i,int j,vector<vector<int> >& dp ){
        if(i+1 == j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = INT_MAX;
        for(int k=i+1;k<j;k++){
            ans = min(ans,values[i]*values[j]*values[k]+solveMem(values,i,k,dp)+solveMem(values,k,j,dp));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }    
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int> > dp(n,vector<int> (n,-1));
        return solveMem(values,0,n-1,dp);
        // return solveMem(values,0,n-1);
    }
};