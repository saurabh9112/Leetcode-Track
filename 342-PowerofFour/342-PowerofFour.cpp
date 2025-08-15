// Last updated: 8/15/2025, 12:22:14 PM
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return 0;
        while(n > 0){
            if(n == 1) return 1;
            if(n%4 == 3) return 0;
            if(n%4 == 2) return 0;
            if(n%4 == 1) return 0;
            n /= 4;
        }
        return true;
    }
};