class Solution {
public:
    string processStr(string s) {
        string res = "";
        for(char ch: s){
            if(ch=='*'){
                int n = res.size();
                if(n>0) res.erase(res.begin()+n-1);
            }
            else if(ch=='#'){
                res = res+res;
            }
            else if(ch=='%'){
                reverse(res.begin(),res.end());
            }
            else res+=ch;
        }
        return res;
    }
};