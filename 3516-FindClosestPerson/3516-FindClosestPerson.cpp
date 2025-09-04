// Last updated: 9/4/2025, 1:15:24 PM
class Solution {
public:
    int findClosest(int x, int y, int z) {
        int num1 = abs(z-x);
        int num2 = abs(z-y);
        if(num1 < num2){
            return 1;
        }
        else if(num1 > num2){
            return 2;
        }
        return 0;
    }
};