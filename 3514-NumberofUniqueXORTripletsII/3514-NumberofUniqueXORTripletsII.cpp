// Last updated: 7/21/2026, 2:28:13 AM
1class Solution {
2public:
3    int uniqueXorTriplets(vector<int>& nums) {
4        int m = 0;
5        for (int v : nums) {
6            m = max(m, v);
7        }
8        int u = 1;
9        while (u <= m) {
10            u <<= 1;
11        }
12        vector<int> one(u), two(u), three(u);
13        for (int v : nums) {
14            one[v] = 1;
15            for (int x = 0; x < u; x++) {
16                if (one[x]) {
17                    two[x ^ v] = 1;
18                }
19            }
20        }
21        for (int v : nums) {
22            for (int x = 0; x < u; x++) {
23                if (two[x]) {
24                    three[x ^ v] = 1;
25                }
26            }
27        }
28        int ans = 0;
29        for (int x = 0; x < u; x++) {
30            if (three[x]) {
31                ans++;
32            }
33        }
34        return ans;
35    }
36};