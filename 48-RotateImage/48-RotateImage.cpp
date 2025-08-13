// Last updated: 8/13/2025, 11:14:21 PM
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //for rotating a matrix by 90 degree
        //1st -> convert the matrix into its transpose
        //2nd -> reverse every row of the transpose matrix
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};