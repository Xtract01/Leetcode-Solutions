class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> mp;
        int n = s.length();
        int ans = 0;
        int l =0 , r = 0;
        while(r<n){
            if(mp.find(s[r])!=mp.end()){
                int idx = mp[s[r]];
                l = max(l,idx+1);
            }
            mp[s[r]] = r;
            ans = max(ans,r-l+1);
            r++;
            
        }
        return ans;
    }
};