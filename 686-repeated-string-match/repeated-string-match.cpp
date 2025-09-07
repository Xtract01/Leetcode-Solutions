class Solution {
public:
    void computeLPS(const string &pat , vector<int> &LPS , int m){
        int len = 0;
        LPS[0] = 0;
        int i = 1;
        while (i < m){
            if(pat[i] == pat[len]){
                len++;
                LPS[i] = len;
                i++;
            } else {
                if(len != 0){
                    len = LPS[len-1];
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }

    bool KMP_MATCH(const string &txt, const string &pat) {
        int n = txt.length();
        int m = pat.length();
        vector<int> LPS(m, 0);
        computeLPS(pat, LPS, m);

        int i = 0, j = 0;
        while(i < n){
            if(txt[i] == pat[j]){
                i++; j++;
            }
            if(j == m){
                return true;  // found a match
            } else if(i < n && txt[i] != pat[j]){
                if(j != 0) j = LPS[j-1];
                else i++;
            }
        }
        return false;
    }

    int repeatedStringMatch(string a, string b) {
        if(a == b) return 1;
        int repeat = 1;
        string temp = a;

        while(temp.length() < b.length()){
            temp += a;
            repeat++;
        }

        if(KMP_MATCH(temp, b)) return repeat;
        temp += a;
        if(KMP_MATCH(temp, b)) return repeat + 1;

        return -1;
    }
};
