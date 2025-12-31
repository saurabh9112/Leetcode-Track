// Last updated: 12/31/2025, 9:46:22 PM
1class Solution {
2public:
3    int divide(int dividend, int divisor) {
4        if (dividend == divisor) return 1;
5        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
6        if (divisor == 1) return dividend;
7        
8        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
9        
10        long long n = abs((long long)dividend);
11        long long d = abs((long long)divisor);
12        int ans = 0;
13
14        while (n >= d) {
15            int p = 0;
16            while (n >= (d << p)) p++;
17            p--;
18            n -= (d << p);
19            ans += (1 << p);
20        }
21
22        return sign * ans;
23    }
24};