// Last updated: 2/22/2026, 10:59:05 PM
1class Solution {
2public:
3    int binaryGap(int n) {
4        n >>= __builtin_ctz(n);
5        if (n == 1) return 0;
6        int maxGap = 0, gap = 0;
7
8        while (n) {
9            if (n & 1) {
10                maxGap = max(maxGap, gap);
11                gap = 0;
12            } else
13                gap++;
14            n >>= 1;
15        }
16
17        return maxGap + 1;
18    }
19};