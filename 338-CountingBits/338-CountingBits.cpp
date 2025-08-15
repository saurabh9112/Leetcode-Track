// Last updated: 8/15/2025, 10:22:52 PM
class Solution {
public:
    int findOnes(int num){
        int cnt = 0;
        while(num > 0){
            if(num%2 != 0) cnt++;
            num/=2;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> result;;
        for(int i=0;i<=n;i++){
            result.push_back(findOnes(i));
        }
        return result;
    }
};