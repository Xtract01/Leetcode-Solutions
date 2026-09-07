class Solution {
public:
    int MOD = 1e9+7;
    int distinctSubseqII(string s) {
        vector<int> end(26,0);
        int total = 0;
        for(char ch: s){
            int idx = ch-'a';
            int oldTotal = total;
            int newSub = (oldTotal + 1 - end[idx] + MOD) %MOD;
            total = (total+newSub)%MOD;
            end[idx]=(end[idx]+newSub)%MOD;
        }
        return total;

    }
};