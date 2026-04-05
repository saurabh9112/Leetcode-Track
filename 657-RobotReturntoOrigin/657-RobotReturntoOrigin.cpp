// Last updated: 4/5/2026, 12:38:46 PM
1class Solution {
2public:
3    bool judgeCircle(string moves) {
4        if (moves.length() & 1) return false;
5        int u = 0, d = 0, l = 0, r = 0;
6
7        for (char c : moves) {
8            u += c == 'U';
9            d += c == 'D';
10            l += c == 'L';
11            r += c == 'R';
12        }
13
14        return u == d && l == r;
15    }
16};