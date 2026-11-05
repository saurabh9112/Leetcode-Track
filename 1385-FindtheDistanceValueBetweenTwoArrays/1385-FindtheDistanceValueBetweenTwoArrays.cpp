// Last updated: 11/5/2026, 7:43:15 AM
1class Solution {
2public:
3    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
4        int cnt = 0;
5        for (auto& x : arr1) {
6            bool ok = true;
7            for (auto& y : arr2) {
8                ok &= (abs(x - y) > d);
9            }
10            cnt += ok;
11        }
12        return cnt;
13    }
14};