class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(N<0){
            x=1/x;
            N= -1*N;
        }
        if(N==0) return 1;
        double half = myPow(x,N/2);
        double result = half*half;

        if(N%2==1) return result * x;
        return result;
    }
};