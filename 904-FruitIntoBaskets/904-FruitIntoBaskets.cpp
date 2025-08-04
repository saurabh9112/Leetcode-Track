// Last updated: 8/4/2025, 11:46:15 AM
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int size = fruits.size();
        unordered_map<int,int> mp;
        int l  = 0;
        int r = 0;
        int ans = 0;
        while(r < size){
            if(mp.size() <= 2){
                mp[fruits[r]]++;
            }
            else{
                if(mp.size() > 2){
                    mp[fruits[l]]--;
                    if(mp[fruits[l]] == 0) mp.erase(fruits[l]);
                    l++;
                }
            }
            if(mp.size() <= 2) {
                ans = max(ans,r-l+1);
                r++;
            }
        }
        return ans;
    }
};