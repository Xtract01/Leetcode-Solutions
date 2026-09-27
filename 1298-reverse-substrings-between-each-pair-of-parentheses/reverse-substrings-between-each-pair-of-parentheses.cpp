class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        st.push(0);
        int n = s.length();
        string res = "";
        for(int i=0 ; i<n ; i++){
            if(s[i]=='('){
                st.push(res.length());
            }
            else if(s[i]==')'){
                int l = st.top();
                st.pop();
                reverse(res.begin()+l,res.end());
            }
            else res+=s[i];
        }
        return res;
    }
};