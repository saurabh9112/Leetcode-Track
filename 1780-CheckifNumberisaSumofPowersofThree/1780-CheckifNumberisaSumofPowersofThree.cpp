// Last updated: 8/13/2025, 5:31:01 PM
class Solution {
public:
    bool solve(int n,vector<int> powers,int index,int sum,vector<vector<int>> &dp){
        if(index >= powers.size()){
            return sum == n;
        }
        if(sum == n) return true;
        if(sum > n) return false;
        if(dp[index][sum] != -1) return dp[index][sum];
        return dp[index][sum] = solve(n,powers,index+1,sum+powers[index],dp) || solve(n,powers,index+1,sum,dp);
    }
    bool checkPowersOfThree(int n) {
        // vector<int> powers;
        // int i = 0;
        // while(pow(3,i) <= n){
        //     powers.push_back(pow(3,i));
        //     i++;
        // }
        // vector<vector<int>> dp(powers.size(),vector<int> (n+1,-1));
        // return solve(n,powers,0,0,dp);
        while (n > 0) {
            if (n % 3 == 2) return false; // found a '2' in base 3
            n /= 3;
        }
        return true;
    }
};