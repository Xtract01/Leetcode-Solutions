class Solution {
public:
    void solve(int idx , string &digits , vector<string>&ans,vector<string>str , string temp){
        if(idx>= digits.length()){
            ans.push_back(temp);
            return ;
        }
        char ch = digits[idx];
        int i = ch - '0';
        string st = str[i-2];
        for(int i=0 ; i<st.length() ;i++){
            temp.push_back(st[i]);
            solve(idx+1,digits,ans,str,temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> str = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string temp;
        solve(0,digits,ans,str,temp);
        return ans;
    }
};