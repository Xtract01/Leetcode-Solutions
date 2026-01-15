class Solution {
public:
    int solve(int i,int n , int buy ,vector<int>& prices ,vector<vector<int>>&dp){
        if(i==n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit = 0;
        if(buy){
            profit = max(-1*prices[i]+solve(i+1,n,0,prices,dp),solve(i+1,n,1,prices,dp));
        }
        else {
           profit = max(prices[i]+solve(i+1,n,1,prices,dp),solve(i+1,n,0,prices,dp)); 
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,n,1,prices,dp);
    }
};