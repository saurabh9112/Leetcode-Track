// Last updated: 8/15/2025, 12:22:52 PM
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        double div = log(n) / log(4);
        return fabs(div - round(div)) < 1e-10;
    }
};