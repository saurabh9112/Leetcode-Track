// Last updated: 9/11/2025, 12:32:40 PM
class Solution {
public:
    bool checkVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I'|| ch == 'O' || ch == 'U'){
            return true;
        }
        return false;
    }
    string sortVowels(string s) {
        vector<int> vowels;
        for(int i=0;i<s.size();i++){
            if(checkVowel(s[i])){
                vowels.push_back(s[i]);
            }
        }
        sort(vowels.begin(),vowels.end());
        string res = "";
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            if(checkVowel(s[i])){
                res += vowels[cnt++];
            }
            else{
                res += s[i];
            }
        }
        return res;
    }
};