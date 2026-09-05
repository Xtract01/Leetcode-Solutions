class Solution {
public:
    bool isValid(string s){
        int n = s.length();
        stack<char> st;
        for(char c: s){
            if(c=='(') st.push(c);
            else {
                if(st.empty()) return false;
                st.pop();
            }
        }
        return st.empty();
    }
    void helper(int idx , int n , string temp , vector<string> &res){
        if(idx==2*n){
            if(isValid(temp)) res.push_back(temp);
            return;
        }
        temp.push_back('(');
        helper(idx+1,n,temp,res);
        temp.pop_back();
        temp.push_back(')');
        helper(idx+1,n,temp,res);
        temp.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp = "";
        helper(0,n,temp,res);
        return res;
    }
};