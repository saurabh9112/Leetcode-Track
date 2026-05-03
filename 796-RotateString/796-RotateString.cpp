// Last updated: 5/3/2026, 3:40:34 PM
1class Solution {
2public:
3    bool rotateString(string s, string goal) {
4        if (s.length() != goal.length()) return false;
5        int length = s.length();
6
7        // Try all possible rotations of the string
8        for (int rotationCount = 0; rotationCount < length; ++rotationCount) {
9            // Perform one rotation
10            rotate(s.begin(), s.begin() + 1, s.end());
11            if (s == goal) return true;
12        }
13        return false;
14    }
15};