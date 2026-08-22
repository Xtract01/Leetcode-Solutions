class Solution {
public:
    int sum(int n){
        int s = 0 ;
        int p = 1;
        while(n>0){
            int l = n%10;
            s+=l;
            p*=l;
            n/=10;
        }
        return s+p;
    }
    bool checkDivisibility(int n) {
        return n%sum(n) == 0;
    }
};