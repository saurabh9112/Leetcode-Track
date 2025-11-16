// Last updated: 11/16/2025, 8:31:02 AM
class Solution {
public:
    int minLengthAfterRemovals(string s) {
        stack<char> st;
        int size = s.size();
        for(int i=0;i<size;i++){
            char ch = s[i];
            if(st.empty()){
                st.push(ch);
            }
            else{
                char top = st.top();
                if(ch == 'a' && top == 'b' || ch == 'b' && top == 'a'){
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
        }

        return st.size();
    }
};