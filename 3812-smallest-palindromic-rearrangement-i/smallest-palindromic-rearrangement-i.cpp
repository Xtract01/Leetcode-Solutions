class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt(26,0);
        for (char c : s) {
            cnt[c - 'a']++;
        }
        char mid='\0';
        string res = "";
        for(int i=0;i<26;i++){
            if(cnt[i]%2!=0) mid = i+'a';
            for(int j=0 ; j<cnt[i]/2;j++){
                res+=i+'a';
            }
        }
        string rev =  res;
        reverse(rev.begin(),rev.end());
        if (mid != '\0')
            res += mid;

        res += rev;
        return res;
    }
};