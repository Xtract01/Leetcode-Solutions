class Solution {
public:
    
    bool solve(int idx ,string s,  unordered_set<string> st,vector<int> &dp){
        if(idx==s.length()) return true;
        if(st.find(s)!=st.end()) return true;
        if(dp[idx]!=-1) return dp[idx];
        for(int i=0 ;i<s.length();i++){
            string temp = s.substr(idx,i);
            if(st.find(temp)!=st.end() && solve(idx+i,s,st,dp)) return dp[idx]=1;
        }
        return dp[idx]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> dp(n,-1);
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        return solve(0,s,st,dp);
    }
};