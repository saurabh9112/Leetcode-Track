// Last updated: 8/29/2025, 7:53:37 PM
class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans = 0;
        for(int i=1;i<=n;i++){
            if(i%2 != 0){
                ans += (m/2);
            }
            else{
                ans += ceil(double(m)/double(2));
            }
        }
        return ans;
    }
};