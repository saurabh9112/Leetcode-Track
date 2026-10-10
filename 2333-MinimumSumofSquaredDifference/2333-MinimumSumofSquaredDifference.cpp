// Last updated: 10/4/2026, 6:31:54 AM
1class Solution {
2public:
3    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
4                               int k2) {
5        long long k = (long long)k1 + k2;
6        int n = nums1.size();
7        for (int i = 0; i < n; i++) {
8            nums1[i] = abs(nums1[i] - nums2[i]);
9        }
10        if (accumulate(nums1.begin(), nums1.end(), 0LL) <= k) {
11            return 0;
12        }
13        sort(nums1.begin(), nums1.end(), greater<int>());
14        nums1.push_back(0);
15        for (int i = 1; i <= n; i++) {
16            long long cost = (long long)(nums1[i - 1] - nums1[i]) * i;
17            if (cost > k) {
18                long long q = k / i, r = k % i;
19                long long hi = nums1[i - 1] - q;
20                long long ans = hi * hi * (i - r) + (hi - 1) * (hi - 1) * r;
21                for (int j = i; j < n; j++) {
22                    ans += (long long)nums1[j] * nums1[j];
23                }
24                return ans;
25            }
26            k -= cost;
27        }
28        return 0;
29    }
30};