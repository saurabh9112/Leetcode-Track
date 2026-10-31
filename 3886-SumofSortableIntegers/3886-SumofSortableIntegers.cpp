// Last updated: 10/31/2026, 3:37:53 PM
1class Solution {
2public:
3    int sortableIntegers(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> fac;
6
7        for (int x = 1; x * x <= n; ++x) {
8            if (n % x == 0) {
9                fac.push_back(x);
10                if (n / x != x) {
11                    fac.push_back(n / x);
12                }
13            }
14        }
15
16        vector<int> target = nums;
17        ranges::sort(target);
18
19        auto kmp = [](const vector<int>& nums1, const vector<int>& nums2) {
20            int n = nums1.size(), m = nums2.size();
21            vector<int> pi(m, 0);
22            int j = 0;
23
24            for (int i = 1; i < m; ++i) {
25                while (j > 0 && nums2[i] != nums2[j]) {
26                    j = pi[j - 1];
27                }
28                if (nums2[i] == nums2[j]) {
29                    ++j;
30                }
31                pi[i] = j;
32            }
33
34            j = 0;
35            for (int i = 0; i < n; ++i) {
36                while (j > 0 && nums1[i] != nums2[j]) {
37                    j = pi[j - 1];
38                }
39                if (nums1[i] == nums2[j]) {
40                    ++j;
41                }
42                if (j == m) {
43                    return true;
44                }
45            }
46            return false;
47        };
48
49        auto check = [&](const vector<int>& nums1, const vector<int>& nums2) {
50            // Check whether cyclic rotations of nums1 can produce nums2
51            vector<int> doubled = nums1;
52            doubled.insert(doubled.end(), nums1.begin(), nums1.end());
53            return kmp(doubled, nums2);
54        };
55
56        int ans = 0;
57
58        for (int d : fac) {
59            bool allGood = true;
60            for (int left = 0; left < n; left += d) {
61                int right = left + d - 1;
62                vector<int> sub1(nums.begin() + left, nums.begin() + right + 1);
63                vector<int> sub2(target.begin() + left,
64                                 target.begin() + right + 1);
65
66                if (!check(sub1, sub2)) {
67                    allGood = false;
68                    break;
69                }
70            }
71            if (allGood) {
72                ans += d;
73            }
74        }
75
76        return ans;
77    }
78};