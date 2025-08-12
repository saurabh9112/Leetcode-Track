// Last updated: 8/12/2025, 11:18:00 AM
// #define MOD 1000000000+7
class Solution {
public:
    const int MOD = 1e9 + 7;
    int solve(int n,vector<long long> &powers,int i,int sum,vector<vector<int>> &dp){
        if(i == powers.size()){
            if(sum == n) return 1;
            else return 0;
        } 
        if(sum == n) return 1;
        if(sum > n) return 0;
        if(dp[i][sum] != -1) return dp[i][sum];
        long long ans1 = 0,ans2 = 0;
        ans1 = solve(n,powers,i+1,sum+powers[i],dp)%MOD;
        ans2 = solve(n,powers,i+1,sum,dp)%MOD;
        return dp[i][sum]=(ans1+ans2)%MOD;
    }
    int numberOfWays(int n, int x) {
        vector<long long> powers;
        for(int i=1;i<=n;i++){
            if(pow(i,x) <= n){
                powers.push_back(pow(i,x));
            }
            else{
                break;
            }
        }
        long long sum = 0;
        vector<vector<int>> dp(powers.size(),vector<int> (n+1,-1));
        return solve(n,powers,0,sum,dp);
    }
};