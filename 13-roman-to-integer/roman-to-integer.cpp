class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        int n = s.length();
        int res = 0;
        mp.insert({'I',1});
        mp.insert({'V',5});
        mp.insert({'X',10});
        mp.insert({'L',50});
        mp.insert({'C',100});
        mp.insert({'D',500});
        mp.insert({'M',1000});
        for(int i = 0;i<n;i++){
            if(i<n-1 && mp[s[i]]<mp[s[i+1]]) res-=mp[s[i]];
            else res+=mp[s[i]];
        }
        return res;
    }
};