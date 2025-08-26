// Last updated: 8/26/2025, 8:21:00 PM
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int res = INT_MIN;
        double maxDig = 0;
        for(int i=0;i<n;i++){
            int len = dimensions[i][0];
            int bdh = dimensions[i][1];
            double dig = sqrt(pow(len,2)+pow(bdh,2));
            if(dig > maxDig){
                maxDig = dig;
                res = len*bdh;
            }
            else if(dig == maxDig){
                res = max(res,len*bdh);
            }
        }
        return res;
    }
};