class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();
        bool conOnes = false;
        int i = 0;
        while(i<n){
            if(s[i]=='1' && conOnes==true) return false;
            if(s[i]=='1'){
                conOnes = true;
                while(i<n && s[i]=='1') i++;
            }
            i++;
        }
        return true;
    }
};