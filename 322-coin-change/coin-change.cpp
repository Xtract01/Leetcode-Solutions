class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>curr(amount+1,0),prev(amount+1,0);
        for(int target = 0 ; target<=amount ; target++){
            if(target%coins[0]==0) prev[target] = target/coins[0];
            else prev[target] = 1e9;
        }
        for(int ind=1 ; ind<n ; ind++){
            for(int target = 0 ; target<amount+1 ; target++){
                int take = INT_MAX;
                if(target>=coins[ind]) take = 1+curr[target-coins[ind]];
                int notTake = prev[target];
                curr[target] = min(take,notTake);
            }
            prev = curr;
        }
        int ans =prev[amount];
        return ans==1e9 ? -1 : ans;
    }
};