// Last updated: 1/2/2026, 9:21:09 PM
1class Solution {
2public:
3    int repeatedNTimes(vector<int>& A) {
4        for (int k = 1; k <= 3; ++k)
5            for (int i = 0; i < A.size() - k; ++i)
6                if (A[i] == A[i+k])
7                    return A[i];
8
9        return 0;            
10    }
11};