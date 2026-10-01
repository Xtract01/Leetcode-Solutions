class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s.length()%2!=0) return false;
        for(int i=0;i<s.length();i++){
            if((s[i]=='(')||(s[i]=='{')||(s[i]=='[')) st.push(s[i]);
            else{
                if(st.size()==0)return false;
                else if(st.top()=='(' && s[i]!=')') return false;
                else if(st.top()=='[' && s[i]!=']') return false;
                else if(st.top()=='{' && s[i]!='}') return false;
                st.pop();
            }

        }
        if(st.size()==0) return true;
        return false;
    }
};