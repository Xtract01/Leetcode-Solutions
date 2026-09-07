class Solution {
public:
    void solve(int idx, string temp ,string digits,unordered_map<int,string> &mp,vector<string> &res){
        if(idx==digits.size()){
            res.push_back(temp);
            return;
        }
        for(char c:mp[digits[idx]-'0']){
            temp.push_back(c);
            solve(idx+1,temp,digits,mp,res);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        vector<string>res;
        string temp ="";
        solve(0,temp,digits,mp,res);
        return res;
    }
};