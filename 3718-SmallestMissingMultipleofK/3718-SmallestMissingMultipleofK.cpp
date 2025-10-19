// Last updated: 10/19/2025, 6:23:16 PM
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto i:nums){
            if(i%k == 0){
                mp[i/k] = 1;
            }
        }
        int ans = 100000;
        for(int i=1;i<=10000;i++){
            if(mp[i] == 0){
                ans = i*k;
                break;
            }
        }
        return ans;
    }
};