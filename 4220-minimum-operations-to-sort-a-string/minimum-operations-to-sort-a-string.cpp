class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        string t = s;
        sort(t.begin(),t.end());
        if(s==t) return 0;
        if(s.size()==2 && s[0]>s[1]) return -1;
        if(s[0]==t[0]||s[n-1]==t[n-1]) return 1;
        string s1 = s;
        sort(s1.begin(),s1.begin()+n-1);
        sort(s1.begin()+1,s1.end());
        string s2 = s;
        sort(s2.begin()+1,s2.end());
        sort(s2.begin(),s2.begin()+n-1);
        if(s1==t || s2==t) return 2;
        return 3;
    }
};