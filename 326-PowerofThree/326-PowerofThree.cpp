// Last updated: 8/13/2025, 3:16:42 PM
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        double div = log(n) / log(3);
        return fabs(div - round(div)) < 1e-10;
    }
};