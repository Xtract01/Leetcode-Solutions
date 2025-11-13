class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        int countOnes = 0;
        int op = 0;
        int i = 0;
        while(i<n){
            if(s[i] == '0'){
                op+=countOnes;
                while(i<n && s[i]=='0') i++;
            }
            else {
                countOnes++;
                i++;
            }
        }
        return op;
    }
};