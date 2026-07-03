class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(2,0)));
        for(int ind=n-1 ; ind>=0 ; ind--){
            for(int k=0 ; k<=2 ; k++){
                for(int buy = 0; buy<2 ; buy++){
                    int profit = -1e9;
                    if(buy){
                        profit = max(-prices[ind]+dp[ind+1][k][0],dp[ind+1][k][1]);
                    }
                    else {
                        if (k > 0) profit = max(prices[ind] + dp[ind+1][k-1][1], dp[ind+1][k][0]);
                        else profit = dp[ind+1][k][0];
                    }
                    dp[ind][k][buy] = profit;
                }
            }
        }
        return dp[0][2][1];
    }
};