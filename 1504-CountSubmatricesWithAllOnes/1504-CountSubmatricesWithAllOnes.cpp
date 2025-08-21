// Last updated: 8/21/2025, 2:17:05 PM
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> arr(m,vector<int> (n,0));
        for(int i=0;i<m;i++){
            int cnt = 0;
            for(int j=n-1;j>=0;j--){
                if(mat[i][j]){
                    cnt++;
                }
                else{
                    cnt = 0;
                }
                arr[i][j] = cnt;
            }
        }
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int x = INT_MAX;
                for(int k=i;k<m;k++){
                    x = min(x,arr[k][j]);
                    ans += x;
                }
            }
        }
        return ans;
    }
};