// Last updated: 9/25/2025, 11:11:36 AM
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n,0),curr(n,0);
        front = triangle[n-1];
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                curr[j] = triangle[i][j]+min(front[j+1],front[j]);
            }
            front = curr;
        }
        return front[0];
    }
};