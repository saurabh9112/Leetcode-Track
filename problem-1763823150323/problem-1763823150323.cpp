// Last updated: 11/22/2025, 8:22:30 PM
class Solution {
public:
    string convertToStr(int num){
        string s = "";
        while(num > 0){
            int digit = num%10;
            char ch = '0' + digit;
            s += ch;
            num /= 10;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i=num1;i<=num2;i++){
            string n1 = convertToStr(i);
            for(int i=1;i<n1.size()-1;i++){
                if(n1[i] > n1[i-1] && n1[i] > n1[i+1]) ans++;
                if(n1[i] < n1[i-1] && n1[i] < n1[i+1]) ans++;
            }
        }

        return ans;
    }
};