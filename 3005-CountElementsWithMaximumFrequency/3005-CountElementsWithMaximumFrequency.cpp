// Last updated: 9/22/2025, 7:58:01 PM
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i:nums){
            mp[i]++;
        }
        int maxCnt = 0;
        for(auto &pair:mp){
            maxCnt = max(maxCnt,pair.second);
        }
        int res = 0;
        for(auto &pair:mp){
            if(pair.second == maxCnt){
                res += maxCnt;
            }
        }
        return res;
    }
};