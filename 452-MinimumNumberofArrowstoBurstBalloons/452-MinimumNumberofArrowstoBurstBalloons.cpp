// Last updated: 8/19/2025, 3:38:16 PM
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int size = points.size();
        int count = 1;
        sort(points.begin(),points.end());
        int intStart = points[0][0];
        int intEnd = points[0][1];
        for(int i=0;i<size;i++){
            if(points[i][0] >= intStart && points[i][0] <= intEnd){
                intStart = points[i][0];
                if(points[i][1] < intEnd) intEnd = points[i][1];
                continue;
            }
            count++;
            intStart = points[i][0];
            intEnd = points[i][1];
        }
        return count;
    }
};