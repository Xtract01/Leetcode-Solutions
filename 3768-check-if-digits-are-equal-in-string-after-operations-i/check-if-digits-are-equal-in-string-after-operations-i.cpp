class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length();
        while(n>2){
            for(int i = 0 ;i<n ; i++){
                s[i] = (s[i] + s[i+1]) % 10;
            }
            n--;
        }
        if(s[0]==s[1]) return true;
        else return false;
    }
};