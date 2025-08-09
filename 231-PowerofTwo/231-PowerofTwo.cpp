// Last updated: 8/9/2025, 6:07:41 PM
class Solution {
public:
    bool solve(int n){
        if(n == 2) return true;
        if(n%2 != 0) return false;
        n /= 2;
        return solve(n);
    }
    bool isPowerOfTwo(int n) {
        if(n == 0) return false;
        if(n == 1) return true;
        return solve(n);
    }
};