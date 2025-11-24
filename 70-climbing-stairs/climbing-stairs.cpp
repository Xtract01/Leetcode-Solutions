class Solution {
public:
    int dp[46];
    int helper(int n , int step){
        if(step == n) return 1;
        if(step>n) return 0;
        if (dp[step]!=-1) return dp[step];
        int oneStep = helper(n,step+1);
        int twoStep = helper(n, step+2);
        return dp[step]=oneStep + twoStep;
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof dp);
        return helper(n,0);
    }
};