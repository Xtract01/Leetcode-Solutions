class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int i = 0 , j = 0 , maxLen = 0 , maxF = 0;
        unordered_map<char,int> mp;
        while(j<n){
            mp[s[j]]++;
            maxF = max(mp[s[j]] , maxF);
            if(j-i+1-maxF> k){
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(mp[s[i]]);
                i++;
            }
            maxLen = max(maxLen , j-i+1);
            j++;
        } 
        return maxLen;
    }
};