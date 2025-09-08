class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> mp;
        unordered_map<char,int> mp1;
        for(int i=0 ;i<s.length();i++){
            mp[s[i]]++;
            mp1[t[i]]++;
        }
        for(auto &el : mp){
            if(mp1[el.first]!=el.second) return false;
        }
        return true;
    }
};