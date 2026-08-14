class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> mp;
        int i =0 , r = 0;
        int n = s.length();
        int res = 0;
        while(r<n){
            mp[s[r]]++;
            while(i<n && mp[s[r]]>2){
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
            res = max(res,r-i+1);
            r++;
        }
        return res;
    }
};