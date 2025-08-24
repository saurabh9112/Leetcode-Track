// Last updated: 8/24/2025, 10:42:24 AM
class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int n = a.size();
        int res = 0,prevOneCnt = 0,currOneCnt = 0;;
        bool firstZero = false;
        for(int i=0;i<n;i++){
            if(a[i] == 1){
                currOneCnt++;
            }
            else{
                res = max(res,prevOneCnt+currOneCnt);
                prevOneCnt = currOneCnt;
                currOneCnt = 0;
            }
        }
        res = max(res,prevOneCnt+currOneCnt);
        if(res == n) return n-1;
        return res;
    }
};