class Solution {
public:
    bool isValid(string s){
        int balance = 0;

        for(char c : s){
            if(c == '(')
                balance++;
            else
                balance--;

            if(balance < 0)return false;
        }
        return balance == 0;
    }
    void solve(int idx, int n, string temp, vector<string> &res){
        if(idx>=2*n){
            if(isValid(temp)) res.push_back(temp);
            return;
        }
        temp.push_back('(');
        solve(idx+1,n,temp,res);
        temp.pop_back();
        temp.push_back(')');
        solve(idx+1,n,temp,res);
        temp.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string temp = "";
        vector<string> res;
        solve(0,n,temp,res);
        return res;
    }
};