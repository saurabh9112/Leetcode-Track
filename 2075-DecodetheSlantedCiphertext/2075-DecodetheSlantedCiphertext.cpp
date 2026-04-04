// Last updated: 4/4/2026, 5:02:49 PM
1class Solution {
2public:
3    string decodeCiphertext(string encodedText, int rows) {
4        int n = encodedText.size();
5        if (rows == 1)
6            return encodedText;
7
8        int cols = n / rows;
9        string res;
10        res.reserve(n);
11
12        for (int c = 0; c < cols; ++c) {
13            int r = 0, j = c;
14            while (r < rows && j < cols) {
15                res += encodedText[r * cols + j];
16                ++r;
17                ++j;
18            }
19        }
20
21        while (!res.empty() && res.back() == ' ') {
22            res.pop_back();
23        }
24
25        return res;
26    }
27};