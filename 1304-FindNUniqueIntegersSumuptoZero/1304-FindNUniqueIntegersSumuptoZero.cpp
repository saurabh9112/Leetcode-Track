// Last updated: 9/7/2025, 1:43:01 PM
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        int num = n/2;
        if(n%2 != 0){
            res.push_back(0);
        }
        int cnt = 1;
        while(num--){
            res.push_back(cnt);
            res.push_back(-1*cnt);
            cnt++;
        }
        return res;
    }
};