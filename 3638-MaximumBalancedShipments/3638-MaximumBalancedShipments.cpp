// Last updated: 8/6/2025, 2:14:40 PM
class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int size = weight.size();
        int count = 0;
        int currMax = -1;
        for(int i=0;i<size;i++){
            if(weight[i] >= currMax){
                currMax = weight[i];
            }
            else{
                count++;
                currMax = -1;
            }
        }
        return count;
    }
};