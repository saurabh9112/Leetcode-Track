// Last updated: 8/23/2025, 3:48:43 PM
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k != 0) return false;
        map<int,int> mp;
        for(auto i:nums){
            mp[i]++;
        }
        while(!mp.empty()){
            int st = mp.begin()->first;
            for(int i=0;i<k;i++){
                int curr = st+i;
                if(mp[curr] == 0) return false;
                mp[curr]--;
                if(mp[curr] == 0) mp.erase(curr);
            }
        }
        return true;
        
    }
};