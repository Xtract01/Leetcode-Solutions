class Solution {
public:
    int minAddToMakeValid(string s) {
        int res = 0;
        int cntr = 0;
        for (char ch : s) {
            if (ch == ')' && cntr == 0) {
                res++;
            }
            else if (ch == ')') {
                cntr--;
            }
            else {
                cntr++;
            }
        }

        return res + cntr;
    }
};