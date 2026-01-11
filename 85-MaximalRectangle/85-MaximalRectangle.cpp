// Last updated: 1/11/2026, 10:53:25 AM
1class Solution {
2public:
3    vector<int> nextSmallerElement(vector<int> arr, int n) {
4        stack<int> s;
5        s.push(-1);
6        vector<int> ans(n);
7        for(int i=n-1; i>=0 ; i--) {
8            int curr = arr[i];
9            while(s.top() != -1 && arr[s.top()] >= curr)
10            {
11                s.pop();
12            }
13            ans[i] = s.top();
14            s.push(i);
15        }
16        return ans;
17    }
18    vector<int> prevSmallerElement(vector<int> arr, int n) {
19        stack<int> s;
20        s.push(-1);
21        vector<int> ans(n);
22        for(int i=0; i<n; i++) {
23            int curr = arr[i];
24            while(s.top() != -1 && arr[s.top()] >= curr)
25            {
26                s.pop();
27            }
28            ans[i] = s.top();
29            s.push(i);
30        }
31        return ans; 
32    }
33    int largestRectangleArea(vector<int>& heights) {
34        int n = heights.size();
35        vector<int> next(n);
36        next = nextSmallerElement(heights, n);
37        vector<int> prev(n);
38        prev = prevSmallerElement(heights, n);
39        int area = INT_MIN;
40        for(int i=0; i<n; i++) {
41            int l = heights[i];
42            if(next[i] == -1) {
43                next[i] = n;
44            }
45            int b = next[i] - prev[i] - 1;
46            int newArea = l*b;
47            area = max(area, newArea);
48        }
49        return area;
50    }    
51    int maximalRectangle(vector<vector<char>>& matrix) {
52        int maxi = INT_MIN;
53        int row = matrix.size();
54        int col = matrix[0].size();
55        vector<int> histogram(col,0);
56        for(int i=0;i<row;i++){
57            for(int j=0;j<col;j++){
58                if(matrix[i][j] == '1'){
59                    histogram[j]++;
60                }
61                else{
62                    histogram[j] = 0;
63                }
64            }
65            maxi = max(maxi,largestRectangleArea(histogram));
66        }
67        return maxi;
68    }
69};