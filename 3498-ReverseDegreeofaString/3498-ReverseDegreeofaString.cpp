// Last updated: 9/20/2026, 2:33:25 PM
1class Solution {
2public:
3    int reverseDegree(string s) {
4        int ans = 0;
5        for (int i = 1; i <= s.size(); i++) {
6            ans += (26 - (s[i - 1] - 'a')) * i;
7        }
8        return ans;
9    }
10};