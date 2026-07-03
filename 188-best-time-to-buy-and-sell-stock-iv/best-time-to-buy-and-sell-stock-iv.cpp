class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+1,vector<int>(2,0)));
        for(int ind=n-1 ; ind>=0 ; ind--){
            for(int cap=0 ; cap<=k ; cap++){
                for(int buy = 0; buy<2 ; buy++){
                    int profit = -1e9;
                    if(buy){
                        profit = max(-prices[ind]+dp[ind+1][cap][0],dp[ind+1][cap][1]);
                    }
                    else {
                        if (cap > 0) profit = max(prices[ind] + dp[ind+1][cap-1][1], dp[ind+1][cap][0]);
                        else profit = dp[ind+1][cap][0];
                    }
                    dp[ind][cap][buy] = profit;
                }
            }
        }
        return dp[0][k][1];
    }
};
