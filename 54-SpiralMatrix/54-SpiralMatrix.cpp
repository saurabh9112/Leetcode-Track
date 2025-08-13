// Last updated: 8/13/2025, 11:13:41 PM
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int topRow = 0;
        int leftCol = 0;
        int bottomRow = m-1;
        int rightCol = n-1;
        int total = m*n;
        int count = 0;
        while(count < total){
            for(int col=leftCol;col<=rightCol && count<total;col++){
                ans.push_back(matrix[topRow][col]);
                count++;
            }
            topRow++;
            for(int row=topRow;row<=bottomRow && count<total;row++){
                ans.push_back(matrix[row][rightCol]);
                count++;
            }
            rightCol--;
            for(int col=rightCol;col>=leftCol && count<total;col--){
                ans.push_back(matrix[bottomRow][col]);
                count++;
            }
            bottomRow--;
            for(int row=bottomRow;row>=topRow && count<total;row--){
                ans.push_back(matrix[row][leftCol]);
                count++;
            }
            leftCol++;
        }
        return ans;
    }
};