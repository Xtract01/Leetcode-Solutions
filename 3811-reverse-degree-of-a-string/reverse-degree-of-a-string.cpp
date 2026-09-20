class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int res = 0;
        for(int i=0 ; i<n ; i++){
            int revNo = 26-(s[i]-'a');
            res = res + (revNo * (i+1));
        }
        return res;
    }
};