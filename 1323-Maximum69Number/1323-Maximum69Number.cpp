// Last updated: 8/16/2025, 10:33:53 PM
class Solution {
public:
    int maximum69Number (int num) {
        int result = 0,cpy = num;
        int count  = 0,first = -1;
        while(num > 0){
            if(num%10 == 6) first = count;
            num/=10;
            count++;
        }
        if(first == -1) return cpy;
        return cpy + 3*pow(10,first);
    }
};