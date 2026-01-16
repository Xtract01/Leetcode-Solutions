class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(
        n+1,
        vector<vector<int>>(3, vector<int>(2, 0))
    );
    for(int i= n-1 ; i>=0 ; i--){
        for(int k=1 ;k<=2;k++){
            for(int buy=0 ; buy<=1; buy++){
                if(buy){
                    dp[i][k][buy] = max(-prices[i]+dp[i+1][k][0],dp[i+1][k][1]);
                }
                else dp[i][k][buy] = max(prices[i]+dp[i+1][k-1][1],dp[i+1][k][0]);
            }
        }
    }
    return dp[0][2][1];
    }

};