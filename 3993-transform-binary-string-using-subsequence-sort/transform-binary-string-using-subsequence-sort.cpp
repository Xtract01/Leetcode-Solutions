class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();
        vector<int> prefix(n+1,0);
        for(int i=0 ; i<n ; i++){
            prefix[i+1] = prefix[i];
            if(s[i]=='1') prefix[i+1]++;
        }
        int total = prefix[n];
        vector<bool> ans;
        for(auto it:strs){
            int one = 0;
            int q = 0;
            for(char c: it){
                if(c=='1') one++;
                else if(c=='?') q++;
            }
            if(one>total || q+one <total){ ans.push_back(false);continue;}
            int need = total - one;
            int remQ = q;
            int cur = 0;
            bool flag = true;
            for(int i=0 ; i<n; i++){
                if(it[i]=='1') cur++;
                else if(it[i]=='?'){
                    remQ--;
                    if(need>remQ){
                        cur++;
                        need--;
                    }
                }
                if(cur>prefix[i+1]) {
                    flag = false;
                    break;
                }
            }
            if(flag && need==0) ans.push_back(true);
            else ans.push_back(false);

        }
        return ans;
    }
};