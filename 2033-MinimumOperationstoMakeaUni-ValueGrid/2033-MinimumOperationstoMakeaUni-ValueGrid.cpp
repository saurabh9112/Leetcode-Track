// Last updated: 5/3/2026, 6:37:23 PM
1class Solution {
2public:
3    int minOperations(vector<vector<int>>& grid, int x) {
4        vector<int> numsArray;
5        int result = 0;
6
7        // Flatten the grid into numsArray
8        for (int row = 0; row < grid.size(); row++) {
9            for (int col = 0; col < grid[0].size(); col++) {
10                numsArray.push_back(grid[row][col]);
11            }
12        }
13
14        int length = numsArray.size();
15
16        // Partially sorts the array so that the median element is placed at the
17        // middle index
18        nth_element(numsArray.begin(), numsArray.begin() + length / 2,
19                    numsArray.end());
20
21        // Store the median element as the final common value to make all
22        // elements equal to
23        int finalCommonNumber = numsArray[length / 2];
24
25        for (int number : numsArray) {
26            // If the remainder when divided by x is different for any number,
27            // return -1
28            if (number % x != finalCommonNumber % x) return -1;
29            // Add the number of operations required to make the current number
30            // equal to finalCommonNumber
31            result += abs(finalCommonNumber - number) / x;
32        }
33
34        return result;
35    }
36};