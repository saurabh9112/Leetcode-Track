// Last updated: 8/13/2025, 5:19:18 PM
class Solution {
public:
    bool solve(int n,vector<int> powers,int index,int sum){
        if(index >= powers.size()){
            return sum == n;
        }
        if(sum == n) return true;
        if(sum > n) return false;
        return solve(n,powers,index+1,sum+powers[index]) || solve(n,powers,index+1,sum);
    }
    bool checkPowersOfThree(int n) {
        vector<int> powers;
        int i = 0;
        while(pow(3,i) <= n){
            powers.push_back(pow(3,i));
            i++;
        }
        return solve(n,powers,0,0);
    }
};