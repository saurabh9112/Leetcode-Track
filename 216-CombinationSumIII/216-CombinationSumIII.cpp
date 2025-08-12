// Last updated: 8/12/2025, 8:07:47 PM
class Solution {
public:
    void solve(int k,int n,vector<vector<int>> &ans,vector<int> curr,int currNum,int sum){
        if(currNum > 9 || k <= 0){
            return;
        }
        if(currNum + sum <= n && k > 0){
            sum += currNum;
            k--;
            curr.push_back(currNum);
            if(sum == n && k == 0){
                ans.push_back(curr);
            }
            if(sum < n && k > 0) solve(k,n,ans,curr,currNum+1,sum);
            curr.pop_back();
            sum -= currNum;
            k++;
            solve(k,n,ans,curr,currNum+1,sum);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(k,n,ans,curr,1,0);
        return ans;
    }
};