// Last updated: 8/18/2025, 1:38:45 PM
class Solution {
public:
    vector<double> getAllValidOperations(double a,double b){
        vector<double> validOperations;
        validOperations.push_back(a+b);
        validOperations.push_back(a-b);
        validOperations.push_back(a*b);
        validOperations.push_back(b-a);
        if(abs(b) > FLT_EPSILON){
            validOperations.push_back(a/b);
        }
        if(abs(a) > FLT_EPSILON){
            validOperations.push_back(b/a);
        }
        return validOperations;
    }
    bool isPossible(vector<double> &arr){
        int n = (int)arr.size();
        if(n == 1){
            return abs(24.0 - arr[0]) <= FLT_EPSILON;
        }
        for(int fn=0;fn<n;fn++){
            for(int sn=0;sn<n;sn++){
                if(fn != sn){
                    vector<double> validOperations = getAllValidOperations(arr[fn],arr[sn]);
                    vector<double> nextArr;
                    for(auto validOperation:validOperations){
                        nextArr.clear();
                        nextArr.push_back(validOperation);
                        for(int i=0;i<n;i++){
                            if(i != fn && i != sn){
                                nextArr.push_back(arr[i]);
                            }
                        }
                        if(isPossible(nextArr)){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> arr(cards.begin(),cards.end());
        return isPossible(arr);
    }
};