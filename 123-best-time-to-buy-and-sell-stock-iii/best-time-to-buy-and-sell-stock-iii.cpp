class Solution {
public:
    int solve(int i , int n , int k ,int buy ,vector<int>& prices,vector<vector<vector<int>>>&dp){
        if(i==n || k==0) return 0;
        if(dp[i][k][buy]!=-1) return dp[i][k][buy];
        if(buy){
            return dp[i][k][buy] = max(-prices[i]+solve(i+1,n,k,0,prices,dp),solve(i+1,n,k,1,prices,dp));
        }
        else {
            return  dp[i][k][buy] = max(prices[i]+solve(i+1,n,k-1,1,prices,dp),solve(i+1,n,k,0,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(
        n,
        vector<vector<int>>(3, vector<int>(2, -1))
    );

    return solve(0, n, 2, 1, prices, dp);
}
};