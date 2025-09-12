// Last updated: 9/12/2025, 12:01:12 PM
class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
            return true;
        }
        return false;
    }
    bool doesAliceWin(string s) {
        int vowelCnt = 0;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                vowelCnt++;
            }
        }
        if(!vowelCnt) return false;
        return true;
    }
};