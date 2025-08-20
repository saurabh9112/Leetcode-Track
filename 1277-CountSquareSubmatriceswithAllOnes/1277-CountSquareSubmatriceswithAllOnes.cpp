// Last updated: 8/20/2025, 7:40:09 PM
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<pair<int,int>>> arr(m,vector<pair<int,int>>(n));
        for(int i=0;i<m;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 1){
                    count++;
                }
                else{
                    count = 0;
                }
                pair<int,int> p = {count,matrix[i][j]};
                arr[i][j] = p;
            }
        }
        for(int j=0;j<n;j++){
            int count = 0;
            for(int i=0;i<m;i++){
                if(matrix[i][j] == 1){
                    count++;
                }
                else{
                    count = 0;
                }
                pair<int,int> p = arr[i][j];
                arr[i][j].second = count;
            }
        }
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int maxH = arr[i][j].second;
                int minW = INT_MAX;
                for (int h = 1; h <= maxH; ++h) {
                    minW = min(minW, arr[i - h + 1][j].first);
                    if (minW >= h) ++result;
                    else break;
                }
            }
        }
        
        return result;

    }
};