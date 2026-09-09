// Last updated: 9/9/2026, 1:32:30 PM
1class Solution {
2public:
3    long long countCommas(long long n) {
4        long long p = 1000, res = 0;
5        while (p <= n) {
6            res += n - p + 1;
7            p *= 1000;
8        }
9        return res;
10    }
11};