// Last updated: 11/22/2025, 8:07:26 PM
class Solution {
public:
    string convertToBinary(int n){
        string s = "";
        while(n > 0){
            if(n%2 == 0) s += '0';
            else{
                s += '1';
            }
            n /= 2;
        }
        return s;
    }
    int minimumFlips(int n) {
        string binary = convertToBinary(n);
        string rev = binary;
        int res = 0;
        reverse(binary.begin(),binary.end());
        for(int i=0;i<rev.size();i++){
            if(rev[i] != binary[i]) res++;
        }
        return res;
    }
};