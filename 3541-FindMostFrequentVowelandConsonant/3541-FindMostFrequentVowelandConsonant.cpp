// Last updated: 9/13/2025, 9:19:55 PM
class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<int,int> mp;
        for(auto i:s){
            mp[i]++;
        }
        int vowelMaxFreq = 0;
        int consMaxFreq = 0;
        for(auto &pair:mp){
            char ch = pair.first;
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                vowelMaxFreq = max(vowelMaxFreq,pair.second);
            }
            else{
                consMaxFreq = max(consMaxFreq,pair.second);
            }
        }
        return vowelMaxFreq + consMaxFreq;
    }
};