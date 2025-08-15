// Last updated: 8/15/2025, 10:15:43 PM
class Solution {
public:
    vector<int> bitsVector(int num){
        vector<int> result(32,0);
        int count = 0;
        while(num > 0){
            if(num%2 == 0){
                result[count++] = 0;
            }
            else{
                result[count++] = 1;;
            }
            num/=2;
        }
        // reverse(result.begin(),result.end());
        return result;
    }
    int minFlips(int a, int b, int c) {
        vector<int> bitsA(32,0),bitsB(32,0),bitsOR(32,0),bitsC(32,0);
        bitsA = bitsVector(a);
        bitsB = bitsVector(b);
        bitsOR = bitsVector(c);
        bitsC = bitsVector(a | b);
        int size = bitsOR.size();
        int cnt = 0;
        for(int i=0;i<32;i++){
            if(bitsC[i] != bitsOR[i]){
                if(bitsC[i] == 1 && bitsOR[i] == 0){
                    cnt += bitsA[i];
                    cnt += bitsB[i];
                }
                else{
                    cnt += 1;
                }
            }
        }
        return cnt;
    }
};