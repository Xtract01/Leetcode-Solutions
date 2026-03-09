class Solution {
public:
    int M = 1e9+7;
    int t[201][201][2];
    int solve(int oneLeft ,int zerosLeft ,bool lastWasOne, int limit){
        if(oneLeft ==0 && zerosLeft == 0){
            return 1;
        }
        if(t[oneLeft][zerosLeft][lastWasOne]!=-1) return t[oneLeft][zerosLeft][lastWasOne];
        int result = 0;
        if(lastWasOne){
            for(int len = 1 ; len<=min(zerosLeft,limit);len++){
                result = (result + solve(oneLeft,zerosLeft - len , false ,limit))%M;
            }
        }
        else {
            for(int len = 1 ; len<=min(oneLeft,limit);len++){
                result = (result + solve(oneLeft - len,zerosLeft, true ,limit))%M;
            }
        }
        return t[oneLeft][zerosLeft][lastWasOne] = result;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t,-1,sizeof(t));
        int startWithOne = solve(one,zero,false,limit);
        int startWithZero = solve(one,zero,true,limit);
        return (startWithOne + startWithZero) % M;
    }
};