// Last updated: 8/5/2025, 9:59:12 AM
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int size = baskets.size();
        unordered_map<int,int> mp;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(baskets[j] >= fruits[i] && mp.find(j) == mp.end()){
                    mp[j] = i;
                    break;
                }
            }
        }
        return size - mp.size();
    }
};