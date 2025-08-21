// Last updated: 8/21/2025, 4:27:28 PM
class Solution {
public: 
    void increasing(vector<int>& startTime, vector<int>& duration){
        int size = startTime.size();
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                if(startTime[i] > startTime[j] || (startTime[i] == startTime[j] && duration[i] > duration[j])){
                    swap(startTime[i],startTime[j]);
                    swap(duration[i],duration[j]);
                }
            }
        }
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        increasing(landStartTime,landDuration);
        increasing(waterStartTime,waterDuration);
        int res = INT_MAX;
        int m = landStartTime.size();
        int n = waterStartTime.size();
        for(int i=0;i<m;i++){
            int j = 0;
            int currStart = landStartTime[i] + landDuration[i];
            for(int j=0;j<n;j++){
                if(waterStartTime[j] >= currStart){
                    res = min(res,waterStartTime[j] + waterDuration[j]);
                }
                else{
                    res = min(res,currStart+waterDuration[j]);
                }
            }
        }
        for(int i=0;i<n;i++){
            int j = 0;
            int currStart = waterStartTime[i] + waterDuration[i];
            for(int j=0;j<m;j++){
                if(landStartTime[j] >= currStart){
                    res = min(res,landStartTime[j] + landDuration[j]);
                }
                else{
                    res = min(res,currStart+landDuration[j]);
                }
            }
        }
        return res;
    }
};